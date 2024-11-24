#include <gz/msgs/details/contacts.pb.h>
#include <gz/msgs/details/world_reset.pb.h>
#include <gz/msgs/entity_factory.pb.h>
#include <gz/msgs/pose.pb.h>
#include <gz/msgs/world_control.pb.h>
#include <unistd.h>

#include <csignal>
#include <cstdint>
#include <fstream>
#include <gz/msgs/Utility.hh>
#include <gz/sim/Server.hh>
#include <gz/transport/Node.hh>
#include <iostream>
#include <ostream>
#include <rclcpp/utilities.hpp>
#include <string>

#include "nandhi_msg_types/srv/get_observations.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;
// timeout used for services
constexpr unsigned int timeout = 5000;

// Model name and world name
std::string model_name = "nandhi";  // Replace with your model's name
std::string world_name = "indoor";  // Replace with your world name if needed

bool is_crashed{false};

// Create a transport node.
gz::transport::Node t_node;

int64_t gz_multi_step{500};

void GetModelString(std::string &buffer, std::string model_path) {
    std::ifstream model_file(model_path);
    model_file.seekg(0, std::ios::end);
    buffer.resize(model_file.tellg());
    model_file.seekg(0);
    model_file.read(buffer.data(), buffer.size());
}

template <class Request, class Response>
bool SendRequest(std::string service_name, Request req, Response res) {
    bool result;
    bool executed = t_node.Request(service_name, req, timeout, res, result);
    if (executed) {
        if (!result) {
            std::cerr << "[createEntityFromStr] Service call failed"
                      << std::endl;
        }
    } else {
        std::cerr << "[createEntityFromStr] Service call timed out"
                  << std::endl;
    }

    return executed && result;
}

bool createEntityFromStr(const std::string &modelStr,
                         const std::string &world_name) {
    gz::msgs::EntityFactory req;
    gz::msgs::Boolean res;

    req.set_sdf(modelStr);

    bool executed = SendRequest<gz::msgs::EntityFactory, gz::msgs::Boolean>(
        "/world/" + world_name + "/create", req, res);

    return executed;
}

bool ResetModel() {
    // Service client to call the set_pose service
    gz::msgs::Boolean res;
    gz::msgs::Pose req;

    // Set the model name
    req.set_name(model_name);

    // Set the desired position (x, y, z) and orientation (roll, pitch, yaw)
    req.mutable_position()->set_x(-7);  // Replace with desired x
    req.mutable_position()->set_y(0.0);  // Replace with desired y
    req.mutable_position()->set_z(0.5);  // Replace with desired z

    // Request the service to set the model pose
    std::string service_name = "/world/" + world_name + "/set_pose";
    bool success =
        SendRequest<gz::msgs::Pose, gz::msgs::Boolean>(service_name, req, res);

    if (success) {
        std::cout << "Reset done successfully." << std::endl;
    } else {
        std::cerr << "Failed to reset." << std::endl;
    }

    return success;
}

bool StepServer() {
    bool result{false};
    std::string service_name{"/world/"+world_name+"/control"};
    gz::msgs::WorldControl req;
    gz::msgs::Boolean res;

    req.set_pause(true);                // Keep paused after the request
    req.set_step(true);                 // Take a single step
    req.set_multi_step(gz_multi_step);  // Run the simulation for 0.5s

    bool executed = SendRequest<gz::msgs::WorldControl, gz::msgs::Boolean>(
        service_name, req, res);
    return executed;
}

void ONContact(const gz::msgs::Contacts &contacts) {
    if (!is_crashed) {
        std::cout << "Crash detected " << contacts.contact_size() << std::endl;
        is_crashed = true;
    }
}

void ProcessRequest(
    const std::shared_ptr<nandhi_msg_types::srv::GetObservations::Request>
        request,
    std::shared_ptr<nandhi_msg_types::srv::GetObservations::Response>
        response) {
    if (request->reset) {
        bool result = ResetModel();
        if (!result) {
            std::cerr << "Failed to reset the model" << std::endl;

        } else {
            is_crashed = false;
            std::cout << "Module reset done" << std::endl;
        }
    }
    if (request->step) {
        gz_multi_step = request->multi_step;
        bool ret = StepServer();
        if (!ret) {
            std::cerr << "RL: Step failed" << std::endl;
        }
    }

    response->crash = is_crashed;
}

int main(int argc, const char *const *argv) {
    // Initialize the ros environment
    rclcpp::init(argc, argv);

    // TODO : Get the path from arguments

    //! [create Nandhi entity]
    std::string modelStr;
    GetModelString(modelStr,
                   "install/nandhi_description/share/"
                   "nandhi_description/models/"+model_name+"/model.sdf");

    createEntityFromStr(modelStr, world_name);
    //! [create Nandhi entity]

    //! [subscribe for contact sensor]
    std::string topic{
        "/world/"+world_name+"/model/"+model_name+"/link/chassis/sensor/sensor_contact/"
        "contact"};
    bool ret = t_node.Subscribe(topic, ONContact);
    if (!ret) {
        std::cerr << "Failed to subscribe to contact sensor" << std::endl;
    }
    //! [subscribe for contact sensor]

    //! [Create ros2 node]
    std::shared_ptr<rclcpp::Node> ros_node =
        rclcpp::Node::make_shared("ros_gz_rl");
    //! [Create ros2 node]

    //! [create ros2 service client]
    rclcpp::Service<nandhi_msg_types::srv::GetObservations>::SharedPtr service =
        ros_node->create_service<nandhi_msg_types::srv::GetObservations>(
            "ros_gz_rl", &ProcessRequest);
    //! [create ros2 service client]

    ResetModel();
    // Get the command from the ros
    rclcpp::spin(ros_node);

    // winding down ros environment
    rclcpp::shutdown();

    // wait for GZ termination
    gz::transport::waitForShutdown();

    std::cout << "Program terminated" << std::endl;

    return 0;
}
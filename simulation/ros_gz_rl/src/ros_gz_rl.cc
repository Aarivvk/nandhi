#include <gz/msgs/entity_factory.pb.h>
#include <gz/msgs/world_control.pb.h>
#include <unistd.h>

#include <csignal>
#include <fstream>
#include <gz/msgs/Utility.hh>
#include <gz/sim/Server.hh>
#include <gz/transport/Node.hh>
#include <iostream>
#include <ostream>
#include <string>

#include "nandhi_msg_types/srv/get_observations.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

bool is_terminated{false};

// Create a transport node.
gz::transport::Node t_node;

// timeout used for services
constexpr unsigned int timeout = 5000;

void GetModelString(std::string &buffer, std::string model_path) {
    std::ifstream model_file(model_path);
    model_file.seekg(0, std::ios::end);
    buffer.resize(model_file.tellg());
    model_file.seekg(0);
    model_file.read(buffer.data(), buffer.size());
}

// Signal handler function
void signalHandler(int signum) {
    std::cout << "\nInterrupt signal (" << signum << ") received.\n";

    // Cleanup and close up stuff here
    // Terminate program
    is_terminated = true;
}

template <class Request, class Response>
bool SendRequest(std::string service_name, Request req, Response res) {
    bool result;
    bool executed = t_node.Request(service_name, req, timeout, res, result);
    if (executed) {
        if (result)
            std::cout << "Request executed : [" << res.data() << "]"
                      << std::endl;
        else {
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

bool StepServer() {
    std::string service_name{"/world/indoor/control"};
    gz::msgs::WorldControl req;
    gz::msgs::Boolean res;

    req.set_pause(true);      // Keep paused after the request
    req.set_step(true);       // Take a single step
    req.set_multi_step(500);  // Run the simulation for 0.5s

    bool executed = SendRequest<gz::msgs::WorldControl, gz::msgs::Boolean>(
        service_name, req, res);
    return executed;
}

// TODO: Add function defintion
void ProcessRequest(
    const std::shared_ptr<nandhi_msg_types::srv::GetObservations::Request>
        request,
    std::shared_ptr<nandhi_msg_types::srv::GetObservations::Response>
        response) {}

int main(int argc, const char *const *argv) {
    // Register signal handler for SIGINT
    signal(SIGINT, signalHandler);

    //! [create Nandhi entity]
    std::string modelStr;
    GetModelString(modelStr,
                   "install/nandhi_description/share/"
                   "nandhi_description/models/nandhi/model.sdf");

    createEntityFromStr(modelStr, "indoor");

    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> ros_node =
        rclcpp::Node::make_shared("ros_gz_rl");
    rclcpp::Service<nandhi_msg_types::srv::GetObservations>::SharedPtr service =
        ros_node->create_service<nandhi_msg_types::srv::GetObservations>(
            "ros_gz_rl", &ProcessRequest);

    while (!is_terminated) {
        bool ret = StepServer();
        if (!ret) {
            std::cerr << "RL: Step failed" << std::endl;
        }
        std::cerr << "RL: Spin" << std::endl;
        // rclcpp::spin(ros_node);
        /* Until the ProcessRequest is implemented sleep for 1s, once it is
         implemented the cycle can be adjusted or let it driven by the client.*/
        std::this_thread::sleep_for(1000ms);
    }

    rclcpp::shutdown();

    std::cout << "Program terminated" << std::endl;

    return 0;
}

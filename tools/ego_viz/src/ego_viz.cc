#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "nandhi_msg_types/msg/ego_state.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class EgoViz : public rclcpp::Node
{
  public:
    EgoViz()
    : Node("ego_state_viz"), count_(0)
    {
      publisher_ego_ = this->create_publisher<visualization_msgs::msg::Marker>( "ego_state_marker", 10 );
      sub_ego_ = this->create_subscription<nandhi_msg_types::msg::EgoState>("ego_state", 10, std::bind(&EgoViz::on_topic_ego_state, this, std::placeholders::_1));
      timer_ = this->create_wall_timer(100ms, std::bind(&EgoViz::timer_callback, this));
    }

  private:
    void timer_callback();  
    void on_topic_ego_state(const nandhi_msg_types::msg::EgoState::ConstSharedPtr msg);

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_ego_;
    rclcpp::Subscription<nandhi_msg_types::msg::EgoState>::SharedPtr sub_ego_;
    nandhi_msg_types::msg::EgoState ego_state;
    size_t count_;
};

void EgoViz::timer_callback()
{
    visualization_msgs::msg::Marker ego = visualization_msgs::msg::Marker();

    ego.header.frame_id = "nandhi_frame";
    ego.header.stamp = rclcpp::Time();
    ego.id = 0;
    ego.type = visualization_msgs::msg::Marker::CUBE;
    ego.action = visualization_msgs::msg::Marker::ADD;
    ego.pose.position.x = ego_state.pose.x;
    ego.pose.position.y = ego_state.pose.y;
    ego.pose.position.z = ego_state.pose.z;
    ego.pose.orientation.x = ego_state.orientation.x;
    ego.pose.orientation.y = ego_state.orientation.y;
    ego.pose.orientation.z = ego_state.orientation.z;
    ego.pose.orientation.w = 1.0;
    ego.scale.x = 0.15;
    ego.scale.y = 0.3;
    ego.scale.z = 0.15;
    ego.color.a = 1.0; // Don't forget to set the alpha!
    ego.color.r = 0.0;
    ego.color.g = 1.0;
    ego.color.b = 0.0;

    publisher_ego_->publish(ego);
}

void EgoViz::on_topic_ego_state(const nandhi_msg_types::msg::EgoState::ConstSharedPtr msg)
{
  // RCLCPP_INFO(this->get_logger(), "I heard: '%f' '%f' '%f'", msg->pose.x, msg->pose.y, msg->pose.z);
  // RCLCPP_INFO(this->get_logger(), "I heard: '%f' '%f' '%f'", msg->orientation.x, msg->orientation.y, msg->orientation.z);
  ego_state.pose = msg->pose;
  ego_state.orientation = msg->orientation;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EgoViz>());
  rclcpp::shutdown();
  return 0;
}
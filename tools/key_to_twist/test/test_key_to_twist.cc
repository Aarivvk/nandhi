#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include <functional>
#include <memory>

using std::placeholders::_1;

class TwistCMDReciver : public rclcpp::Node
{
    public:
        TwistCMDReciver() : Node("Twist_listner")
        {
            m_subscription = this->create_subscription<geometry_msgs::msg::Twist>(
                "/nandhi/cmd_vel", 10, std::bind(&TwistCMDReciver::topic_callback, this, _1));
        }

    private:
        void topic_callback(const geometry_msgs::msg::Twist &msg) const
        {
            RCLCPP_INFO(this->get_logger(), "I heard: '%s', '%s'", std::to_string(msg.linear.x).c_str(), std::to_string(msg.angular.z).c_str());
        }
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr m_subscription;
};

int
main(int argc, char *argv[])
{
        rclcpp::init(argc, argv);
        rclcpp::spin(std::make_shared<TwistCMDReciver>());
        rclcpp::shutdown();
        return 0;
}
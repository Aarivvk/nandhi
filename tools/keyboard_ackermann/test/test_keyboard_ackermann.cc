#include "nandhi_msg_types/msg/ackermann_drive.hpp"
#include "rclcpp/rclcpp.hpp"
#include <functional>
#include <memory>

using std::placeholders::_1;

class AckermanCMDReciver : public rclcpp::Node
{
    public:
        AckermanCMDReciver() : Node("Ackerman_listner")
        {
            m_subscription = this->create_subscription<nandhi_msg_types::msg::AckermannDrive>(
                "/ackermann_cmd", 10, std::bind(&AckermanCMDReciver::topic_callback, this, _1));
        }

    private:
        void topic_callback(const nandhi_msg_types::msg::AckermannDrive &msg) const
        {
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", std::to_string(msg.speed).c_str());
        }
        rclcpp::Subscription<nandhi_msg_types::msg::AckermannDrive>::SharedPtr m_subscription;
};

int
main(int argc, char *argv[])
{
        rclcpp::init(argc, argv);
        rclcpp::spin(std::make_shared<AckermanCMDReciver>());
        rclcpp::shutdown();
        return 0;
}
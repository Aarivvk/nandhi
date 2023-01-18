#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "nandhi_msg_types/msg/ackermann_drive.hpp"

#include "i2c_pwm_pca9685/i2c_pwm.hh"


using std::placeholders::_1;

class AckermanCMDReciver : public rclcpp::Node
{
public:
    AckermanCMDReciver() : Node("vehicle_control_system")
    {
        m_subscription = this->create_subscription<nandhi_msg_types::msg::AckermannDrive>(
            "/ackermann_cmd", 10, std::bind(&AckermanCMDReciver::topic_callback, this, _1));
        m_pca.setPWMFreq(55);
        m_pca.setPWM(1, servo_mid);
        m_pca.setPWM(0, servo_mid);
    }

    AckermanCMDReciver()
    {
        m_pca.setPWM(1, servo_mid);
        m_pca.setPWM(0, servo_mid);
    }

        private : void topic_callback(const nandhi_msg_types::msg::AckermannDrive &msg) const
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", std::to_string(msg.speed).c_str());
        m_pca.setPWM(0, msg.speed);
        m_pca.setPWM(1, msg.steering_angle);
    }
    rclcpp::Subscription<nandhi_msg_types::msg::AckermannDrive>::SharedPtr m_subscription;
    PCA9685 m_pca = PCA9685(8, 0x40);
    constexpr int servo_mid = 340;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AckermanCMDReciver>());
    rclcpp::shutdown();
    return 0;
}
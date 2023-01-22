
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
        m_pca.setPWMFreq(PWM_FQ);
        reset();
    }

    ~AckermanCMDReciver()
    {
        reset();
    }

private:
    void topic_callback(const nandhi_msg_types::msg::AckermannDrive &msg)
    {
        RCLCPP_INFO(this->get_logger(), "I heard: speed = '%s', steering = '%s'", std::to_string(msg.speed).c_str(), std::to_string(msg.steering_angle).c_str());
        set_speed(msg.speed);
        set_steering(msg.steering_angle);
    }

    void set_speed(float speed)
    {
        m_pca.setPWM(SPEED_PIN, speed);
    }

    void set_steering(float steering)
    {
        m_pca.setPWM(STEERING_PIN, steering);
    }

    void reset()
    {
        set_speed(SERVO_MID_SPEED);
        set_steering(SERVO_MID_STEERING);
    }

    rclcpp::Subscription<nandhi_msg_types::msg::AckermannDrive>::SharedPtr m_subscription;
    PCA9685 m_pca = PCA9685(8, 0x40);
    const int SERVO_MID_SPEED = 330;
    const int SERVO_MID_STEERING = 430;
    const uint16_t PWM_FQ = 60;
    const uint8_t SPEED_PIN{0};
    const uint8_t STEERING_PIN{1};
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AckermanCMDReciver>());
    rclcpp::shutdown();
    return 0;
}
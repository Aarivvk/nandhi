
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "nandhi_msg_types/msg/ackermann_drive.hpp"

#include "i2c_pwm_pca9685/i2c_pwm.hh"

using std::placeholders::_1;

struct VCSData
{
    int speed{};
    int steering{};
};

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

        VCSData vcs_data = converte_percent_ackerman_to_vcs(msg);
        RCLCPP_INFO(this->get_logger(), "Converted: speed = '%s', steering = '%s'", std::to_string(vcs_data.speed).c_str(), std::to_string(vcs_data.steering).c_str());
        set_vcs_data_to_pwm(vcs_data);
        // set_speed(msg.speed);
        // set_steering(msg.steering_angle);
    }

    int convert_steering(float value)
    {
        int steering{SERVO_MID_STEERING};
        if (0 <= value && 100 >= value)
        {
            steering += convert_range(SERVO_MIN_STEERING, SERVO_MID_STEERING, 100, value);
        }
        else if (0 > value && -100 <= value)
        {
            steering -= convert_range(SERVO_MID_STEERING, SERVO_MAX_STEERING, 100, value);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Invalid convert steering value = '%s'", std::to_string(value).c_str());
        }
        return steering;
    }

    int convert_speed(float value)
    {
        int speed{SERVO_MID_SPEED};
        if (0 <= value && 100 >= value)
        {
            speed += convert_range(SERVO_MID_SPEED, SERVO_MAX_SPEED, 100, value);
        }
        else if (0 > value && -100 <= value)
        {
            speed -= convert_range(SERVO_MIN_SPEED, SERVO_MID_SPEED, 100, value);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Invalid convert speed value = '%s'", std::to_string(value).c_str());
        }
        return speed;
    }

    int convert_range(float min, float max, float range, float value)
    {
        int convert{};
        convert = (int)std::round((std::abs(value) * (max - min)) / range);
        return convert;
    }

    VCSData converte_percent_ackerman_to_vcs(const nandhi_msg_types::msg::AckermannDrive &ackerman_data)
    {
        VCSData vcs_data{};
        vcs_data.speed = convert_speed(ackerman_data.speed);
        vcs_data.steering = convert_steering(ackerman_data.steering_angle);
        return vcs_data;
    }

    void set_vcs_data_to_pwm(const VCSData data)
    {
        set_speed(data.speed);
        set_steering(data.steering);
    }

    void set_speed(float speed)
    {
        if (SERVO_MIN_SPEED <= speed && SERVO_MAX_SPEED >= speed)
        {
            m_pca.setPWM(SPEED_PIN, speed);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Ignore speed value = '%s'", std::to_string(speed).c_str());
        }
    }

    void set_steering(float steering)
    {
        if (SERVO_MIN_STEERING <= steering && SERVO_MAX_STEERING >= steering)
        {
            m_pca.setPWM(STEERING_PIN, steering);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Ignore steering value = '%s'", std::to_string(steering).c_str());
        }
    }

    void reset()
    {
        set_speed(SERVO_MID_SPEED);
        set_steering(SERVO_MID_STEERING);
    }

    rclcpp::Subscription<nandhi_msg_types::msg::AckermannDrive>::SharedPtr m_subscription;
    PCA9685 m_pca = PCA9685(8, 0x40);

    const int SERVO_MIN_SPEED = 345; // In reverse
    const int SERVO_MID_SPEED = 380; // zero moment
    const int SERVO_MAX_SPEED = 550; // In forward

    const int SERVO_MIN_STEERING = 315; // Right side
    const int SERVO_MID_STEERING = 430; // centered
    const int SERVO_MAX_STEERING = 550; // Left side

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
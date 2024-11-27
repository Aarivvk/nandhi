
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include "i2c_pwm_pca9685/i2c_pwm.hh"

using std::placeholders::_1;

struct VCSData
{
    int speed{};
    int steering{};
};

class TwistCMDReciver : public rclcpp::Node
{
public:
    TwistCMDReciver() : Node("vehicle_control_system")
    {
        m_subscription = this->create_subscription<geometry_msgs::msg::Twist>(
            "/nandhi/cmd_vel", 10, std::bind(&TwistCMDReciver::topic_callback, this, _1));
        m_pca.setPWMFreq(PWM_FQ);
        reset();
    }

    ~TwistCMDReciver()
    {
        reset();
    }

private:
    void topic_callback(const geometry_msgs::msg::Twist &msg)
    {
        RCLCPP_INFO(this->get_logger(), "I heard: speed = '%s', steering = '%s'", std::to_string(msg.linear.x).c_str(), std::to_string(msg.angular.z).c_str());

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

    VCSData converte_percent_ackerman_to_vcs(const geometry_msgs::msg::Twist &twist_msg)
    {
        VCSData vcs_data{};
        geometry_msgs::msg::Twist twist_data;
        twist_data.linear.x = (twist_msg.linear.x * 100)/max_linear_velocity;
        twist_data.angular.z = (twist_msg.angular.z * 100)/max_angular_velocity;
        vcs_data.speed = convert_speed(twist_data.linear.x);
        vcs_data.steering = convert_steering(twist_data.angular.z);
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

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr m_subscription;
    PCA9685 m_pca = PCA9685(8, 0x40);

    const int SERVO_MIN_SPEED = 250; // In reverse
    const int SERVO_MID_SPEED = 380; // zero moment
    const int SERVO_MAX_SPEED = 550; // In forward

    const int SERVO_MIN_STEERING = 250; // Right side
    const int SERVO_MID_STEERING = 340; // centered
    const int SERVO_MAX_STEERING = 550; // Left side

    const uint16_t PWM_FQ = 55;
    const uint8_t SPEED_PIN{0};
    const uint8_t STEERING_PIN{1};

    double max_linear_velocity = 13.89; // m/s
    double max_angular_velocity = 47.9; // rad/s
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TwistCMDReciver>());
    rclcpp::shutdown();
    return 0;
}
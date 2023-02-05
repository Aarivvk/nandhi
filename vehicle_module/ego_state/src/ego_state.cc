
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nandhi_msg_types/msg/imu_sensor.hpp"
#include "nandhi_msg_types/msg/ego_state.hpp"

#include "imu_sensor/imu_sensor.hh"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class EgoViz : public rclcpp::Node
{
  public:
    EgoViz()
    : Node("EgoSate")
    {
      publisher_ego_ = this->create_publisher<nandhi_msg_types::msg::EgoState>("ego_state", 10);
      publisher_imu_ = this->create_publisher<sensor_msgs::msg::Imu>("imu_sensor", 10);
      timer_ = this->create_wall_timer(DT, std::bind(&EgoViz::timer_callback, this));
    }

  private:
    const std::chrono::milliseconds DT = 100ms;
    const double PI = 22/7;
    double raw_pitch_acc_rad{}, raw_gyro_pitch_rad{};
    double raw_roll_acc_rad{}, raw_gyro_roll_rad{};
    double raw_gyro_yaw{};
    nandhi_msg_types::msg::EgoState ego_;
    void timer_callback();
    void printData(const RawImuSensorData &data) const;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<nandhi_msg_types::msg::EgoState>::SharedPtr publisher_ego_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr publisher_imu_;
    ImuSensor imu{8, 0x68};
};

void EgoViz::printData(const RawImuSensorData &data) const
{
  std::cout << "Acceleroneter :" << std::endl;
  std::cout << "vX: " << data.raw_acc_x << std::endl;
  std::cout << "vY: " << data.raw_acc_y << std::endl;
  std::cout << "vZ: " << data.raw_acc_z << std::endl;
  std::cout << std::endl;
  std::cout << "Gyro :" << std::endl;
  std::cout << "wX: " << data.raw_gyro_x << std::endl;
  std::cout << "wY: " << data.raw_gyro_y << std::endl;
  std::cout << "wZ: " << data.raw_gyro_z << std::endl;
  std::cout << std::endl;
  std::cout << "Magnetometer :" << std::endl;
  std::cout << "TX: " << data.raw_mag_x << std::endl;
  std::cout << "TY: " << data.raw_mag_y << std::endl;
  std::cout << "TZ: " << data.raw_mag_z << std::endl;
  std::cout << std::endl;
  std::cout << "Temparature :" << data.temp << std::endl;
  std::cout << "======================================================" << std::endl;
}

void EgoViz::timer_callback()
{
  auto dts = 0.1;
  auto data = imu.fetchEgoState();
  sensor_msgs::msg::Imu imu_data;
  imu_data.header.stamp = this->get_clock()->now();
  imu_data.header.frame_id = "nandhi_frame";
  imu_data.linear_acceleration.x = data.raw_acc_x;
  imu_data.linear_acceleration.y = data.raw_acc_y;// fix for MPU9250 make it z
  imu_data.linear_acceleration.z = data.raw_acc_z + 1;// fix for MPU9250 make it y

  imu_data.angular_velocity.x = data.raw_gyro_x;
  imu_data.angular_velocity.y = data.raw_gyro_y;
  imu_data.angular_velocity.z = data.raw_gyro_z;

  //TODO low pass filter for ACC.
  raw_pitch_acc_rad = 0.60 * raw_pitch_acc_rad + 0.40 * atan2(imu_data.linear_acceleration.x, imu_data.linear_acceleration.z);
  raw_roll_acc_rad = 0.60 * raw_roll_acc_rad + 0.40 * atan2(imu_data.linear_acceleration.y, imu_data.linear_acceleration.z);
  raw_gyro_pitch_rad = (raw_gyro_pitch_rad + imu_data.angular_velocity.y * dts) * (PI / 180);
  raw_gyro_roll_rad = (raw_gyro_roll_rad + imu_data.angular_velocity.x * dts) * (PI / 180);
  raw_gyro_yaw = (raw_gyro_yaw + imu_data.angular_velocity.z * dts) * (PI / 180);
  // Low pass filter taking the gyro for the curent instance but over time acc is considered. Fusion.
  ego_.orientation.x = (0.70 * raw_gyro_pitch_rad) + (0.30 * raw_pitch_acc_rad);
  ego_.orientation.y = (0.70 * raw_gyro_roll_rad) + (0.30 * raw_roll_acc_rad);
  ego_.orientation.z += raw_gyro_yaw;

  publisher_ego_->publish(ego_);
  publisher_imu_->publish(imu_data);
  // printData(data);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EgoViz>());
  rclcpp::shutdown();
  return 0;
}
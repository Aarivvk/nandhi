// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__BUILDER_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__BUILDER_HPP_

#include "nandhi_msg_types/msg/detail/imu_sensor__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace nandhi_msg_types
{

namespace msg
{

namespace builder
{

class Init_ImuSensor_temp
{
public:
  explicit Init_ImuSensor_temp(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  ::nandhi_msg_types::msg::ImuSensor temp(::nandhi_msg_types::msg::ImuSensor::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_mag_z
{
public:
  explicit Init_ImuSensor_raw_mag_z(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_temp raw_mag_z(::nandhi_msg_types::msg::ImuSensor::_raw_mag_z_type arg)
  {
    msg_.raw_mag_z = std::move(arg);
    return Init_ImuSensor_temp(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_mag_y
{
public:
  explicit Init_ImuSensor_raw_mag_y(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_mag_z raw_mag_y(::nandhi_msg_types::msg::ImuSensor::_raw_mag_y_type arg)
  {
    msg_.raw_mag_y = std::move(arg);
    return Init_ImuSensor_raw_mag_z(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_mag_x
{
public:
  explicit Init_ImuSensor_raw_mag_x(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_mag_y raw_mag_x(::nandhi_msg_types::msg::ImuSensor::_raw_mag_x_type arg)
  {
    msg_.raw_mag_x = std::move(arg);
    return Init_ImuSensor_raw_mag_y(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_gyro_z
{
public:
  explicit Init_ImuSensor_raw_gyro_z(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_mag_x raw_gyro_z(::nandhi_msg_types::msg::ImuSensor::_raw_gyro_z_type arg)
  {
    msg_.raw_gyro_z = std::move(arg);
    return Init_ImuSensor_raw_mag_x(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_gyro_y
{
public:
  explicit Init_ImuSensor_raw_gyro_y(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_gyro_z raw_gyro_y(::nandhi_msg_types::msg::ImuSensor::_raw_gyro_y_type arg)
  {
    msg_.raw_gyro_y = std::move(arg);
    return Init_ImuSensor_raw_gyro_z(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_gyro_x
{
public:
  explicit Init_ImuSensor_raw_gyro_x(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_gyro_y raw_gyro_x(::nandhi_msg_types::msg::ImuSensor::_raw_gyro_x_type arg)
  {
    msg_.raw_gyro_x = std::move(arg);
    return Init_ImuSensor_raw_gyro_y(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_acc_z
{
public:
  explicit Init_ImuSensor_raw_acc_z(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_gyro_x raw_acc_z(::nandhi_msg_types::msg::ImuSensor::_raw_acc_z_type arg)
  {
    msg_.raw_acc_z = std::move(arg);
    return Init_ImuSensor_raw_gyro_x(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_acc_y
{
public:
  explicit Init_ImuSensor_raw_acc_y(::nandhi_msg_types::msg::ImuSensor & msg)
  : msg_(msg)
  {}
  Init_ImuSensor_raw_acc_z raw_acc_y(::nandhi_msg_types::msg::ImuSensor::_raw_acc_y_type arg)
  {
    msg_.raw_acc_y = std::move(arg);
    return Init_ImuSensor_raw_acc_z(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

class Init_ImuSensor_raw_acc_x
{
public:
  Init_ImuSensor_raw_acc_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuSensor_raw_acc_y raw_acc_x(::nandhi_msg_types::msg::ImuSensor::_raw_acc_x_type arg)
  {
    msg_.raw_acc_x = std::move(arg);
    return Init_ImuSensor_raw_acc_y(msg_);
  }

private:
  ::nandhi_msg_types::msg::ImuSensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nandhi_msg_types::msg::ImuSensor>()
{
  return nandhi_msg_types::msg::builder::Init_ImuSensor_raw_acc_x();
}

}  // namespace nandhi_msg_types

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__BUILDER_HPP_

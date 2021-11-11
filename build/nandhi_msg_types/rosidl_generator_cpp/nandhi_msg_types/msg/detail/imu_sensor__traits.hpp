// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__TRAITS_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__TRAITS_HPP_

#include "nandhi_msg_types/msg/detail/imu_sensor__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nandhi_msg_types::msg::ImuSensor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: raw_acc_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_acc_x: ";
    value_to_yaml(msg.raw_acc_x, out);
    out << "\n";
  }

  // member: raw_acc_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_acc_y: ";
    value_to_yaml(msg.raw_acc_y, out);
    out << "\n";
  }

  // member: raw_acc_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_acc_z: ";
    value_to_yaml(msg.raw_acc_z, out);
    out << "\n";
  }

  // member: raw_gyro_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_gyro_x: ";
    value_to_yaml(msg.raw_gyro_x, out);
    out << "\n";
  }

  // member: raw_gyro_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_gyro_y: ";
    value_to_yaml(msg.raw_gyro_y, out);
    out << "\n";
  }

  // member: raw_gyro_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_gyro_z: ";
    value_to_yaml(msg.raw_gyro_z, out);
    out << "\n";
  }

  // member: raw_mag_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_mag_x: ";
    value_to_yaml(msg.raw_mag_x, out);
    out << "\n";
  }

  // member: raw_mag_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_mag_y: ";
    value_to_yaml(msg.raw_mag_y, out);
    out << "\n";
  }

  // member: raw_mag_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_mag_z: ";
    value_to_yaml(msg.raw_mag_z, out);
    out << "\n";
  }

  // member: temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp: ";
    value_to_yaml(msg.temp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nandhi_msg_types::msg::ImuSensor & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nandhi_msg_types::msg::ImuSensor>()
{
  return "nandhi_msg_types::msg::ImuSensor";
}

template<>
inline const char * name<nandhi_msg_types::msg::ImuSensor>()
{
  return "nandhi_msg_types/msg/ImuSensor";
}

template<>
struct has_fixed_size<nandhi_msg_types::msg::ImuSensor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nandhi_msg_types::msg::ImuSensor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nandhi_msg_types::msg::ImuSensor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__TRAITS_HPP_

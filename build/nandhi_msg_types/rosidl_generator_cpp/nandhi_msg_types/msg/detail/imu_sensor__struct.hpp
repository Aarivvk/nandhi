// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__STRUCT_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__nandhi_msg_types__msg__ImuSensor __attribute__((deprecated))
#else
# define DEPRECATED__nandhi_msg_types__msg__ImuSensor __declspec(deprecated)
#endif

namespace nandhi_msg_types
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuSensor_
{
  using Type = ImuSensor_<ContainerAllocator>;

  explicit ImuSensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_acc_x = 0.0;
      this->raw_acc_y = 0.0;
      this->raw_acc_z = 0.0;
      this->raw_gyro_x = 0.0;
      this->raw_gyro_y = 0.0;
      this->raw_gyro_z = 0.0;
      this->raw_mag_x = 0.0;
      this->raw_mag_y = 0.0;
      this->raw_mag_z = 0.0;
      this->temp = 0.0;
    }
  }

  explicit ImuSensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_acc_x = 0.0;
      this->raw_acc_y = 0.0;
      this->raw_acc_z = 0.0;
      this->raw_gyro_x = 0.0;
      this->raw_gyro_y = 0.0;
      this->raw_gyro_z = 0.0;
      this->raw_mag_x = 0.0;
      this->raw_mag_y = 0.0;
      this->raw_mag_z = 0.0;
      this->temp = 0.0;
    }
  }

  // field types and members
  using _raw_acc_x_type =
    double;
  _raw_acc_x_type raw_acc_x;
  using _raw_acc_y_type =
    double;
  _raw_acc_y_type raw_acc_y;
  using _raw_acc_z_type =
    double;
  _raw_acc_z_type raw_acc_z;
  using _raw_gyro_x_type =
    double;
  _raw_gyro_x_type raw_gyro_x;
  using _raw_gyro_y_type =
    double;
  _raw_gyro_y_type raw_gyro_y;
  using _raw_gyro_z_type =
    double;
  _raw_gyro_z_type raw_gyro_z;
  using _raw_mag_x_type =
    double;
  _raw_mag_x_type raw_mag_x;
  using _raw_mag_y_type =
    double;
  _raw_mag_y_type raw_mag_y;
  using _raw_mag_z_type =
    double;
  _raw_mag_z_type raw_mag_z;
  using _temp_type =
    double;
  _temp_type temp;

  // setters for named parameter idiom
  Type & set__raw_acc_x(
    const double & _arg)
  {
    this->raw_acc_x = _arg;
    return *this;
  }
  Type & set__raw_acc_y(
    const double & _arg)
  {
    this->raw_acc_y = _arg;
    return *this;
  }
  Type & set__raw_acc_z(
    const double & _arg)
  {
    this->raw_acc_z = _arg;
    return *this;
  }
  Type & set__raw_gyro_x(
    const double & _arg)
  {
    this->raw_gyro_x = _arg;
    return *this;
  }
  Type & set__raw_gyro_y(
    const double & _arg)
  {
    this->raw_gyro_y = _arg;
    return *this;
  }
  Type & set__raw_gyro_z(
    const double & _arg)
  {
    this->raw_gyro_z = _arg;
    return *this;
  }
  Type & set__raw_mag_x(
    const double & _arg)
  {
    this->raw_mag_x = _arg;
    return *this;
  }
  Type & set__raw_mag_y(
    const double & _arg)
  {
    this->raw_mag_y = _arg;
    return *this;
  }
  Type & set__raw_mag_z(
    const double & _arg)
  {
    this->raw_mag_z = _arg;
    return *this;
  }
  Type & set__temp(
    const double & _arg)
  {
    this->temp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nandhi_msg_types::msg::ImuSensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const nandhi_msg_types::msg::ImuSensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nandhi_msg_types::msg::ImuSensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nandhi_msg_types::msg::ImuSensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nandhi_msg_types__msg__ImuSensor
    std::shared_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nandhi_msg_types__msg__ImuSensor
    std::shared_ptr<nandhi_msg_types::msg::ImuSensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuSensor_ & other) const
  {
    if (this->raw_acc_x != other.raw_acc_x) {
      return false;
    }
    if (this->raw_acc_y != other.raw_acc_y) {
      return false;
    }
    if (this->raw_acc_z != other.raw_acc_z) {
      return false;
    }
    if (this->raw_gyro_x != other.raw_gyro_x) {
      return false;
    }
    if (this->raw_gyro_y != other.raw_gyro_y) {
      return false;
    }
    if (this->raw_gyro_z != other.raw_gyro_z) {
      return false;
    }
    if (this->raw_mag_x != other.raw_mag_x) {
      return false;
    }
    if (this->raw_mag_y != other.raw_mag_y) {
      return false;
    }
    if (this->raw_mag_z != other.raw_mag_z) {
      return false;
    }
    if (this->temp != other.temp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuSensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuSensor_

// alias to use template instance with default allocator
using ImuSensor =
  nandhi_msg_types::msg::ImuSensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nandhi_msg_types

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__STRUCT_HPP_

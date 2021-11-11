// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nandhi_msg_types:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__BUILDER_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__BUILDER_HPP_

#include "nandhi_msg_types/msg/detail/orientation__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace nandhi_msg_types
{

namespace msg
{

namespace builder
{

class Init_Orientation_z
{
public:
  explicit Init_Orientation_z(::nandhi_msg_types::msg::Orientation & msg)
  : msg_(msg)
  {}
  ::nandhi_msg_types::msg::Orientation z(::nandhi_msg_types::msg::Orientation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nandhi_msg_types::msg::Orientation msg_;
};

class Init_Orientation_y
{
public:
  explicit Init_Orientation_y(::nandhi_msg_types::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_z y(::nandhi_msg_types::msg::Orientation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Orientation_z(msg_);
  }

private:
  ::nandhi_msg_types::msg::Orientation msg_;
};

class Init_Orientation_x
{
public:
  Init_Orientation_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Orientation_y x(::nandhi_msg_types::msg::Orientation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Orientation_y(msg_);
  }

private:
  ::nandhi_msg_types::msg::Orientation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nandhi_msg_types::msg::Orientation>()
{
  return nandhi_msg_types::msg::builder::Init_Orientation_x();
}

}  // namespace nandhi_msg_types

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__BUILDER_HPP_

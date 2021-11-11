// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nandhi_msg_types:msg/Pose.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__POSE__BUILDER_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__POSE__BUILDER_HPP_

#include "nandhi_msg_types/msg/detail/pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace nandhi_msg_types
{

namespace msg
{

namespace builder
{

class Init_Pose_z
{
public:
  explicit Init_Pose_z(::nandhi_msg_types::msg::Pose & msg)
  : msg_(msg)
  {}
  ::nandhi_msg_types::msg::Pose z(::nandhi_msg_types::msg::Pose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nandhi_msg_types::msg::Pose msg_;
};

class Init_Pose_y
{
public:
  explicit Init_Pose_y(::nandhi_msg_types::msg::Pose & msg)
  : msg_(msg)
  {}
  Init_Pose_z y(::nandhi_msg_types::msg::Pose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Pose_z(msg_);
  }

private:
  ::nandhi_msg_types::msg::Pose msg_;
};

class Init_Pose_x
{
public:
  Init_Pose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pose_y x(::nandhi_msg_types::msg::Pose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Pose_y(msg_);
  }

private:
  ::nandhi_msg_types::msg::Pose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nandhi_msg_types::msg::Pose>()
{
  return nandhi_msg_types::msg::builder::Init_Pose_x();
}

}  // namespace nandhi_msg_types

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__POSE__BUILDER_HPP_

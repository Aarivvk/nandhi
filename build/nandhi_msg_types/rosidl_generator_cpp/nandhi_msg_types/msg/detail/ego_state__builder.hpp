// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__BUILDER_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__BUILDER_HPP_

#include "nandhi_msg_types/msg/detail/ego_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace nandhi_msg_types
{

namespace msg
{

namespace builder
{

class Init_EgoState_orientation
{
public:
  explicit Init_EgoState_orientation(::nandhi_msg_types::msg::EgoState & msg)
  : msg_(msg)
  {}
  ::nandhi_msg_types::msg::EgoState orientation(::nandhi_msg_types::msg::EgoState::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nandhi_msg_types::msg::EgoState msg_;
};

class Init_EgoState_pose
{
public:
  Init_EgoState_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EgoState_orientation pose(::nandhi_msg_types::msg::EgoState::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_EgoState_orientation(msg_);
  }

private:
  ::nandhi_msg_types::msg::EgoState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nandhi_msg_types::msg::EgoState>()
{
  return nandhi_msg_types::msg::builder::Init_EgoState_pose();
}

}  // namespace nandhi_msg_types

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__BUILDER_HPP_

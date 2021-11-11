// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__STRUCT_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pose'
#include "nandhi_msg_types/msg/detail/pose__struct.hpp"
// Member 'orientation'
#include "nandhi_msg_types/msg/detail/orientation__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nandhi_msg_types__msg__EgoState __attribute__((deprecated))
#else
# define DEPRECATED__nandhi_msg_types__msg__EgoState __declspec(deprecated)
#endif

namespace nandhi_msg_types
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EgoState_
{
  using Type = EgoState_<ContainerAllocator>;

  explicit EgoState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    orientation(_init)
  {
    (void)_init;
  }

  explicit EgoState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init),
    orientation(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _pose_type =
    nandhi_msg_types::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _orientation_type =
    nandhi_msg_types::msg::Orientation_<ContainerAllocator>;
  _orientation_type orientation;

  // setters for named parameter idiom
  Type & set__pose(
    const nandhi_msg_types::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__orientation(
    const nandhi_msg_types::msg::Orientation_<ContainerAllocator> & _arg)
  {
    this->orientation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nandhi_msg_types::msg::EgoState_<ContainerAllocator> *;
  using ConstRawPtr =
    const nandhi_msg_types::msg::EgoState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nandhi_msg_types::msg::EgoState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nandhi_msg_types::msg::EgoState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nandhi_msg_types__msg__EgoState
    std::shared_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nandhi_msg_types__msg__EgoState
    std::shared_ptr<nandhi_msg_types::msg::EgoState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EgoState_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    return true;
  }
  bool operator!=(const EgoState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EgoState_

// alias to use template instance with default allocator
using EgoState =
  nandhi_msg_types::msg::EgoState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nandhi_msg_types

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__STRUCT_HPP_

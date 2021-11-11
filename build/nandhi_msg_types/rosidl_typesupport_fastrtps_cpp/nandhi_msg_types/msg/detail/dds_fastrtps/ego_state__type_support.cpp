// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice
#include "nandhi_msg_types/msg/detail/ego_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "nandhi_msg_types/msg/detail/ego_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace nandhi_msg_types
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const nandhi_msg_types::msg::Pose &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  nandhi_msg_types::msg::Pose &);
size_t get_serialized_size(
  const nandhi_msg_types::msg::Pose &,
  size_t current_alignment);
size_t
max_serialized_size_Pose(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace nandhi_msg_types

namespace nandhi_msg_types
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const nandhi_msg_types::msg::Orientation &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  nandhi_msg_types::msg::Orientation &);
size_t get_serialized_size(
  const nandhi_msg_types::msg::Orientation &,
  size_t current_alignment);
size_t
max_serialized_size_Orientation(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace nandhi_msg_types


namespace nandhi_msg_types
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
cdr_serialize(
  const nandhi_msg_types::msg::EgoState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pose
  nandhi_msg_types::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.pose,
    cdr);
  // Member: orientation
  nandhi_msg_types::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.orientation,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nandhi_msg_types::msg::EgoState & ros_message)
{
  // Member: pose
  nandhi_msg_types::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.pose);

  // Member: orientation
  nandhi_msg_types::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.orientation);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
get_serialized_size(
  const nandhi_msg_types::msg::EgoState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pose

  current_alignment +=
    nandhi_msg_types::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.pose, current_alignment);
  // Member: orientation

  current_alignment +=
    nandhi_msg_types::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.orientation, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
max_serialized_size_EgoState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: pose
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        nandhi_msg_types::msg::typesupport_fastrtps_cpp::max_serialized_size_Pose(
        full_bounded, current_alignment);
    }
  }

  // Member: orientation
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        nandhi_msg_types::msg::typesupport_fastrtps_cpp::max_serialized_size_Orientation(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _EgoState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const nandhi_msg_types::msg::EgoState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _EgoState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nandhi_msg_types::msg::EgoState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _EgoState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nandhi_msg_types::msg::EgoState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _EgoState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_EgoState(full_bounded, 0);
}

static message_type_support_callbacks_t _EgoState__callbacks = {
  "nandhi_msg_types::msg",
  "EgoState",
  _EgoState__cdr_serialize,
  _EgoState__cdr_deserialize,
  _EgoState__get_serialized_size,
  _EgoState__max_serialized_size
};

static rosidl_message_type_support_t _EgoState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_EgoState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace nandhi_msg_types

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nandhi_msg_types
const rosidl_message_type_support_t *
get_message_type_support_handle<nandhi_msg_types::msg::EgoState>()
{
  return &nandhi_msg_types::msg::typesupport_fastrtps_cpp::_EgoState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nandhi_msg_types, msg, EgoState)() {
  return &nandhi_msg_types::msg::typesupport_fastrtps_cpp::_EgoState__handle;
}

#ifdef __cplusplus
}
#endif

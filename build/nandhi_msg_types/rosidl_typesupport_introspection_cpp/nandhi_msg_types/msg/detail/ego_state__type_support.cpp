// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nandhi_msg_types/msg/detail/ego_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nandhi_msg_types
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void EgoState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nandhi_msg_types::msg::EgoState(_init);
}

void EgoState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nandhi_msg_types::msg::EgoState *>(message_memory);
  typed_message->~EgoState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember EgoState_message_member_array[2] = {
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nandhi_msg_types::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types::msg::EgoState, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "orientation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nandhi_msg_types::msg::Orientation>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types::msg::EgoState, orientation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers EgoState_message_members = {
  "nandhi_msg_types::msg",  // message namespace
  "EgoState",  // message name
  2,  // number of fields
  sizeof(nandhi_msg_types::msg::EgoState),
  EgoState_message_member_array,  // message members
  EgoState_init_function,  // function to initialize message memory (memory has to be allocated)
  EgoState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t EgoState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &EgoState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace nandhi_msg_types


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nandhi_msg_types::msg::EgoState>()
{
  return &::nandhi_msg_types::msg::rosidl_typesupport_introspection_cpp::EgoState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nandhi_msg_types, msg, EgoState)() {
  return &::nandhi_msg_types::msg::rosidl_typesupport_introspection_cpp::EgoState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

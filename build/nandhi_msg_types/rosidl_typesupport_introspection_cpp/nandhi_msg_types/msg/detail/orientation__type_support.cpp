// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nandhi_msg_types:msg/Orientation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nandhi_msg_types/msg/detail/orientation__struct.hpp"
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

void Orientation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nandhi_msg_types::msg::Orientation(_init);
}

void Orientation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nandhi_msg_types::msg::Orientation *>(message_memory);
  typed_message->~Orientation();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Orientation_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types::msg::Orientation, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types::msg::Orientation, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types::msg::Orientation, z),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Orientation_message_members = {
  "nandhi_msg_types::msg",  // message namespace
  "Orientation",  // message name
  3,  // number of fields
  sizeof(nandhi_msg_types::msg::Orientation),
  Orientation_message_member_array,  // message members
  Orientation_init_function,  // function to initialize message memory (memory has to be allocated)
  Orientation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Orientation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Orientation_message_members,
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
get_message_type_support_handle<nandhi_msg_types::msg::Orientation>()
{
  return &::nandhi_msg_types::msg::rosidl_typesupport_introspection_cpp::Orientation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nandhi_msg_types, msg, Orientation)() {
  return &::nandhi_msg_types::msg::rosidl_typesupport_introspection_cpp::Orientation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

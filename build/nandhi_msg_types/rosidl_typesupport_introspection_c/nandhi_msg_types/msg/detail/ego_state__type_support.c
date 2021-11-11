// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nandhi_msg_types/msg/detail/ego_state__rosidl_typesupport_introspection_c.h"
#include "nandhi_msg_types/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nandhi_msg_types/msg/detail/ego_state__functions.h"
#include "nandhi_msg_types/msg/detail/ego_state__struct.h"


// Include directives for member types
// Member `pose`
#include "nandhi_msg_types/msg/pose.h"
// Member `pose`
#include "nandhi_msg_types/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `orientation`
#include "nandhi_msg_types/msg/orientation.h"
// Member `orientation`
#include "nandhi_msg_types/msg/detail/orientation__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void EgoState__rosidl_typesupport_introspection_c__EgoState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nandhi_msg_types__msg__EgoState__init(message_memory);
}

void EgoState__rosidl_typesupport_introspection_c__EgoState_fini_function(void * message_memory)
{
  nandhi_msg_types__msg__EgoState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember EgoState__rosidl_typesupport_introspection_c__EgoState_message_member_array[2] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__EgoState, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orientation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__EgoState, orientation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers EgoState__rosidl_typesupport_introspection_c__EgoState_message_members = {
  "nandhi_msg_types__msg",  // message namespace
  "EgoState",  // message name
  2,  // number of fields
  sizeof(nandhi_msg_types__msg__EgoState),
  EgoState__rosidl_typesupport_introspection_c__EgoState_message_member_array,  // message members
  EgoState__rosidl_typesupport_introspection_c__EgoState_init_function,  // function to initialize message memory (memory has to be allocated)
  EgoState__rosidl_typesupport_introspection_c__EgoState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t EgoState__rosidl_typesupport_introspection_c__EgoState_message_type_support_handle = {
  0,
  &EgoState__rosidl_typesupport_introspection_c__EgoState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nandhi_msg_types
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nandhi_msg_types, msg, EgoState)() {
  EgoState__rosidl_typesupport_introspection_c__EgoState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nandhi_msg_types, msg, Pose)();
  EgoState__rosidl_typesupport_introspection_c__EgoState_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nandhi_msg_types, msg, Orientation)();
  if (!EgoState__rosidl_typesupport_introspection_c__EgoState_message_type_support_handle.typesupport_identifier) {
    EgoState__rosidl_typesupport_introspection_c__EgoState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &EgoState__rosidl_typesupport_introspection_c__EgoState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

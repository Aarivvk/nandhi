// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nandhi_msg_types/msg/detail/imu_sensor__rosidl_typesupport_introspection_c.h"
#include "nandhi_msg_types/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nandhi_msg_types/msg/detail/imu_sensor__functions.h"
#include "nandhi_msg_types/msg/detail/imu_sensor__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nandhi_msg_types__msg__ImuSensor__init(message_memory);
}

void ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_fini_function(void * message_memory)
{
  nandhi_msg_types__msg__ImuSensor__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_member_array[10] = {
  {
    "raw_acc_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_acc_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_acc_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_acc_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_acc_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_acc_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_gyro_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_gyro_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_gyro_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_gyro_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_gyro_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_gyro_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_mag_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_mag_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_mag_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_mag_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "raw_mag_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, raw_mag_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nandhi_msg_types__msg__ImuSensor, temp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_members = {
  "nandhi_msg_types__msg",  // message namespace
  "ImuSensor",  // message name
  10,  // number of fields
  sizeof(nandhi_msg_types__msg__ImuSensor),
  ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_member_array,  // message members
  ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_init_function,  // function to initialize message memory (memory has to be allocated)
  ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_type_support_handle = {
  0,
  &ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nandhi_msg_types
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nandhi_msg_types, msg, ImuSensor)() {
  if (!ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_type_support_handle.typesupport_identifier) {
    ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ImuSensor__rosidl_typesupport_introspection_c__ImuSensor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

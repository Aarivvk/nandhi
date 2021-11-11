// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nandhi_msg_types:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__STRUCT_H_
#define NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Orientation in the package nandhi_msg_types.
typedef struct nandhi_msg_types__msg__Orientation
{
  double x;
  double y;
  double z;
} nandhi_msg_types__msg__Orientation;

// Struct for a sequence of nandhi_msg_types__msg__Orientation.
typedef struct nandhi_msg_types__msg__Orientation__Sequence
{
  nandhi_msg_types__msg__Orientation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nandhi_msg_types__msg__Orientation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__STRUCT_H_

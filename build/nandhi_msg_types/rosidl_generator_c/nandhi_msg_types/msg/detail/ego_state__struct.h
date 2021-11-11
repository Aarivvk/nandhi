// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__STRUCT_H_
#define NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "nandhi_msg_types/msg/detail/pose__struct.h"
// Member 'orientation'
#include "nandhi_msg_types/msg/detail/orientation__struct.h"

// Struct defined in msg/EgoState in the package nandhi_msg_types.
typedef struct nandhi_msg_types__msg__EgoState
{
  nandhi_msg_types__msg__Pose pose;
  nandhi_msg_types__msg__Orientation orientation;
} nandhi_msg_types__msg__EgoState;

// Struct for a sequence of nandhi_msg_types__msg__EgoState.
typedef struct nandhi_msg_types__msg__EgoState__Sequence
{
  nandhi_msg_types__msg__EgoState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nandhi_msg_types__msg__EgoState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__STRUCT_H_

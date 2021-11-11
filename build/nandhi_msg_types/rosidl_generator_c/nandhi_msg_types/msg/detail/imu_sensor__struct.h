// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__STRUCT_H_
#define NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ImuSensor in the package nandhi_msg_types.
typedef struct nandhi_msg_types__msg__ImuSensor
{
  double raw_acc_x;
  double raw_acc_y;
  double raw_acc_z;
  double raw_gyro_x;
  double raw_gyro_y;
  double raw_gyro_z;
  double raw_mag_x;
  double raw_mag_y;
  double raw_mag_z;
  double temp;
} nandhi_msg_types__msg__ImuSensor;

// Struct for a sequence of nandhi_msg_types__msg__ImuSensor.
typedef struct nandhi_msg_types__msg__ImuSensor__Sequence
{
  nandhi_msg_types__msg__ImuSensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nandhi_msg_types__msg__ImuSensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__STRUCT_H_

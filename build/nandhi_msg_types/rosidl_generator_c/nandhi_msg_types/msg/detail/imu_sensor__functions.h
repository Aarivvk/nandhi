// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__FUNCTIONS_H_
#define NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nandhi_msg_types/msg/rosidl_generator_c__visibility_control.h"

#include "nandhi_msg_types/msg/detail/imu_sensor__struct.h"

/// Initialize msg/ImuSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nandhi_msg_types__msg__ImuSensor
 * )) before or use
 * nandhi_msg_types__msg__ImuSensor__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
bool
nandhi_msg_types__msg__ImuSensor__init(nandhi_msg_types__msg__ImuSensor * msg);

/// Finalize msg/ImuSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
void
nandhi_msg_types__msg__ImuSensor__fini(nandhi_msg_types__msg__ImuSensor * msg);

/// Create msg/ImuSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nandhi_msg_types__msg__ImuSensor__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
nandhi_msg_types__msg__ImuSensor *
nandhi_msg_types__msg__ImuSensor__create();

/// Destroy msg/ImuSensor message.
/**
 * It calls
 * nandhi_msg_types__msg__ImuSensor__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
void
nandhi_msg_types__msg__ImuSensor__destroy(nandhi_msg_types__msg__ImuSensor * msg);


/// Initialize array of msg/ImuSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * nandhi_msg_types__msg__ImuSensor__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
bool
nandhi_msg_types__msg__ImuSensor__Sequence__init(nandhi_msg_types__msg__ImuSensor__Sequence * array, size_t size);

/// Finalize array of msg/ImuSensor messages.
/**
 * It calls
 * nandhi_msg_types__msg__ImuSensor__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
void
nandhi_msg_types__msg__ImuSensor__Sequence__fini(nandhi_msg_types__msg__ImuSensor__Sequence * array);

/// Create array of msg/ImuSensor messages.
/**
 * It allocates the memory for the array and calls
 * nandhi_msg_types__msg__ImuSensor__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
nandhi_msg_types__msg__ImuSensor__Sequence *
nandhi_msg_types__msg__ImuSensor__Sequence__create(size_t size);

/// Destroy array of msg/ImuSensor messages.
/**
 * It calls
 * nandhi_msg_types__msg__ImuSensor__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nandhi_msg_types
void
nandhi_msg_types__msg__ImuSensor__Sequence__destroy(nandhi_msg_types__msg__ImuSensor__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__IMU_SENSOR__FUNCTIONS_H_

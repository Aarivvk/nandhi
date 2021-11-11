// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice
#include "nandhi_msg_types/msg/detail/imu_sensor__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "nandhi_msg_types/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nandhi_msg_types/msg/detail/imu_sensor__struct.h"
#include "nandhi_msg_types/msg/detail/imu_sensor__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ImuSensor__ros_msg_type = nandhi_msg_types__msg__ImuSensor;

static bool _ImuSensor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImuSensor__ros_msg_type * ros_message = static_cast<const _ImuSensor__ros_msg_type *>(untyped_ros_message);
  // Field name: raw_acc_x
  {
    cdr << ros_message->raw_acc_x;
  }

  // Field name: raw_acc_y
  {
    cdr << ros_message->raw_acc_y;
  }

  // Field name: raw_acc_z
  {
    cdr << ros_message->raw_acc_z;
  }

  // Field name: raw_gyro_x
  {
    cdr << ros_message->raw_gyro_x;
  }

  // Field name: raw_gyro_y
  {
    cdr << ros_message->raw_gyro_y;
  }

  // Field name: raw_gyro_z
  {
    cdr << ros_message->raw_gyro_z;
  }

  // Field name: raw_mag_x
  {
    cdr << ros_message->raw_mag_x;
  }

  // Field name: raw_mag_y
  {
    cdr << ros_message->raw_mag_y;
  }

  // Field name: raw_mag_z
  {
    cdr << ros_message->raw_mag_z;
  }

  // Field name: temp
  {
    cdr << ros_message->temp;
  }

  return true;
}

static bool _ImuSensor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImuSensor__ros_msg_type * ros_message = static_cast<_ImuSensor__ros_msg_type *>(untyped_ros_message);
  // Field name: raw_acc_x
  {
    cdr >> ros_message->raw_acc_x;
  }

  // Field name: raw_acc_y
  {
    cdr >> ros_message->raw_acc_y;
  }

  // Field name: raw_acc_z
  {
    cdr >> ros_message->raw_acc_z;
  }

  // Field name: raw_gyro_x
  {
    cdr >> ros_message->raw_gyro_x;
  }

  // Field name: raw_gyro_y
  {
    cdr >> ros_message->raw_gyro_y;
  }

  // Field name: raw_gyro_z
  {
    cdr >> ros_message->raw_gyro_z;
  }

  // Field name: raw_mag_x
  {
    cdr >> ros_message->raw_mag_x;
  }

  // Field name: raw_mag_y
  {
    cdr >> ros_message->raw_mag_y;
  }

  // Field name: raw_mag_z
  {
    cdr >> ros_message->raw_mag_z;
  }

  // Field name: temp
  {
    cdr >> ros_message->temp;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nandhi_msg_types
size_t get_serialized_size_nandhi_msg_types__msg__ImuSensor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImuSensor__ros_msg_type * ros_message = static_cast<const _ImuSensor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name raw_acc_x
  {
    size_t item_size = sizeof(ros_message->raw_acc_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_acc_y
  {
    size_t item_size = sizeof(ros_message->raw_acc_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_acc_z
  {
    size_t item_size = sizeof(ros_message->raw_acc_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_gyro_x
  {
    size_t item_size = sizeof(ros_message->raw_gyro_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_gyro_y
  {
    size_t item_size = sizeof(ros_message->raw_gyro_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_gyro_z
  {
    size_t item_size = sizeof(ros_message->raw_gyro_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_mag_x
  {
    size_t item_size = sizeof(ros_message->raw_mag_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_mag_y
  {
    size_t item_size = sizeof(ros_message->raw_mag_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name raw_mag_z
  {
    size_t item_size = sizeof(ros_message->raw_mag_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temp
  {
    size_t item_size = sizeof(ros_message->temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ImuSensor__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nandhi_msg_types__msg__ImuSensor(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nandhi_msg_types
size_t max_serialized_size_nandhi_msg_types__msg__ImuSensor(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: raw_acc_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_acc_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_acc_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_gyro_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_gyro_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_gyro_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_mag_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_mag_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: raw_mag_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: temp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ImuSensor__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_nandhi_msg_types__msg__ImuSensor(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ImuSensor = {
  "nandhi_msg_types::msg",
  "ImuSensor",
  _ImuSensor__cdr_serialize,
  _ImuSensor__cdr_deserialize,
  _ImuSensor__get_serialized_size,
  _ImuSensor__max_serialized_size
};

static rosidl_message_type_support_t _ImuSensor__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImuSensor,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nandhi_msg_types, msg, ImuSensor)() {
  return &_ImuSensor__type_support;
}

#if defined(__cplusplus)
}
#endif

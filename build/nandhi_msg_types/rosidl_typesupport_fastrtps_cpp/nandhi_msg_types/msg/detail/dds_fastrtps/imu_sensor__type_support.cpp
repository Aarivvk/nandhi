// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice
#include "nandhi_msg_types/msg/detail/imu_sensor__rosidl_typesupport_fastrtps_cpp.hpp"
#include "nandhi_msg_types/msg/detail/imu_sensor__struct.hpp"

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

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
cdr_serialize(
  const nandhi_msg_types::msg::ImuSensor & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: raw_acc_x
  cdr << ros_message.raw_acc_x;
  // Member: raw_acc_y
  cdr << ros_message.raw_acc_y;
  // Member: raw_acc_z
  cdr << ros_message.raw_acc_z;
  // Member: raw_gyro_x
  cdr << ros_message.raw_gyro_x;
  // Member: raw_gyro_y
  cdr << ros_message.raw_gyro_y;
  // Member: raw_gyro_z
  cdr << ros_message.raw_gyro_z;
  // Member: raw_mag_x
  cdr << ros_message.raw_mag_x;
  // Member: raw_mag_y
  cdr << ros_message.raw_mag_y;
  // Member: raw_mag_z
  cdr << ros_message.raw_mag_z;
  // Member: temp
  cdr << ros_message.temp;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nandhi_msg_types::msg::ImuSensor & ros_message)
{
  // Member: raw_acc_x
  cdr >> ros_message.raw_acc_x;

  // Member: raw_acc_y
  cdr >> ros_message.raw_acc_y;

  // Member: raw_acc_z
  cdr >> ros_message.raw_acc_z;

  // Member: raw_gyro_x
  cdr >> ros_message.raw_gyro_x;

  // Member: raw_gyro_y
  cdr >> ros_message.raw_gyro_y;

  // Member: raw_gyro_z
  cdr >> ros_message.raw_gyro_z;

  // Member: raw_mag_x
  cdr >> ros_message.raw_mag_x;

  // Member: raw_mag_y
  cdr >> ros_message.raw_mag_y;

  // Member: raw_mag_z
  cdr >> ros_message.raw_mag_z;

  // Member: temp
  cdr >> ros_message.temp;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
get_serialized_size(
  const nandhi_msg_types::msg::ImuSensor & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: raw_acc_x
  {
    size_t item_size = sizeof(ros_message.raw_acc_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_acc_y
  {
    size_t item_size = sizeof(ros_message.raw_acc_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_acc_z
  {
    size_t item_size = sizeof(ros_message.raw_acc_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_gyro_x
  {
    size_t item_size = sizeof(ros_message.raw_gyro_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_gyro_y
  {
    size_t item_size = sizeof(ros_message.raw_gyro_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_gyro_z
  {
    size_t item_size = sizeof(ros_message.raw_gyro_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_mag_x
  {
    size_t item_size = sizeof(ros_message.raw_mag_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_mag_y
  {
    size_t item_size = sizeof(ros_message.raw_mag_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: raw_mag_z
  {
    size_t item_size = sizeof(ros_message.raw_mag_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temp
  {
    size_t item_size = sizeof(ros_message.temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nandhi_msg_types
max_serialized_size_ImuSensor(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: raw_acc_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_acc_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_acc_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_gyro_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_gyro_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_gyro_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_mag_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_mag_y
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: raw_mag_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: temp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ImuSensor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const nandhi_msg_types::msg::ImuSensor *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ImuSensor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nandhi_msg_types::msg::ImuSensor *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ImuSensor__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nandhi_msg_types::msg::ImuSensor *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ImuSensor__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ImuSensor(full_bounded, 0);
}

static message_type_support_callbacks_t _ImuSensor__callbacks = {
  "nandhi_msg_types::msg",
  "ImuSensor",
  _ImuSensor__cdr_serialize,
  _ImuSensor__cdr_deserialize,
  _ImuSensor__get_serialized_size,
  _ImuSensor__max_serialized_size
};

static rosidl_message_type_support_t _ImuSensor__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ImuSensor__callbacks,
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
get_message_type_support_handle<nandhi_msg_types::msg::ImuSensor>()
{
  return &nandhi_msg_types::msg::typesupport_fastrtps_cpp::_ImuSensor__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nandhi_msg_types, msg, ImuSensor)() {
  return &nandhi_msg_types::msg::typesupport_fastrtps_cpp::_ImuSensor__handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nandhi_msg_types:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__TRAITS_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__TRAITS_HPP_

#include "nandhi_msg_types/msg/detail/orientation__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nandhi_msg_types::msg::Orientation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nandhi_msg_types::msg::Orientation & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nandhi_msg_types::msg::Orientation>()
{
  return "nandhi_msg_types::msg::Orientation";
}

template<>
inline const char * name<nandhi_msg_types::msg::Orientation>()
{
  return "nandhi_msg_types/msg/Orientation";
}

template<>
struct has_fixed_size<nandhi_msg_types::msg::Orientation>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nandhi_msg_types::msg::Orientation>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nandhi_msg_types::msg::Orientation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__ORIENTATION__TRAITS_HPP_

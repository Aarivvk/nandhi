// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice

#ifndef NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__TRAITS_HPP_
#define NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__TRAITS_HPP_

#include "nandhi_msg_types/msg/detail/ego_state__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'pose'
#include "nandhi_msg_types/msg/detail/pose__traits.hpp"
// Member 'orientation'
#include "nandhi_msg_types/msg/detail/orientation__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const nandhi_msg_types::msg::EgoState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_yaml(msg.pose, out, indentation + 2);
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation:\n";
    to_yaml(msg.orientation, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const nandhi_msg_types::msg::EgoState & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<nandhi_msg_types::msg::EgoState>()
{
  return "nandhi_msg_types::msg::EgoState";
}

template<>
inline const char * name<nandhi_msg_types::msg::EgoState>()
{
  return "nandhi_msg_types/msg/EgoState";
}

template<>
struct has_fixed_size<nandhi_msg_types::msg::EgoState>
  : std::integral_constant<bool, has_fixed_size<nandhi_msg_types::msg::Orientation>::value && has_fixed_size<nandhi_msg_types::msg::Pose>::value> {};

template<>
struct has_bounded_size<nandhi_msg_types::msg::EgoState>
  : std::integral_constant<bool, has_bounded_size<nandhi_msg_types::msg::Orientation>::value && has_bounded_size<nandhi_msg_types::msg::Pose>::value> {};

template<>
struct is_message<nandhi_msg_types::msg::EgoState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NANDHI_MSG_TYPES__MSG__DETAIL__EGO_STATE__TRAITS_HPP_

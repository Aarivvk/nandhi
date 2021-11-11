// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nandhi_msg_types:msg/Pose.idl
// generated code does not contain a copyright notice
#include "nandhi_msg_types/msg/detail/pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
nandhi_msg_types__msg__Pose__init(nandhi_msg_types__msg__Pose * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
nandhi_msg_types__msg__Pose__fini(nandhi_msg_types__msg__Pose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

nandhi_msg_types__msg__Pose *
nandhi_msg_types__msg__Pose__create()
{
  nandhi_msg_types__msg__Pose * msg = (nandhi_msg_types__msg__Pose *)malloc(sizeof(nandhi_msg_types__msg__Pose));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nandhi_msg_types__msg__Pose));
  bool success = nandhi_msg_types__msg__Pose__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
nandhi_msg_types__msg__Pose__destroy(nandhi_msg_types__msg__Pose * msg)
{
  if (msg) {
    nandhi_msg_types__msg__Pose__fini(msg);
  }
  free(msg);
}


bool
nandhi_msg_types__msg__Pose__Sequence__init(nandhi_msg_types__msg__Pose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  nandhi_msg_types__msg__Pose * data = NULL;
  if (size) {
    data = (nandhi_msg_types__msg__Pose *)calloc(size, sizeof(nandhi_msg_types__msg__Pose));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nandhi_msg_types__msg__Pose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nandhi_msg_types__msg__Pose__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
nandhi_msg_types__msg__Pose__Sequence__fini(nandhi_msg_types__msg__Pose__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nandhi_msg_types__msg__Pose__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

nandhi_msg_types__msg__Pose__Sequence *
nandhi_msg_types__msg__Pose__Sequence__create(size_t size)
{
  nandhi_msg_types__msg__Pose__Sequence * array = (nandhi_msg_types__msg__Pose__Sequence *)malloc(sizeof(nandhi_msg_types__msg__Pose__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = nandhi_msg_types__msg__Pose__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
nandhi_msg_types__msg__Pose__Sequence__destroy(nandhi_msg_types__msg__Pose__Sequence * array)
{
  if (array) {
    nandhi_msg_types__msg__Pose__Sequence__fini(array);
  }
  free(array);
}

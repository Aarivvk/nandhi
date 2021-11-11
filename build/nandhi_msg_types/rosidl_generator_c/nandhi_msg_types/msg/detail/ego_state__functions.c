// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nandhi_msg_types:msg/EgoState.idl
// generated code does not contain a copyright notice
#include "nandhi_msg_types/msg/detail/ego_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `pose`
#include "nandhi_msg_types/msg/detail/pose__functions.h"
// Member `orientation`
#include "nandhi_msg_types/msg/detail/orientation__functions.h"

bool
nandhi_msg_types__msg__EgoState__init(nandhi_msg_types__msg__EgoState * msg)
{
  if (!msg) {
    return false;
  }
  // pose
  if (!nandhi_msg_types__msg__Pose__init(&msg->pose)) {
    nandhi_msg_types__msg__EgoState__fini(msg);
    return false;
  }
  // orientation
  if (!nandhi_msg_types__msg__Orientation__init(&msg->orientation)) {
    nandhi_msg_types__msg__EgoState__fini(msg);
    return false;
  }
  return true;
}

void
nandhi_msg_types__msg__EgoState__fini(nandhi_msg_types__msg__EgoState * msg)
{
  if (!msg) {
    return;
  }
  // pose
  nandhi_msg_types__msg__Pose__fini(&msg->pose);
  // orientation
  nandhi_msg_types__msg__Orientation__fini(&msg->orientation);
}

nandhi_msg_types__msg__EgoState *
nandhi_msg_types__msg__EgoState__create()
{
  nandhi_msg_types__msg__EgoState * msg = (nandhi_msg_types__msg__EgoState *)malloc(sizeof(nandhi_msg_types__msg__EgoState));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nandhi_msg_types__msg__EgoState));
  bool success = nandhi_msg_types__msg__EgoState__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
nandhi_msg_types__msg__EgoState__destroy(nandhi_msg_types__msg__EgoState * msg)
{
  if (msg) {
    nandhi_msg_types__msg__EgoState__fini(msg);
  }
  free(msg);
}


bool
nandhi_msg_types__msg__EgoState__Sequence__init(nandhi_msg_types__msg__EgoState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  nandhi_msg_types__msg__EgoState * data = NULL;
  if (size) {
    data = (nandhi_msg_types__msg__EgoState *)calloc(size, sizeof(nandhi_msg_types__msg__EgoState));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nandhi_msg_types__msg__EgoState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nandhi_msg_types__msg__EgoState__fini(&data[i - 1]);
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
nandhi_msg_types__msg__EgoState__Sequence__fini(nandhi_msg_types__msg__EgoState__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nandhi_msg_types__msg__EgoState__fini(&array->data[i]);
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

nandhi_msg_types__msg__EgoState__Sequence *
nandhi_msg_types__msg__EgoState__Sequence__create(size_t size)
{
  nandhi_msg_types__msg__EgoState__Sequence * array = (nandhi_msg_types__msg__EgoState__Sequence *)malloc(sizeof(nandhi_msg_types__msg__EgoState__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = nandhi_msg_types__msg__EgoState__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
nandhi_msg_types__msg__EgoState__Sequence__destroy(nandhi_msg_types__msg__EgoState__Sequence * array)
{
  if (array) {
    nandhi_msg_types__msg__EgoState__Sequence__fini(array);
  }
  free(array);
}

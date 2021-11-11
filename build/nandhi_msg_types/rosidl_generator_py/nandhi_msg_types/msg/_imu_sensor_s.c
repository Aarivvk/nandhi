// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nandhi_msg_types:msg/ImuSensor.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "nandhi_msg_types/msg/detail/imu_sensor__struct.h"
#include "nandhi_msg_types/msg/detail/imu_sensor__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool nandhi_msg_types__msg__imu_sensor__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("nandhi_msg_types.msg._imu_sensor.ImuSensor", full_classname_dest, 42) == 0);
  }
  nandhi_msg_types__msg__ImuSensor * ros_message = _ros_message;
  {  // raw_acc_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_acc_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_acc_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_acc_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_acc_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_acc_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_acc_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_acc_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_acc_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_gyro_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_gyro_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_gyro_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_gyro_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_gyro_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_gyro_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_gyro_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_gyro_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_gyro_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_mag_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_mag_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_mag_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_mag_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_mag_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_mag_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // raw_mag_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "raw_mag_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->raw_mag_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temp
    PyObject * field = PyObject_GetAttrString(_pymsg, "temp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temp = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nandhi_msg_types__msg__imu_sensor__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ImuSensor */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nandhi_msg_types.msg._imu_sensor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ImuSensor");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nandhi_msg_types__msg__ImuSensor * ros_message = (nandhi_msg_types__msg__ImuSensor *)raw_ros_message;
  {  // raw_acc_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_acc_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_acc_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_acc_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_acc_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_acc_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_acc_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_acc_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_acc_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_gyro_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_gyro_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_gyro_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_gyro_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_gyro_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_gyro_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_gyro_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_gyro_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_gyro_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_mag_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_mag_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_mag_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_mag_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_mag_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_mag_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // raw_mag_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->raw_mag_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "raw_mag_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

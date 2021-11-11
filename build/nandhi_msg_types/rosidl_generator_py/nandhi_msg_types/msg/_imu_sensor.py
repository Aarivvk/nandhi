# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nandhi_msg_types:msg/ImuSensor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ImuSensor(type):
    """Metaclass of message 'ImuSensor'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nandhi_msg_types')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nandhi_msg_types.msg.ImuSensor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__imu_sensor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__imu_sensor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__imu_sensor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__imu_sensor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__imu_sensor

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ImuSensor(metaclass=Metaclass_ImuSensor):
    """Message class 'ImuSensor'."""

    __slots__ = [
        '_raw_acc_x',
        '_raw_acc_y',
        '_raw_acc_z',
        '_raw_gyro_x',
        '_raw_gyro_y',
        '_raw_gyro_z',
        '_raw_mag_x',
        '_raw_mag_y',
        '_raw_mag_z',
        '_temp',
    ]

    _fields_and_field_types = {
        'raw_acc_x': 'double',
        'raw_acc_y': 'double',
        'raw_acc_z': 'double',
        'raw_gyro_x': 'double',
        'raw_gyro_y': 'double',
        'raw_gyro_z': 'double',
        'raw_mag_x': 'double',
        'raw_mag_y': 'double',
        'raw_mag_z': 'double',
        'temp': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.raw_acc_x = kwargs.get('raw_acc_x', float())
        self.raw_acc_y = kwargs.get('raw_acc_y', float())
        self.raw_acc_z = kwargs.get('raw_acc_z', float())
        self.raw_gyro_x = kwargs.get('raw_gyro_x', float())
        self.raw_gyro_y = kwargs.get('raw_gyro_y', float())
        self.raw_gyro_z = kwargs.get('raw_gyro_z', float())
        self.raw_mag_x = kwargs.get('raw_mag_x', float())
        self.raw_mag_y = kwargs.get('raw_mag_y', float())
        self.raw_mag_z = kwargs.get('raw_mag_z', float())
        self.temp = kwargs.get('temp', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.raw_acc_x != other.raw_acc_x:
            return False
        if self.raw_acc_y != other.raw_acc_y:
            return False
        if self.raw_acc_z != other.raw_acc_z:
            return False
        if self.raw_gyro_x != other.raw_gyro_x:
            return False
        if self.raw_gyro_y != other.raw_gyro_y:
            return False
        if self.raw_gyro_z != other.raw_gyro_z:
            return False
        if self.raw_mag_x != other.raw_mag_x:
            return False
        if self.raw_mag_y != other.raw_mag_y:
            return False
        if self.raw_mag_z != other.raw_mag_z:
            return False
        if self.temp != other.temp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def raw_acc_x(self):
        """Message field 'raw_acc_x'."""
        return self._raw_acc_x

    @raw_acc_x.setter
    def raw_acc_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_acc_x' field must be of type 'float'"
        self._raw_acc_x = value

    @property
    def raw_acc_y(self):
        """Message field 'raw_acc_y'."""
        return self._raw_acc_y

    @raw_acc_y.setter
    def raw_acc_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_acc_y' field must be of type 'float'"
        self._raw_acc_y = value

    @property
    def raw_acc_z(self):
        """Message field 'raw_acc_z'."""
        return self._raw_acc_z

    @raw_acc_z.setter
    def raw_acc_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_acc_z' field must be of type 'float'"
        self._raw_acc_z = value

    @property
    def raw_gyro_x(self):
        """Message field 'raw_gyro_x'."""
        return self._raw_gyro_x

    @raw_gyro_x.setter
    def raw_gyro_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_gyro_x' field must be of type 'float'"
        self._raw_gyro_x = value

    @property
    def raw_gyro_y(self):
        """Message field 'raw_gyro_y'."""
        return self._raw_gyro_y

    @raw_gyro_y.setter
    def raw_gyro_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_gyro_y' field must be of type 'float'"
        self._raw_gyro_y = value

    @property
    def raw_gyro_z(self):
        """Message field 'raw_gyro_z'."""
        return self._raw_gyro_z

    @raw_gyro_z.setter
    def raw_gyro_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_gyro_z' field must be of type 'float'"
        self._raw_gyro_z = value

    @property
    def raw_mag_x(self):
        """Message field 'raw_mag_x'."""
        return self._raw_mag_x

    @raw_mag_x.setter
    def raw_mag_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_mag_x' field must be of type 'float'"
        self._raw_mag_x = value

    @property
    def raw_mag_y(self):
        """Message field 'raw_mag_y'."""
        return self._raw_mag_y

    @raw_mag_y.setter
    def raw_mag_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_mag_y' field must be of type 'float'"
        self._raw_mag_y = value

    @property
    def raw_mag_z(self):
        """Message field 'raw_mag_z'."""
        return self._raw_mag_z

    @raw_mag_z.setter
    def raw_mag_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'raw_mag_z' field must be of type 'float'"
        self._raw_mag_z = value

    @property
    def temp(self):
        """Message field 'temp'."""
        return self._temp

    @temp.setter
    def temp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temp' field must be of type 'float'"
        self._temp = value

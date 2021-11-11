# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nandhi_msg_types:msg/EgoState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EgoState(type):
    """Metaclass of message 'EgoState'."""

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
                'nandhi_msg_types.msg.EgoState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ego_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ego_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ego_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ego_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ego_state

            from nandhi_msg_types.msg import Orientation
            if Orientation.__class__._TYPE_SUPPORT is None:
                Orientation.__class__.__import_type_support__()

            from nandhi_msg_types.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EgoState(metaclass=Metaclass_EgoState):
    """Message class 'EgoState'."""

    __slots__ = [
        '_pose',
        '_orientation',
    ]

    _fields_and_field_types = {
        'pose': 'nandhi_msg_types/Pose',
        'orientation': 'nandhi_msg_types/Orientation',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['nandhi_msg_types', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nandhi_msg_types', 'msg'], 'Orientation'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from nandhi_msg_types.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        from nandhi_msg_types.msg import Orientation
        self.orientation = kwargs.get('orientation', Orientation())

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
        if self.pose != other.pose:
            return False
        if self.orientation != other.orientation:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from nandhi_msg_types.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if __debug__:
            from nandhi_msg_types.msg import Orientation
            assert \
                isinstance(value, Orientation), \
                "The 'orientation' field must be a sub message of type 'Orientation'"
        self._orientation = value

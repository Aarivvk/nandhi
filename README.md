# Nandhi

Autonomus vehicle(1:10) from scratch.

I am building an hobby vehicle with expectations to create a platfor to kick start the real life ML algorithums in action like Reinforcement learning.

I am aproching this task in below Phases fasion.

### Phase I: (System)

1. Hardware integration

- Assemble the Vehicle:
  - Chassi
  - Battery
  - Vehicle contorller unit
  - IMU sensor, 2D Lidar and a Camera
  - HPC (Nvidia AGX Xavior)

2. Wiring it up
3. Power mangement (may be Ardino or I2C/USB device)

- Check the power riqierments
- Monitor the power consumsion
- Reposrt batery status and abnormalities

#### Phase II: (Simulation)
1. Gazebo simulation
2. 4wd ackerman steering
3. Lidar
4. camera
5. Ros bridge
6. RVIZ

#### Phase III: (Software)

1. Basic Vehicle drivers ROS2 nodes

- Ego/Vehicle state node
- YDLidar ROS2 node (using as is)
- IMU sensor node
- I2C wrapper for easy use
- Vehicle Controler node
- Keyboard listener node
- Vehicle vizualisation node

2. Bring-up the perception

- Digital environment (2D Lidar + camera)
- Vehicle state position and orientation(IMU + camera + Lidar).

3. The Driver

- Vehicle pannnig and Behaviour

  This is work in progress, Phase I.2 and Phase II.1 is complete.
  #TODO: Add picture/video of curent state and discribe it more.


## Launch Nandhi

To launch simulation

```bash
# Shel A
source install/setup.bash
ros2 launch nandhi_sim_launch nandhi_sim.launch.py
```

```bash
# Shel B
# To make robot move
ros2 topic pub /nandhi/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 5.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: -0.22}}"
# OR
./install/key_to_twist/lib/key_to_twist/key_to_twist
```

To listen the Twist value run below binary

```bash
# Shell C
./build/key_to_twist/key_to_twist_test
```


## Nandhi constants

**Maximum Linear Velocity**

Maximu speed: 50 k/h
Wheel Diameter: 0.1 m

max_linear_velocity = 13.89 m/s

**Maximum Angular Velocity**
wheel base W: 0.29 m

max_angular_velocity = max_linear_velocity/W
max_angular_velocity = 47.9 rad/s

- 8500 rpm
- (L x W x H) 532 x 290 x 195 mm

[Vehicle link](https://www.conrad.de/de/p/reely-eraser-brushless-1-10-rc-modellauto-elektro-short-course-allradantrieb-4wd-100-rtr-2-4-ghz-inkl-akku-ladeger-1976297.html#productTechData)


## Help full commands

Step through the gazebo server

```bash
ros2 service call /ros_gz_rl nandhi_msg_types/srv/GetObservations "{step: true, multi_step: 500}"
```

Move the robot
```bash
gz topic -t "/model/nandhi/cmd_vel" -m gz.msgs.Twist -p "linear: {x: 0.5}, angular: {z: 0.1}"
# OR
ros2 topic pub /nandhi/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.5}}"
```
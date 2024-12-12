
# Nandhi: Autonomous Vehicle

I am building a hobby autonomous vehicle (of 1:10 scale) to serve as a platform for implementing real-world Machine Learning algorithms, including Reinforcement Learning.

This project is divided into several phases, each focused on different aspects of the system:

## Project Phases Overview

### Phase I: System Setup and Hardware Integration

1. **Hardware Integration**
   - Assemble the Vehicle:
     - Chassis
     - Battery
     - Vehicle controller unit
     - IMU sensor, 2D LiDAR, and a camera
     - High-Performance Computer (HPC) — Nvidia AGX Xavier

2. **Wiring and Connectivity**
   - Connect all components for data and power transmission.

3. **Power Management**
   - Power management via Arduino or I2C/USB device:
     - Check power requirements.
     - Monitor power consumption.
     - Report battery status and detect abnormalities.

### Phase II: Simulation Environment

1. **Gazebo Simulation Setup**
   - Simulate the vehicle in a controlled environment.

2. **4WD Ackerman Steering**
   - Implement four-wheel-drive steering with Ackerman geometry.

3. **Sensors Simulation**
   - Simulate sensors including LiDAR and camera.

4. **ROS Integration**
   - ROS Bridge integration for connecting Gazebo to ROS.

5. **Visualization with RViz**
   - Visualize the vehicle and environment in RViz.

### Phase III: Software Development

1. **ROS2 Nodes for Vehicle Drivers**
   - Develop ROS2 nodes for vehicle control:
     - Ego/Vehicle State Node
     - YDLidar ROS2 Node (using pre-existing implementations)
     - IMU Sensor Node
     - I2C Wrapper Node (for easy I2C integration)
     - Vehicle Controller Node
     - Keyboard Listener Node (for manual control)
     - Vehicle Visualization Node (for RViz)

2. **Perception System**
   - Implement perception using:
     - Digital environment data from 2D LiDAR and camera.
     - Vehicle state estimation for position and orientation using IMU, camera, and LiDAR data.

3. **Vehicle Planning and Behavior**
   - Develop vehicle planning and behavior control (in progress).

_Current Progress: Phase I.2 and Phase II.1 are complete._  
**TODO**: Add a picture/video of the current progress and describe it in more detail.

---

## How to Launch Nandhi

### Simulation Setup

To launch the simulation environment:

1. In the first terminal (Shell A):

   ```bash
   source install/setup.bash
   ros2 launch nandhi_sim_launch nandhi_sim.launch.py
   ```

2. To make the robot move, open a second terminal (Shell B) and use one of the following options:
   - Using ROS2 topic publishing:

     ```bash
     ros2 topic pub /nandhi/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 5.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: -0.22}}"
     ```

   - Using the keyboard control node:

     ```bash
     ./install/key_to_twist/lib/key_to_twist/key_to_twist
     ```

3. To listen to the Twist value, open a third terminal (Shell C) and run the test binary:

   ```bash
   ./build/key_to_twist/key_to_twist_test
   ```

---

## Nandhi Constants and Vehicle Specifications

### Maximum Linear Velocity

- Maximum speed: $50 \ \text{km/h}$
- Wheel Diameter: $0.1 \ \text{m}$

$$
\text{max linear velocity} = 13.89 \ \text{m/s}
$$

### Maximum Angular Velocity

- Wheel base $W = 0.29 \ \text{m}$

$$
\text{max angular velocity} = \frac{\text{max linear velocity}}{W} = 47.9 \ \text{rad/s}
$$

### RPM and Dimensions

- 8500 RPM
- Dimensions: $(L \times W \times H) = 532 \times 290 \times 195 \ \text{mm}$

- [Vehicle Link](https://www.conrad.de/de/p/reely-eraser-brushless-1-10-rc-modellauto-elektro-short-course-allradantrieb-4wd-100-rtr-2-4-ghz-inkl-akku-ladeger-1976297.html#productTechData)

---

## Helpful Commands with gazebo simulation with ros2 bridge

### Setup the environment

```bash
# To enable the local models
# TODO: add it in the launch file
export GZ_SIM_RESOURCE_PATH=~/project/ros_ws/src/nandhi/simulation/nandhi_description/models/:$GZ_SIM_RESOURCE_PATH
# For gazebo plugins shared library, from root of colcon workspace
export GZ_SIM_SYSTEM_PLUGIN_PATH=`pwd`/build/distance
# This need for remote desktop, where the display server is set to 10
export DISPLAY=:10.0
```

### Step Through the Gazebo Server

```bash
ros2 service call /ros_gz_rl nandhi_msg_types/srv/GetObservations "{step: true, multi_step: 500}"
```

### Move the Robot

```bash
gz topic -t "/model/nandhi/cmd_vel" -m gz.msgs.Twist -p "linear: {x: 0.5}, angular: {z: 0.1}"
# OR
ros2 topic pub /nandhi/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.5}}"
```

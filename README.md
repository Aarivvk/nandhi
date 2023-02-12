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

#### Phase II: (Software)
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
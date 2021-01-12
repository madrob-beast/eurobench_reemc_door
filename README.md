# reemc_door
This repository contains the simulation files for the E10 - Open the door episode for the 1st SciRoc Challenge.
For more information please refer to [this website](https://sites.google.com/view/e10-open-the-door/home).
## Installation
### Prerequisites:
- Ubuntu 16.04  (Xenial Xerus).
- ROS kinetic kame.
- Gazebo 7.x updated to the last version.
- Git
- [REEM-C Simulator](http://wiki.ros.org/Robots/REEM-C/Tutorials/Installation/Simulation)



### Installation:

- Open a terminal and go to the src folder in the reem-c workspace: 
```
cd ~/reemc_public_ws/src
```
- Clone the challenge environments.
```
git clone https://github.com/JoseJaramillo/reemc_door
```
- Build the workspace.
```
cd ..
catkin build -DCATKIN_ENABLE_TESTING=0
```
If the installation was successful, the terminal will show that All packages succeeded!. 

## Usage

- Source the workspace.
```
source ~/reemc_public_ws/devel/setup.bash
```
- Launch the environments.
```
roslaunch reemc_door reemc_door.launch door:=simple
```
This will launch a Gazebo world with the REEM-C robot and a simple door. 
To launch the environments in different scenarios:
```
roslaunch reemc_door reemc_door.launch door:=simple
roslaunch reemc_door reemc_door.launch door:=self_closing
roslaunch reemc_door reemc_door.launch door:=hard_obstacle
roslaunch reemc_door reemc_door.launch door:=soft_obstacle
roslaunch reemc_door reemc_door.launch door:=wind
```
Where:
- simple: standard door, it won't close if the robot does not push it.
- self_closing: the door will act as if has self-closing hinges.
- hard_obstacle: A small obstacle will appear behind the door, the robot should push the door harder to overcome this obstacle.
- soft_obstacle: a big box will appear behind the door, this obstacle can be moved and the robot should push harder to move it away.
- wind: A wind draft which pushes the door against the robot is simulated. 

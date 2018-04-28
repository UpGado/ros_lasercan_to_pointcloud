# ros_laserscan_to_pointcloud
A ROS package that listens to a *sensor_msgs/LaserScan*, converts the data into *sensor_msgs/PointCloud2* type, and publishes it to a new topic.

## Installation from Source

This will install the package from source. If you have a fork of the repository, use the URL for your fork instead (or add it later with `git remote`.)

```bash
# clone
cd catkin_ws/src
git clone https://github.com/UpGado/ros_lasercan_to_pointcloud.git 

# build
cd ~/catkin_ws
catkin_make
```

## Usage
Run the following command on a separate terminal instance.
```bash
rosrun laserscan_to_pointcloud laserscan_to_pointcloud_node
```

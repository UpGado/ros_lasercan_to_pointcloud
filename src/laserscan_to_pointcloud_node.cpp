#include "ros/ros.h"
#include "tf/transform_listener.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/PointCloud2.h"
#include <laser_geometry/laser_geometry.h>

ros::Publisher pointcloud_publisher;
laser_geometry::LaserProjection projector;
tf::TransformListener *tfListener = NULL;

void laserscanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  ROS_INFO("Received something! Ahmed is the coolest kid ever");
  sensor_msgs::PointCloud2 cloud;
  projector.transformLaserScanToPointCloud("base_link", *msg, cloud, *tfListener);
  pointcloud_publisher.publish(cloud);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "laserscan_to_pointcloud_node");

  ros::NodeHandle n;

  tfListener = new tf::TransformListener();
  tfListener->setExtrapolationLimit(ros::Duration(10));

  ros::Subscriber sub = n.subscribe("scan", 1000, laserscanCallback);
   
  pointcloud_publisher = n.advertise<sensor_msgs::PointCloud2> ("/laserscan_to_pointcloud", 100, false);
  
  ros::spin();

  return 0;
}

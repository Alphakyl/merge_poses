#include "ros/ros.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/Pose.h"
#include "nav_msgs/Odometry.h"

using namespace std;

geometry_msgs::Pose pose1;
geometry_msgs::Pose pose2;
geometry_msgs::Pose pose3;

void odom1Cb(const nav_msgs::Odometry&);
void odom2Cb(const nav_msgs::Odometry&);
void odom3Cb(const nav_msgs::Odometry&);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "merge_poses_node");

  ros::NodeHandle nh;

  ros::Publisher poseArrayPub = nh.advertise<geometry_msgs::PoseArray>("merged_poses", 1000);
  ros::Subscriber odom1Sub = nh.subscribe("odom1", 1000, odom1Cb);
  ros::Subscriber odom2Sub = nh.subscribe("odom2", 1000, odom2Cb);
  ros::Subscriber odom3Sub = nh.subscribe("odom3", 1000, odom3Cb);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    geometry_msgs::PoseArray poseArrayMsg;

    poseArrayMsg.header.stamp = ros::Time::now();
    poseArrayMsg.poses.push_back(pose1);
    poseArrayMsg.poses.push_back(pose2);
    poseArrayMsg.poses.push_back(pose3);

    poseArrayPub.publish(poseArrayMsg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}

void odom1Cb(const nav_msgs::Odometry& msg)
{
pose1 = msg.pose.pose;
}

void odom2Cb(const nav_msgs::Odometry& msg)
{
pose2 = msg.pose.pose;
}

void odom3Cb(const nav_msgs::Odometry& msg)
{
pose3 = msg.pose.pose;
}

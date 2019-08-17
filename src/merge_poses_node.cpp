#include "ros/ros.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/Pose.h"
#include "nav_msgs/Odometry.h"

using namespace std;

geometry_msgs::Pose pose[10];
bool is_initialized[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void odom0Cb(const nav_msgs::Odometry&);
void odom1Cb(const nav_msgs::Odometry&);
void odom2Cb(const nav_msgs::Odometry&);
void odom3Cb(const nav_msgs::Odometry&);
void odom4Cb(const nav_msgs::Odometry&);
void odom5Cb(const nav_msgs::Odometry&);
void odom6Cb(const nav_msgs::Odometry&);
void odom7Cb(const nav_msgs::Odometry&);
void odom8Cb(const nav_msgs::Odometry&);
void odom9Cb(const nav_msgs::Odometry&);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "merge_poses_node");

  ros::NodeHandle nh;

  ros::Publisher poseArrayPub = nh.advertise<geometry_msgs::PoseArray>("merged_poses", 100);

  ros::Subscriber odom0Sub = nh.subscribe("odom0", 10, odom0Cb);
  ros::Subscriber odom1Sub = nh.subscribe("odom1", 10, odom1Cb);
  ros::Subscriber odom2Sub = nh.subscribe("odom2", 10, odom2Cb);
  ros::Subscriber odom3Sub = nh.subscribe("odom3", 10, odom3Cb);
  ros::Subscriber odom4Sub = nh.subscribe("odom4", 10, odom4Cb);
  ros::Subscriber odom5Sub = nh.subscribe("odom5", 10, odom5Cb);
  ros::Subscriber odom6Sub = nh.subscribe("odom6", 10, odom6Cb);
  ros::Subscriber odom7Sub = nh.subscribe("odom7", 10, odom7Cb);
  ros::Subscriber odom8Sub = nh.subscribe("odom8", 10, odom8Cb);
  ros::Subscriber odom9Sub = nh.subscribe("odom9", 10, odom9Cb);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    geometry_msgs::PoseArray poseArrayMsg;

    poseArrayMsg.header.stamp = ros::Time::now();
    poseArrayMsg.header.frame_id = "world";

    for (int i = 0; i < 10; i++)
    {
      if(is_initialized[i])
      poseArrayMsg.poses.push_back(pose[i]);
    }

    poseArrayPub.publish(poseArrayMsg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}

void odom0Cb(const nav_msgs::Odometry& msg)
{
pose[0] = msg.pose.pose;
is_initialized[0] = 1;
}

void odom1Cb(const nav_msgs::Odometry& msg)
{
pose[1] = msg.pose.pose;
is_initialized[1] = 1;
}

void odom2Cb(const nav_msgs::Odometry& msg)
{
pose[2] = msg.pose.pose;
is_initialized[2] = 1;
}

void odom3Cb(const nav_msgs::Odometry& msg)
{
pose[3] = msg.pose.pose;
is_initialized[3] = 1;
}

void odom4Cb(const nav_msgs::Odometry& msg)
{
pose[4] = msg.pose.pose;
is_initialized[4] = 1;
}

void odom5Cb(const nav_msgs::Odometry& msg)
{
pose[5] = msg.pose.pose;
is_initialized[5] = 1;
}

void odom6Cb(const nav_msgs::Odometry& msg)
{
pose[6] = msg.pose.pose;
is_initialized[6] = 1;
}

void odom7Cb(const nav_msgs::Odometry& msg)
{
pose[7] = msg.pose.pose;
is_initialized[7] = 1;
}

void odom8Cb(const nav_msgs::Odometry& msg)
{
pose[8] = msg.pose.pose;
is_initialized[8] = 1;
}

void odom9Cb(const nav_msgs::Odometry& msg)
{
pose[9] = msg.pose.pose;
is_initialized[9] = 1;
}

#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist, PoseWithCovarianceStamped

def move_and_set_pose():
    rospy.init_node('move_and_set_pose', anonymous=True)
    vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    pose_pub = rospy.Publisher('/amcl_pose', PoseWithCovarianceStamped, queue_size=10)

    # Move forward for 1 meter
    vel_msg = Twist()
    vel_msg.linear.x = 0.2  # meters per second
    t0 = rospy.Time.now().to_sec()
    current_dist = 0
    while current_dist < 1.0:
        vel_pub.publish(vel_msg)
        t1 = rospy.Time.now().to_sec()
        current_dist = 0.2 * (t1 - t0)
    vel_msg.linear.x = 0  # stop moving
    vel_pub.publish(vel_msg)

    # Set the robot pose to (2, 0, 0)
    pose_msg = PoseWithCovarianceStamped()
    pose_msg.header.frame_id = 'map'
    pose_msg.header.stamp = rospy.Time.now()
    pose_msg.pose.pose.position.x = 2
    pose_msg.pose.pose.position.y = 0
    pose_msg.pose.pose.position.z = 0
    pose_msg.pose.pose.orientation.x = 0
    pose_msg.pose.pose.orientation.y = 0
    pose_msg.pose.pose.orientation.z = 0
    pose_msg.pose.pose.orientation.w = 1
    pose_pub.publish(pose_msg)

if __name__ == '__main__':
    try:
        move_and_set_pose()
    except rospy.ROSInterruptException:
        pass


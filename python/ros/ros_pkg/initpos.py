#!/usr/bin/env python

import tf
import rospy
import time
from geometry_msgs.msg import PoseWithCovarianceStamped

def initPos():
    global pub
    pub = rospy.Publisher('/initialpose', PoseWithCovarianceStamped, queue_size=10)
    pose_pub = rospy.Publisher('/amcl_pose', PoseWithCovarianceStamped, queue_size=10)
    listener = tf.TransformListener() 
    pose_msg = PoseWithCovarianceStamped()
    pose_msg.header.frame_id = 'map'
    pose_msg.header.stamp = rospy.Time.now()
    pose_msg.pose.pose.position.x = 0
    pose_msg.pose.pose.position.y = 0
    pose_msg.pose.pose.position.z = 0
    pose_msg.pose.pose.orientation.x = 0
    pose_msg.pose.pose.orientation.y = 0
    pose_msg.pose.pose.orientation.z = 0
    pose_msg.pose.pose.orientation.w = 1

    pose_pub.publish(pose_msg)
    start_time = time.time()
    while time.time() - start_time <= 5 :
        pub.publish(pose_msg)

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        try:
            (trans,rot) = listener.lookupTransform('map', 'base_link', rospy.Time(0)) 
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            continue

        pose_msg = PoseWithCovarianceStamped()
        pose_msg.header.frame_id = 'map'
        x,y,z = trans[0], trans[1], trans[2]
        
        pose_msg.pose.pose.position.x = x
        pose_msg.pose.pose.position.y = y
        pose_msg.pose.pose.position.z = z
        x,y,z, w = rot[0], rot[1], rot[2], rot[3]
        pose_msg.pose.pose.orientation.x = x
        pose_msg.pose.pose.orientation.y = y
        pose_msg.pose.pose.orientation.z = z
        pose_msg.pose.pose.orientation.w = w

        pub.publish(pose_msg)

        time.sleep(1)

if __name__ == '__main__':
    rospy.init_node("initpos")
    initPos()
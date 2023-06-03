#_*_coding:UTF-8_*_

import rospy
import tf
import time

if __name__ == '__main__':
    rospy.init_node('turtle_tf_listener') 

    listener = tf.TransformListener() 
    while not rospy.is_shutdown(): 
        a = input()
        try:
            (trans,rot) = listener.lookupTransform('map', 'base_link', rospy.Time(0)) 
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException): 
            continue
        print('position',trans) 
        print('orient',rot) 
        x,y,z = trans[0], trans[1], trans[2]
        x_,y_,z_, w = rot[0], rot[1], rot[2], rot[3]
        # print("pose_msg.header.frame_id = 'map'")
        # print("pose_msg.pose.position.x = {}".format(x))
        # print("pose_msg.pose.position.y = {}".format(y))
        # print("pose_msg.pose.position.z = {}".format(z))
        # print("pose_msg.pose.orientation.x = {}".format(x_))
        # print("pose_msg.pose.orientation.y = {}".format(y_))
        # print("pose_msg.pose.orientation.z = {}".format(z_))
        # print("pose_msg.pose.orientation.w = {}".format(w))
        print("{}, {}, {}, {}, {}, {}, {}".format(x,y,z, x_,y_, z_, w))

        

import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from geometry_msgs.msg import Pose, Point, Quaternion

def move(distance):
    rospy.init_node('move_base_test', anonymous=True)

    client = actionlib.SimpleActionClient('move_base', MoveBaseAction)
    client.wait_for_server()

    goal = MoveBaseGoal()

    goal.target_pose.header.frame_id = 'map'
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.pose.position.x = distance
    goal.target_pose.pose.orientation.w = 1.0

    client.send_goal(goal)
    client.wait_for_result()
if __name__ == '__main__':
    try:
        move(1) 
    except rospy.ROSInterruptException:
        pass

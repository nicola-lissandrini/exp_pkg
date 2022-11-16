#!/usr/bin/env python

import signal
import rospy
import numpy as np

from geometry_msgs.msg import Pose
import matplotlib.pyplot as plt

target_pose = Pose ()
target_pose.position.x = 1.5
target_pose.position.y = 0.
target_pose.orientation.w = 1

class TargetNode:
    def __init__ (self):
        rospy.init_node ("target_node")

        self.target_pub = rospy.Publisher (rospy.get_param("/target/target_pub"), Pose, queue_size=1)
        self.rate = rospy.Rate (rospy.get_param ("/target/rate"))

    def spin (self):
        while not rospy.is_shutdown ():
            self.target_pub.publish (target_pose)
            self.rate.sleep ()

if __name__ == "__main__":
    try:
        tn = TargetNode ()
        tn.spin ()
    except rospy.ROSInterruptException:
        pass
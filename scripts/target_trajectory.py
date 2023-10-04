#!/usr/bin/env python

import rospy
import signal 


class TargetTrajectoryNode:
    def __init__ (self):
        rospy.init_node ("target_trajectory")

        self.time_zero = None 
        
        self.trajectory_waypoints = rospy.get_param ("/target/trajectory")
        self.timer = None
        self.timer_period = 1./rospy.get_param ("/target/rate")

    def start (self):
        self.timer = rospy.Timer (rospy.Duration(self.timer_period), self.timer_callback)
        self.time_zero = rospy.Time.now ()

    def elapsed (self):
        if (self.time_zero is None):
            raise RuntimeError ()
        return (rospy.Time.now () - self.time_zero).to_sec ()

    def timer_callback (self, event):
        print (self.elapsed ())


    def spin (self):
        rospy.spin ()


def signal_handler (sig, frame):
    quit ()


if __name__ == "__main__":
    try:
        signal.signal (signal.SIGINT, signal_handler)
        ttn = TargetTrajectoryNode ()
        ttn.start ()
        ttn.spin ()
    except rospy.ROSInterruptException:
        pass
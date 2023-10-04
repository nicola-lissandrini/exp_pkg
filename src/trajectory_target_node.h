#ifndef TRAJECTORYTARGETNODE_H
#define TRAJECTORYTARGETNODE_H

#include <ros/ros.h>

#include "trajectory_target.h"


class TrajectoryTargetNode
{
public:
	TrajectoryTargetNode(int argc, char *argv[], const std::string &name);

	void timerCallback (const ros::TimerEvent &event);
	int spin ();

private:
	ros::Publisher _trajectoryPub;
	ros::Timer _timer;

	TrajectoryTarget _trajectoryTarget;
};

#endif // TRAJECTORYTARGETNODE_H

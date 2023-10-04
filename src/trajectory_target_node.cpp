#include "trajectory_target_node.h"
#include <geometry_msgs/PoseStamped.h>
#include <ros/package.h>

using namespace std;


TrajectoryTargetNode::TrajectoryTargetNode (int argc, char *argv[], const std::string &name)
{
	ros::init (argc, argv, name);
	ros::NodeHandle nh;

	_trajectoryPub = nh.advertise<geometry_msgs::PoseStamped> ("/trajectory_target", 1);
	_timer = nh.createTimer (ros::Duration (0.1), &TrajectoryTargetNode::timerCallback, this);

	std::string filename;
	nh.getParam ("/target_trajectory/trajectory_filename", filename);

	_trajectoryTarget.loadTrajectory (filename);
	_trajectoryTarget.start ();
}

void TrajectoryTargetNode::timerCallback (const ros::TimerEvent &event)
{
	geometry_msgs::PoseStamped poseMsg;

	TrajectoryTarget::Pose current = _trajectoryTarget.getCurrent ();

	COUTN(current);


	poseMsg.header.stamp = ros::Time::now (); // different from the actual trajectory stamp... whatever
	poseMsg.pose.position.x = current[0];
	poseMsg.pose.position.x = current[1];
	poseMsg.pose.position.x = current[2];
	poseMsg.pose.orientation.w = current[3];

	_trajectoryPub.publish (poseMsg);
}

int TrajectoryTargetNode::spin()
{
	ros::spin ();

	return 0;
}

int main (int argc, char *argv[])
{
	nlib::quickGDB (argc, argv);

	TrajectoryTargetNode ttn(argc, argv, "trajectory_target");

	return ttn.spin ();
}

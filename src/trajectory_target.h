#ifndef TRAJECTORYTARGET_H
#define TRAJECTORYTARGET_H

#include <chrono>
#include <nlohmann/json.hpp>
#include <nlib/nl_timeseries.h>
#include <eigen3/Eigen/Core>


class TrajectoryTarget
{
public:
	using Pose = Eigen::Vector4f;
	using Trajectory = nlib::Timeseries<Pose, std::chrono::milliseconds>;

	TrajectoryTarget ();

	void loadTrajectory (const std::string &filename);
	void start ();
	Pose getCurrent ();

private:
	Trajectory _trajectory;
};

#endif // TRAJECTORYTARGET_H

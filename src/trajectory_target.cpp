#include "trajectory_target.h"
#include <chrono>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;
using namespace std::chrono;

TrajectoryTarget::TrajectoryTarget()
{

}

void TrajectoryTarget::start () {
	_trajectory.setStartTime (system_clock::now ());
}

TrajectoryTarget::Pose TrajectoryTarget::getCurrent ()
{
	return _trajectory.at(system_clock::now ());
}

void TrajectoryTarget::loadTrajectory (const std::string &filename)
{
	std::ifstream trajectoryFile(filename);
	json jsonTrajectory;

	trajectoryFile >> jsonTrajectory;

	for (const auto &curr : jsonTrajectory["trajectory"])
	{
		Trajectory::Sample sample;
		float timeSeconds = curr["time"];
		sample.delay () = duration_cast<Trajectory::Precision> (duration<float> (timeSeconds));

		int i = 0;
		for (float value : curr["pose"]) {
			sample.obj ()[i] = value;
			i++;
		}
	}
}

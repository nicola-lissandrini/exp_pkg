cmake_minimum_required(VERSION 3.0.2)
project(exp_pkg)

add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  nlib
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES exp_pkg
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
CATKIN_DEPENDS nlib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable (target_trajectory src/trajectory_target_node.cpp src/trajectory_target.cpp)
target_link_libraries (target_trajectory ${catkin_LIBRARIES})


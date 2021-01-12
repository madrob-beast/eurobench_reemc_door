cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(roscpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(eurobench_bms_msgs_and_srvs REQUIRED)
include_directories(${roscpp_INCLUDE_DIRS})
include_directories(${std_msgs_INCLUDE_DIRS})
include_directories(${eurobench_bms_msgs_and_srvs_INCLUDE_DIRS})

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(door_wind SHARED door_wind.cc)
target_link_libraries(door_wind ${GAZEBO_LIBRARIES})

add_library(simple_door_config SHARED simple_door_config.cc)
target_link_libraries(simple_door_config ${GAZEBO_LIBRARIES} ${roscpp_LIBRARIES})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

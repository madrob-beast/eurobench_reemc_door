cmake_minimum_required(VERSION 2.8.3)
project(eurobench_reemc_door)

find_package(catkin REQUIRED)

catkin_package()
add_subdirectory(${PROJECT_SOURCE_DIR}/plugins)
foreach(dir launch models)
    install(DIRECTORY ${dir}/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
endforeach(dir)

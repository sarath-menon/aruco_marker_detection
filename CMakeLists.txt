cmake_minimum_required(VERSION "3.17")
project(opencv_example)
set(CMAKE_CXX_STANDARD 17)

# include folders src,include
include_directories(include src)

# set OpenCV_DIR variable equal to the path to opencv 
# set(OpenCV_DIR /usr/local/Cellar/opencv/4.5.2_4/include/opencv4)

# configure the necessary common CMake environment variables
# needed to include and link the OpenCV program into this
# demo project, namely OpenCV_INCLUDE_DIRS and OpenCV_LIBS
find_package(OpenCV REQUIRED )
find_package(yaml-cpp REQUIRED )

# tell the build to include the headers 
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${YAML_INCLUDE_DIRS} )

# specify the executable target to be built
add_executable(${PROJECT_NAME} src/main.cpp src/aruco_functions.cpp)

# tell it to link the executable target against OpenCV
target_link_libraries(${PROJECT_NAME} 
    ${OpenCV_LIBS}
    yaml-cpp )
#pragma once

#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>

#include <yaml-cpp/yaml.h>

class ArucoFunctions
{
private:
public:
    void createArucoMarker(cv::Ptr<cv::aruco::Dictionary> dictionary);
    auto DetectArucoMarker(cv::Mat frame, cv::Ptr<cv::aruco::Dictionary> dictionary);

    // Function to detect markers and diplay detected markers in image window
    void DisplayDetected();
};
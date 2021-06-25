#include <aruco_functions.h>

#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>

void ArucoFunctions::createArucoMarker(cv::Ptr<cv::aruco::Dictionary> dictionary)
{
    cv::Mat markerImage;
    cv::aruco::drawMarker(dictionary, 23, 200, markerImage, 1);
    cv::imwrite("/Users/sarathmenon/Documents/c++_projects/opencv_examples/generated_images/1_waste.png", markerImage);
}

auto ArucoFunctions::DetectArucoMarker(cv::Mat frame, cv::Ptr<cv::aruco::Dictionary> dictionary)
{
    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::aruco::detectMarkers(frame, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);

    // Draw box on detected markers
    cv::Mat detectedImage = frame.clone();
    cv::aruco::drawDetectedMarkers(detectedImage, markerCorners, markerIds);

    return detectedImage;
}

void ArucoFunctions::DisplayDetected()
{ // Function to detect markers and diplay detected markers in image window
    // Set marker type
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

    //Initialize videocapture
    cv::Mat frame, detectedImage;
    cv::VideoCapture cap;
    cap.open(0);

    // Show error if camera cannot be opened
    if (!cap.isOpened())
    {
        std::cerr << "ERROR! Unable to open camera\n";
    }

    //--- GRAB AND WRITE LOOP
    for (;;)
    {
        cap.read(frame);
        if (frame.empty())
        {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }

        detectedImage = DetectArucoMarker(frame, dictionary);
        // show live and wait for a key with timeout long enough to show images
        cv::imshow("Live", detectedImage);
        if (cv::waitKey(5) >= 0)
            break;
    }
}
#include <iostream>

#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <aruco_functions.h>

int main() {
  ArucoFunctions obj;

  // Function to detect markers and diplay detected markers in image window
  // Set marker type
  cv::Ptr<cv::aruco::Dictionary> dictionary =
      cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);

  // Initialize videocapture
  cv::Mat frame, detectedImage;
  cv::VideoCapture cap;
  cap.open(0);

  // Show error if camera cannot be opened
  if (!cap.isOpened()) {
    std::cerr << "ERROR! Unable to open camera\n";
  }

  //--- GRAB AND WRITE LOOP
  for (;;) {
    cap.read(frame);
    if (frame.empty()) {
      std::cerr << "ERROR! blank frame grabbed\n";
      break;
    }

    detectedImage = obj.DetectArucoMarker(frame, dictionary);
    // show live and wait for a key with timeout long enough to show images
    cv::imshow("Live", detectedImage);
    if (cv::waitKey(5) >= 0)
      break;
  }
}

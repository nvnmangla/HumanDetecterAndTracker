/**
 * @file humanDetector.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Functions definitions for class HumanDetector
 * @version 0.1
 * @date 2022-10-14
 * @copyright Copyright (c) 2022
 *
 */

#include <humanDetector.hpp>
/**
 * @brief Construct a new Human Detector:: Human Detector object
 * 
 * @param imagePath 
 * @param modelPath 
 * @param is_cuda 
 */
HumanDetector::HumanDetector(string imagePath, string modelPath, bool is_cuda) {
  Image img(imagePath);
  Yolo model(modelPath, is_cuda);
}

cv::Mat HumanDetector::detectHuman() {
  cv::Mat image = cv::Mat::ones(2, 2, CV_8UC1);
  return image;
}

// float HumanDetector::depth(){
//   float d = 0;
//   return d;
// }

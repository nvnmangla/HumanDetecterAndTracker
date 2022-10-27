/**
 * @file image.cpp
 * @author Naveen Mangla (nmangla@umd.edu); Mahima Arora (marora1@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-14
 * @copyright Copyright (c) 2022
 *
 */

#include <yolo.hpp>


cv::Mat Yolo::getOutput() {
  cv::Mat outImage = cv::Mat::ones(2, 2, CV_8UC1);

  // Get output image from model
  return outImage;
}
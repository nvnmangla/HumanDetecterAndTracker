/**
 * @file image.hpp
 * @author Naveen Mangla (nvnmangla@umd.edu)
 * @author Mahima Arora
 * @author Abhinav Garg
 * @brief Image related functions
 * @version 0.1
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_IMAGE_HPP_
#define INCLUDE_IMAGE_HPP_

#include <fstream>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

struct Detection {
  // int class_id;
  float confidence;
  cv::Rect box;
  float depth;
};

using std::cin;
using std::cout;
using std::string;

class Image {
 private:
  cv::Mat image;  // image itself :)
 public:
  /**
   * @brief Construct a new Image object
   *
   * @param img Input Image
   */
  explicit Image(cv::Mat &img);

  // Dimentions of the square image
  const float INPUT_WIDTH = 640.0;
  const float INPUT_HEIGHT = 640.0;

  cv::Mat get_image();

  void view();
  /**
   * @brief Squaring Image for Yolo Model
   *
   * @return cv::Mat
   */
  cv::Mat square_img();

  /**
   * @brief To draw rectangle on the image
   *
   * @return cv::Mat
   */
  cv::Mat draw_rectangles(int, std::vector<Detection>);
};

#endif  // INCLUDE_IMAGE_HPP_

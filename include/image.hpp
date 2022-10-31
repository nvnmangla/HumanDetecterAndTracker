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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



#ifndef HUMANDETECTERANDTRACKER_INCLUDE_IMAGE_HPP_
#define HUMANDETECTERANDTRACKER_INCLUDE_IMAGE_HPP_

#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

/**
 * @brief Structure to store detections
 */
struct Detection {
  float confidence;
  cv::Rect box;
  float depth;
};

using std::cin;
using std::cout;
using std::string;

/**
 * @brief Image class, manupulates images
 * 
 */
class Image {
 private:
  cv::Mat image;  // image itself :)

 public:
  /**
   * @brief Construct a new Image object
   *
   * @param img Input Image
   */
  explicit Image(cv::Mat);

  // Dimensions of the square image
  const float INPUT_WIDTH = 640.0;
  const float INPUT_HEIGHT = 640.0;

  /**
   * @brief Get the image object
   * 
   * @return cv::Mat 
   */
  cv::Mat get_image();

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
  cv::Mat draw_rectangles(std::vector<Detection>);
};

#endif  // HUMANDETECTERANDTRACKER_INCLUDE_IMAGE_HPP_

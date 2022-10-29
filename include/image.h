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

#ifndef INCLUDE_IMAGE_H_
#define INCLUDE_IMAGE_H_

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
 public:
  /**
   * @brief Construct a new Image object
   *
   * @param pathToImage:string - Directory to the image
   */
  explicit Image(string pathToImage);
  bool testView = true;
  bool testGrayscale = true;
  const float INPUT_WIDTH = 640.0;
  const float INPUT_HEIGHT = 640.0;

 private:
  string imagePath;  // Path of the image
  cv::Mat image;     // image itself :)
  cv::Mat shortImage;
  int ratio = 4;
  cv::Mat gray;

 public:
  /**
   * @brief Shorten the input image
   *
   * @return cv::Mat
   */
  cv::Mat shorten();

  /**
   * @brief Get the Image
   *
   * @return cv::Mat
   */
  cv::Mat getImage();

  /**
   * @brief Enlage the output image
   *
   * @return cv::Mat
   */
  cv::Mat enlarge();
  /**
   * @brief view the image
   *
   */
  void view();
  /**
   * @brief Gray Scaling the image
   *
   */
  cv::Mat grayScale();

  cv::Mat square_img(const cv::Mat &source);

  cv::Mat draw_rectangles(int, std::vector<Detection>, cv::Mat);
};

#endif  // INCLUDE_IMAGE_H_

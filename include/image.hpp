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

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
<<<<<<< HEAD
using std::cin;
using std::cout;
using std::string;

// <<<<<<< HEAD
class Image {
 private:
  string imagePath = "../shiva.jpg";         // Path of the image
  cv::Mat image = cv::imread(imagePath, 1);  // image itself :)
  cv::Mat shortImage = shorten();
  int ratio = 4;
  cv::Mat gray;

 public:
  bool testView = true;
  bool testGrayscale = true;

  /**
   * @brief Shorten the input image
   *
   * @return cv::Mat
   */
  cv::Mat shorten();
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
  void grayScale();

=======
>>>>>>> af854c728f6c06fb0872ef6651470701b9433164

struct Detection {
  // int class_id;
  float confidence;
  cv::Rect box;
  float depth;
};

using std::cin;
using std::cout;
using std::string;

<<<<<<< HEAD
>>>>>>> 77e0c2d27d4f469ad96fede773330b239b988a39
=======
class Image {

 
 private:
  cv::Mat image;     // image itself :)
 public:
  /**
   * @brief Construct a new Image object
   * 
   * @param img Input Image 
   */
  explicit Image(cv::Mat &img);
    
    int testDetection{};

    // Dimentions of the square image
    const float INPUT_WIDTH = 640.0;
    const float INPUT_HEIGHT = 640.0;


  
  cv::Mat getImage();

  /**
   * @brief view the image
   *
   */
  // void view();
  // /**
  //  * @brief Squaring Image for Yolo Model
  //  * 
  //  * @return cv::Mat 
  //  */
  cv::Mat square_img();

  /**
   * @brief To draw rectangle on the image
   *
   * @return cv::Mat
   */
<<<<<<< HEAD
  cv::Mat grayScale();
>>>>>>> 1e918620d45118a13202a60b3ed48c25da8d788f
=======
  cv::Mat draw_rectangles(int, std::vector<Detection>);
>>>>>>> af854c728f6c06fb0872ef6651470701b9433164
};

#endif  // INCLUDE_IMAGE_HPP_

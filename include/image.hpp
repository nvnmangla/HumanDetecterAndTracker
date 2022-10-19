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

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>
using std::cin;
using std::cout;
using std::string;

<<<<<<< HEAD
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

class Image{
   private: 
    string imagePath = "../shiva.jpg";  // Path of the image 
    cv::Mat image = cv::imread(imagePath,1); // image itself :)
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

>>>>>>> 77e0c2d27d4f469ad96fede773330b239b988a39
};

#endif  // IMAGE_HPP_
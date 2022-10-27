/**
 * @file yolo.hpp
 * @author Naveen Mangla (nvnmangla@umd.edu)
 * @author Mahima Arora
 * @author Abhinav Garg
 * @brief Model related functions
 * @version 0.1
 * @copyright Copyright (c) 2022
 *
 */

#ifndef YOLO_HPP_
#define YOLO_HPP_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

class Yolo {
 private:
  // This will change to original yolo model
  int model;

  void modelFilter(){
      // TODO, Model Filter.
  };

 public:
  /**
   * @brief Get the Output image
   *
   * @return cv::Mat
   */
  cv::Mat getOutput();
  std::vector<std::string> load_class_list();
};

#endif  // YOLO_HPP_

/**
 * @file humanDetector.hpp
 * @author Naveen Mangla (nvnmangla@umd.edu)
 * @author Mahima Arora
 * @author Abhinav Garg
 * @brief The binding class
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

#ifndef INCLUDE_HUMANDETECTOR_HPP_
#define INCLUDE_HUMANDETECTOR_HPP_

#include <string>
#include <cmath>
#include <image.hpp>
#include "./yolo.hpp"
// #include <iostream>



class HumanDetector {
 public:
  HumanDetector(string, string, bool);
  /**
   * @brief Decting and Tracking human.
   *
   * @return cv::Mat
   */
  cv::Mat detectHuman();

  // float depth();
};

#endif  // INCLUDE_HUMANDETECTOR_HPP_

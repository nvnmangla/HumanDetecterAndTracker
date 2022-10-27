
/**
 * @file humanDetector.hpp
 * @author Naveen Mangla (nvnmangla@umd.edu)
 * @author Mahima Arora
 * @author Abhinav Garg
 * @brief The binding class
 * @version 0.1
 * @copyright Copyright (c) 2022
 */

#ifndef HUMANDETECTOR_HPP_
#define HUMANDETECTOR_HPP_

#include <image.hpp>
#include <iostream>
#include <yolo.hpp>

class HumanDetector {
 public:
  HumanDetector(string, string);
  /**
   * @brief Decting and Tracking human.
   *
   * @return cv::Mat
   */
  cv::Mat detectHuman();
};

#endif  // HUMANDETECTOR_HPP_

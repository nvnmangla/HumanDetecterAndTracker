/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@umd.edu); Mahima Arora (marora1@umd.edu)
 * @brief  Implementation
 * @version 0.1
 * @date 2022-09-20
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <humanDetector.hpp>

using std::cin;
using std::cout;
using std::string;

int main() {
  Image img;

  cv::imshow("new",img.shorten());
  cv::waitKey(0);

  
  cout<<"Detecting Humans ......... :) \n"<<"They are complicated\n";

  return 0;
}

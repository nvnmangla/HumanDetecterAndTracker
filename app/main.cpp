/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@umd.edu); Mahima Arora (marora1@umd.edu)
 * @brief  Implementation
 * @version 0.1
 * @date 2022-09-20
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <humanDetector.hpp>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() {
  // Image img("../../bus.jpg");
  Yolo yol("../../yolov5s1.onnx");

  const std::vector<cv::Scalar> colors = {
      cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255),
      cv::Scalar(255, 0, 0)};

  // std::vector<string>classes;'
  auto classes = yol.load_class_list("../../coco_names.txt");

  // auto in_img = img.getImage().clone();

  cv::Mat in_img;

  cv::VideoCapture capture("../../Office-Parkour.mp4");
  if (!capture.isOpened()) {
    std::cerr << "Error opening video file\n";
    return -1;
  }

  while (true) {
    // cv::Mat in_img;
    capture.read(in_img);

    std::vector<Detection> output;
    yol.detect(in_img, output, classes);

    auto detections = output.size();

    for (int i{}; i < static_cast<int>(detections); i++) {
      auto rectangle = output[i];
      const auto color = colors[rectangle.class_id % colors.size()];
      cv::rectangle(in_img, rectangle.box, color, 3);
    }

    cv::imshow("Display window", in_img);
    cv::waitKey(1);
    in_img.release();
  }
  cout << "Detecting Humans ......... :) \n"
       << "They are complicated\n";
  cv::destroyAllWindows();

  return 0;
}

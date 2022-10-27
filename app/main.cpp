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

int main(int argc, char **argv) {

  bool is_cuda = argc > 1 && strcmp(argv[1], "cuda") == 0;
  Yolo yol("../../yolov5s.onnx",is_cuda);


  auto classes = yol.load_class_list("../../coco_names.txt");


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

      cv::rectangle(in_img, rectangle.box,  cv::Scalar(255, 255, 0), 3);

    }

    cv::imshow("Display window", in_img);\
    if (cv::waitKey(1) != -1)
        {
            capture.release();
            std::cout << "finished by user\n";
            break;
        }

    in_img.release();
  }
  cout << "Detecting Humans ......... :) \n"
       << "They are complicated\n";
  cv::destroyAllWindows();

  return 0;
}

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
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(int argc, char **argv) {

  bool is_cuda = argc > 1 && strcmp(argv[1], "cuda") == 0;

  Yolo yol("../../models/yolov5n.onnx",is_cuda);  
  // Creating Yolo class object yol with argument as location of yolo model path

  auto classes = yol.load_class_list("../../segmentations/coco_names.txt");

  cv::Mat in_img;

  cv::VideoCapture capture("../../videos/Office-Parkour.mp4");
  if (!capture.isOpened()) {
    std::cerr << "Error opening video file\n";
    return -1;
  }

  while (true) {
    // cv::Mat in_img;
    capture.read(in_img);

    std::vector<Detection> output;
    // float depth = 0;
    yol.detect(in_img, output, classes);

    auto detections = output.size();

    for (int i{}; i < static_cast<int>(detections); i++) {
      auto rectangle = output[i];
      auto box = output[i].box;
      // cout << rectangle.box << "\n";
      cv::rectangle(in_img, rectangle.box,  cv::Scalar(255, 255, 0), 3);
      if (output[i].depth > 4){
        cv::putText(in_img, std::to_string(output[i].depth)+"ft", cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(255, 255, 0));
      }
      else{
        cv::putText(in_img, std::to_string(output[i].depth)+"ft", cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255));
      }
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
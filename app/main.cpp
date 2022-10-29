/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@umd.edu); Mahima Arora (marora1@umd.edu);
 * Abhinav Garg (agarg125@umd.edu)
 * @brief  Implementation
 * @version 0.1
 * @date 2022-09-20
 * @copyright Copyright (c) 2022
 *
 */

#include <fstream>
#include <humanDetector.hpp>
#include <opencv2/core/mat.hpp>

using std::cin;
using std::cout;
using std::string;

int main(int argc, char **argv) {
  bool is_cuda = argc > 1 && strcmp(argv[1], "cuda") == 0;

  Yolo yol("../../models/yolov5n.onnx", is_cuda);
  Image img("/path");
  // Creating Yolo class object yol with argument as location of yolo model path

  auto classes = yol.load_class_list("../../segmentations/coco_names.txt");
  // classes variable contains all the class name possible in coco dataset

  cv::Mat in_img;
  cv::VideoCapture capture("../../videos/Office-Parkour.mp4");
  // reading video from the file path
  if (!capture.isOpened()) {
    std::cerr << "Error opening video file\n";
    return -1;
  }

  while (true) {
    capture.read(in_img);

    std::vector<Detection> output;

    yol.detect(in_img, output, classes);
    // detects all the persons in the image frame

    int detections = output.size();

    cv::Mat out_img = img.draw_rectangles(detections, output, in_img);
    // functions draws all the rectangle and prints the depth

    cv::imshow("Display window", out_img);
    if (cv::waitKey(1) != -1) {
      capture.release();
      std::cout << "finished by user\n";
      break;
    }
    out_img.release();
  }
  cout << "Detecting Humans ......... :) \n"
       << "They are complicated\n";
  cv::destroyAllWindows();

  return 0;
}

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

int main() {
 
  // Creating Yolo class object yol with argument as location of yolo model path

  Yolo yol("../../models/yolov5n.onnx");
  
  // classes variable contains all the class name possible in coco dataset
  auto classes = yol.load_class_list("../../segmentations/coco_names.txt");

  cv::Mat in_img;
  
  // reading video from the file path
  cv::VideoCapture capture("../../videos/Office-Parkour.mp4");
  if (!capture.isOpened()) {
    // Sanity check
    std::cerr << "Error opening video file\n";
    return -1;
  }
  
  // looping through the frames 
  while (true) {

    capture.read(in_img);
    // creating image object from input image 
    Image img(in_img);

    std::vector<Detection> output;

    // detects all the persons in the image frame
    yol.detect(in_img, output, classes);
    

    int detections = output.size();
    

    cv::Mat out_img = img.draw_rectangles(detections, output);
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

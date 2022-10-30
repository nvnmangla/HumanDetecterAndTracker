/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@umd.edu);
 * @author Mahima Arora (marora1@umd.edu);
 * @author Abhinav Garg (agarg125@umd.edu)
 * @brief  Implementation
 * @version 0.1
 * @date 2022-09-20
 * @copyright Copyright (c) 2022
 *
 */

#include <yolo.hpp>

using std::cin;
using std::cout;
using std::string;

int main(int argc, char *argv[]) {
  // Creating Yolo class object yol with argument as location of yolo model path
  string path = "../videos/Office-Parkour.mp4";
  if (argc == 2) {
    cout << "The argument supplied is " << argv[1] << std::endl;
    path = argv[1];
  } else {
    cout << "Reading file " << path << std::endl;
  }

  Yolo yol("../models/yolov5n.onnx");

  // classes variable contains all the class name possible in coco dataset
  const auto classes = yol.load_class_list("../segmentations/coco_names.txt");

  cv::Mat in_img;

  // reading video from the file path
  cv::VideoCapture capture(path);
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

    // detects all the persons in the image frame
    yol.detect(img, classes);

    // Getting output image
    // functions draws all the rectangle and prints the depth
    cv::Mat out_img =
        img.draw_rectangles(static_cast<int>(yol.output.size()), yol.output);

    cv::imshow("Display window", out_img);
    if (cv::waitKey(1) != -1) {
      capture.release();
      std::cout << "finished by user\n";
      break;
    }
    out_img.release();
    yol.output.clear();
  }
  cout << "Detecting Humans ......... :) \n"
       << "They are complicated\n";
  cv::destroyAllWindows();

  return 0;
}

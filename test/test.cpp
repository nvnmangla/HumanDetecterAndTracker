/**
 * @file test.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Test cases for functions
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>
#include <humanDetector.hpp>
#include <image.hpp>
#include <opencv2/opencv.hpp>
#include <yolo.hpp>

// TEST(Image1, shorten) {
//   cv::Mat im;
//   Image img("");
//   EXPECT_EQ(static_cast<int>(img.getImage().rows / 4),
//             static_cast<int>(img.shorten().rows));
//   // EXPECT_EQ(240, img.enlarge().rows);
// }

// TEST(Image2, englarge) {
//   Image img("../videos/shiva.jpg");
//   EXPECT_EQ(img.getImage().rows, img.enlarge().rows);
//   // EXPECT_EQ(120, img.shorten().rows);
// }

// TEST(Image, grayscaleCheck) {
//   Image img("../videos/shiva.jpg");
//   // img.view();
//   EXPECT_EQ(1, img.grayScale().channels());
//   // EXPECT_EQ(120, img.shorten().rows);
// }

// TEST(Yolo, getOutputCheck) {
//   Yolo objYolo("../models/yolov5s.onnx");
//   EXPECT_EQ(2, objYolo.getOutput().rows);
//   // EXPECT_EQ(120, img.shorten().rows);
// }

// TEST(HumanDetector, detectHumanCheck) {
//   HumanDetector hd("../videos/shiva.jpg", "../models/yolov5.onnx");
//   EXPECT_EQ(2, hd.detectHuman().rows);
  // EXPECT_EQ(120, img.shorten().rows);
// }

// TEST(Yolo,detect){
//   Yolo yol("../yolov5s.onnx",true);
//   auto classes = yol.load_class_list("../../segmentations/coco_names.txt");

//   yol.detect();
// }

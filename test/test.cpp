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
#include<opencv2/opencv.hpp>
#include <image.hpp>
#include <humanDetector.hpp>
#include <yolo.hpp>

TEST(Image1, shorten) {
  Image img("../shiva.jpg");
  EXPECT_EQ(static_cast<int>(img.getImage().rows/4), static_cast<int>(img.shorten().rows));
  // EXPECT_EQ(240, img.enlarge().rows);
}

TEST(Image2, englarge) {
  Image img("../shiva.jpg");
  EXPECT_EQ(img.getImage().rows, img.enlarge().rows);
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(Image, grayscaleCheck) {
  Image img("../shiva.jpg");
  
  EXPECT_EQ(1, img.grayScale().channels());
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(Yolo, getOutputCheck) {
  Yolo objYolo("../yolov5s.onnx",true);
  EXPECT_EQ(2, objYolo.getOutput().rows);
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(HumanDetector, detectHumanCheck) {
  HumanDetector hd("../shiva.jpg","../yolov5.onnx",true);
  EXPECT_EQ(2, hd.detectHuman().rows);
  // EXPECT_EQ(120, img.shorten().rows);
}


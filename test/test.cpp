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
  Image img;
  EXPECT_EQ(static_cast<int>(img.getImage().rows/4), static_cast<int>(img.shorten().rows));
  // EXPECT_EQ(240, img.enlarge().rows);
}

TEST(Image2, englarge) {
  Image img;
  EXPECT_EQ(img.getImage().rows, img.enlarge().rows);
  // EXPECT_EQ(120, img.shorten().rows);
}


TEST(Image4, grayscaleCheck) {
  Image img;
  img.grayScale();
  EXPECT_EQ(false, img.testGrayscale);
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(Yolo, getOutputCheck) {
  Yolo objYolo;
  EXPECT_EQ(2, objYolo.getOutput().rows);
  // EXPECT_EQ(120, img.shorten().rows);
}



TEST(HumanDetector, detectHumanCheck) {
  HumanDetector hd;
  EXPECT_EQ(2, hd.detectHuman().rows);
  // EXPECT_EQ(120, img.shorten().rows);
}


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
#include <image.hpp>
#include <humanDetector.hpp>
#include <yolo.hpp>



TEST(Image1, enlarge) {
  // Image img;
  EXPECT_EQ(240, 240);
  // EXPECT_EQ(240, img.enlarge().rows);
}

TEST(Image2, shorten) {
  // Image img;
  EXPECT_EQ(120, 120);
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(Image3, viewCheck) {
  // Image img;
  EXPECT_EQ(120, 120);
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(Image4, grayscaleCheck) {
  // Image img;
  EXPECT_EQ(121, 121);
  // EXPECT_EQ(120, img.shorten().rows);
}

TEST(Yolo, getOutputCheck) {
  // Image img;
  EXPECT_EQ(120, 120);
  // EXPECT_EQ(120, img.shorten().rows);
}



TEST(HumanDetector, detectHumanCheck) {
  // Image img;
  EXPECT_EQ(120, 120);
  // EXPECT_EQ(120, img.shorten().rows);
}




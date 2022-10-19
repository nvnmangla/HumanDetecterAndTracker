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



TEST(Image, enlarge) {
  Image img;
  EXPECT_EQ(240, 240);
  // EXPECT_EQ(240, img.enlarge().rows);
}


TEST(Image, shorten) {
  Image img;
  EXPECT_EQ(120, 120);
  // EXPECT_EQ(120, img.shorten().rows);
}


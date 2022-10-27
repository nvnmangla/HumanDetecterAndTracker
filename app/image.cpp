/**
 * @file image.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Functions definitions for class Image
 * @version 0.1
 * @date 2022-10-14
 * @copyright Copyright (c) 2022
 *
 */

#include <image.hpp>

Image::Image(string pathToImage) {
  this->imagePath = pathToImage;
  this->image = cv::imread(pathToImage, 1);
  this->shortImage = shorten();
  this->gray = grayScale();
}

cv::Mat Image::enlarge() {
  cv::Mat enlarged;
  cv::resize(this->shortImage, enlarged, this->image.size(), cv::INTER_LINEAR);
  return enlarged;
}

cv::Mat Image::shorten() {
  cv::Mat shortImg;
  cv::resize(this->image, shortImg,
             cv::Size(static_cast<int>(this->image.cols / 4),
                      static_cast<int>(this->image.rows / 4)),
             cv::INTER_LINEAR);
  return shortImg;
}

cv::Mat Image::getImage() { return this->image; }

void Image::view() {
  testView = false;
  cout << "Photo in View\tPress 0 to close";
  cv::imshow("View Window", this->image);
  cv::waitKey(0);
}

cv::Mat Image::grayScale() {
  cv::Mat graysc;
  testGrayscale = false;
  if (this->image.channels() < 3) {
    this->image.copyTo(graysc);
  } else {
    cv::cvtColor(this->image, graysc, cv::COLOR_BGR2GRAY);
  }
  return graysc;
}

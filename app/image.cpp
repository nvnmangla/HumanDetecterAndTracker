/**
 * @file image.cpp
 * @author Naveen Mangla (nmangla@umd.edu);
 * @author Mahima Arora (marora1@umd.edu);
 * @author Abhinav Garg (agarg125@umd.edu)
 * @brief Functions definitions for class Image
 * @version 0.1
 * @date 2022-10-14
 * @copyright Copyright (c) 2022
 *
 */
#include "./image.hpp"

Image::Image(cv::Mat img) {
  this->image = img;
}

cv::Mat Image::get_image() { return this->image; }

cv::Mat Image::square_img() {
  int col = this->image.cols;
  int row = this->image.rows;
  int _max = MAX(col, row);
  cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
  this->image.copyTo(result(cv::Rect(0, 0, col, row)));
  return result;
}

cv::Mat Image::draw_rectangles(std::vector<Detection> output) {
  cv::Mat out_img = this->image.clone();
  for (int i{}; i < static_cast<int>(output.size()); i++) {
    //// LCOV_EXCL_START
    auto rectangle = output[i];

    auto box = output[i].box;
    if (output[i].depth > 4) {
      cv::putText(out_img, std::to_string(output[i].depth) + "ft",
                  cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.75,
                  cv::Scalar(255, 255, 0));
      cv::rectangle(out_img, rectangle.box, cv::Scalar(255, 255, 0), 3);

    } else {
      cv::putText(out_img, std::to_string(output[i].depth) + "ft",
                  cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.75,
                  cv::Scalar(0, 0, 255));
      cv::rectangle(out_img, rectangle.box, cv::Scalar(0, 0, 255), 3);
      //// LCOV_EXCL_STOP
    }
  }
  return out_img;
}

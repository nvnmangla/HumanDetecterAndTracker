/**
 * @file image.cpp
 * @author Naveen Mangla (nmangla@umd.edu)
 * @brief Functions definitions for class Image
 * @version 0.1
 * @date 2022-10-14
 * @copyright Copyright (c) 2022
 *
 */

#include "./image.hpp"
/**
 * @brief Construct a new Image:: Image object
 *
 * @param pathToImage
 */
Image::Image(cv::Mat &img) {
  // this->imagePath = pathToImage;
  this->image = img;
}

cv::Mat Image::get_image() { return this->image; }
/**
 * @brief To view the image frame
 *
 */
// void Image::view() {
//   cout << "Photo in View\tPress 0 to close";
//   cv::imshow("View Window", this->image);
//   cv::waitKey(0);
// }

/**
 * @brief we need to pass a square image to Yolo, hence this function returns a
 * square image
 *
 * @param source (input image)
 * @return cv::Mat
 */
cv::Mat Image::square_img() {
  int col = this->image.cols;
  int row = this->image.rows;
  int _max = MAX(col, row);
  cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
  this->image.copyTo(result(cv::Rect(0, 0, col, row)));
  return result;
}

/**
 * @brief This function edits the image by drawing rectange around the objects
 in the image it also prints the depth measurement of object.
 *
 * @param detections (output size)
 * @param output (contains the measurement of all the rectangles)
 * @param in_img (input image)
 * @return cv::Mat
 */
cv::Mat Image::draw_rectangles(int detections, std::vector<Detection> output) {
  cv::Mat out_img = this->image.clone();
  for (int i{}; i < static_cast<int>(detections); i++) {
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

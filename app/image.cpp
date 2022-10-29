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
Image::Image(string pathToImage) {
  this->imagePath = pathToImage;
  // this->image = cv::imread(pathToImage, 1);
  // this->shortImage = shorten();
}
/**
 * @brief The function enlarge is used to make the image bigger
 * 
 * @return cv::Mat 
 */
cv::Mat Image::enlarge() {
  cv::Mat enlarged;
  cv::resize(this->shortImage, enlarged, this->image.size(), cv::INTER_LINEAR);
  return enlarged;
}

/**
 * @brief the function shorten is used to make image small
 * 
 * @return cv::Mat 
 */
cv::Mat Image::shorten() {
  cv::Mat shortImg;
  cv::resize(this->image, shortImg,
             cv::Size(static_cast<int>(this->image.cols / 4),
                      static_cast<int>(this->image.rows / 4)),
             cv::INTER_LINEAR);
  return shortImg;
}

cv::Mat Image::getImage() { return this->image; }
/**
 * @brief To view the image frame
 * 
 */
void Image::view() {
  testView = false;
  cout << "Photo in View\tPress 0 to close";
  cv::imshow("View Window", this->image);
  cv::waitKey(0);
}
/**
 * @brief Converts the coloured image of three channel to a single channel black
 * and white image
 *
 * @return cv::Mat
 */
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
/**
 * @brief we need to pass a square image to Yolo, hence this function returns a
 * square image
 *
 * @param source (input image)
 * @return cv::Mat
 */
cv::Mat Image::square_img(const cv::Mat &source) {
  int col = source.cols;
  int row = source.rows;
  int _max = MAX(col, row);
  cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
  source.copyTo(result(cv::Rect(0, 0, col, row)));
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
cv::Mat Image::draw_rectangles(int detections, std::vector<Detection> output,
                               cv::Mat in_img) {
  cv::Mat out_img = in_img;
  for (int i{}; i < static_cast<int>(detections); i++) {
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
    }
  }
  return out_img;
}

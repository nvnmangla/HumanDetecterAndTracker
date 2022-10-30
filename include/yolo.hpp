/**
 * @file yolo.hpp
 * @author Naveen Mangla (nvnmangla@umd.edu)
 * @author Mahima Arora
 * @author Abhinav Garg
 * @brief Model related functions
 * @version 0.1
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_YOLO_HPP_
#define INCLUDE_YOLO_HPP_

#include <image.hpp>


using cv::Scalar;
/**
 * @brief The constants INPUT_WIDTH and INPUT_HEIGHT are for the blob size.
 *  The BLOB stands for Binary Large Object. It contains the data in readable
 * raw format. The image has to be converted to a blob so that the network can
 * process it. In our case, it is a 4D array object with the shape (1, 3, 640,
 * 640). Source:
 * https://learnopencv.com/object-detection-using-yolov5-and-opencv-dnn-in-c-and-python/
 */
// Constants.

using std::cin;
using std::cout;
using std::string;

class Yolo {
  
private:
  const float SCORE_THRESHOLD = 0.45;
  const float NMS_THRESHOLD = 0.55;
  const float CONFIDENCE_THRESHOLD = 0.60;
  
public:
  // Text parameters.
  std::vector<Detection> output;

  // Colors.
  Scalar BLACK = Scalar(0, 0, 0);
  Scalar BLUE = Scalar(255, 178, 50);
  Scalar YELLOW = Scalar(0, 255, 255);
  Scalar RED = Scalar(0, 0, 255);

  // constructur
  Yolo(string);
  cv::dnn::Net model;
  // Yolo model YOLO V5
  // cv::Mat format_yolov5(const cv::Mat &source);

  std::vector<std::string> load_class_list(string);


  void detect(Image&,const std::vector<std::string>&);

  void getting_Rect_dim(std::vector<cv::Rect> &, float *,
                        float &, float, float);

  void remove_Redundant_box(float &,Image&,std::vector<cv::Rect>,
                    std::vector<float>);
};
#endif  // INCLUDE_YOLO_HPP_
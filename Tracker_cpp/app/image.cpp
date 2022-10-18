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

Image::Image(string dirToImage){
    this->image = cv::imread(dirToImage,1);
}

cv::Mat Image::enlarge(){

    cv::Mat enlarged;
    cv::resize(shortImage, enlarged,image.size(), cv::INTER_LINEAR);
    return enlarged;

}

cv::Mat Image::shorten(){

    cv::Mat shortImg;
    cv::resize(this->image,shortImg, cv::Size(static_cast<int>(image.rows/4), static_cast<int>(image.cols/4)), cv::INTER_LINEAR);
    return shortImg;

}

void Image::view(){

    cout<<"Photo in View\tPress 0 to close";

    cv::imshow("View Window",image);
    cv::waitKey(0);

    //TODO View the image
}

void Image::grayScale(){
    // TODO grayscale the image
}

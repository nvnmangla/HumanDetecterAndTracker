/**
 * @file main.cpp
 * @author Naveen Mangla (nmangla@umd.edu); Mahima Arora (marora1@umd.edu)
 * @brief  Implementation
 * @version 0.1
 * @date 2022-09-20
 * @copyright Copyright (c) 2022
 *
 */

// #include <iostream>
// #include <humanDetector.hpp>
// #include <opencv2/core/version.hpp>
// #include <opencv2/opencv.hpp>
// #include <vector>
// #include <fstream>

// using namespace cv;
// using namespace std;
// using namespace cv::dnn;

// using std::cin;
// using std::cout;
// using std::string;

// const float INPUT_WIDTH = 640.0;
// const float INPUT_HEIGHT = 640.0;
// const float SCORE_THRESHOLD = 0.5;
// const float NMS_THRESHOLD = 0.45;
// const float CONFIDENCE_THRESHOLD = 0.45;
 
// // Text parameters.
// const float FONT_SCALE = 0.7;
// const int FONT_FACE = FONT_HERSHEY_SIMPLEX;
// const int THICKNESS = 1;
 
// // Colors.
// Scalar BLACK = Scalar(0,0,0);
// Scalar BLUE = Scalar(255, 178, 50);
// Scalar YELLOW = Scalar(0, 255, 255);
// Scalar RED = Scalar(0,0,255);

// void draw_label(Mat& input_image, string label, int left, int top)
// {
//     // Display the label at the top of the bounding box.
//     int baseLine;
//     Size label_size = getTextSize(label, FONT_FACE, FONT_SCALE, THICKNESS, &baseLine);
//     top = max(top, label_size.height);
//     // Top left corner.
//     Point tlc = Point(left, top);
//     // Bottom right corner.
//     Point brc = Point(left + label_size.width, top + label_size.height + baseLine);
//     // Draw white rectangle.
//     rectangle(input_image, tlc, brc, BLACK, FILLED);
//     // Put the label on the black rectangle.
//     putText(input_image, label, Point(left, top + label_size.height), FONT_FACE, FONT_SCALE, YELLOW, THICKNESS);
// }

// vector<Mat> pre_process(Mat &input_image, Net &net)
// {
//     // Convert to blob.
//     Mat blob;
//     blobFromImage(input_image, blob, 1./255., Size(INPUT_WIDTH, INPUT_HEIGHT), Scalar(), true, false);
 
//     net.setInput(blob);
 
//     // Forward propagate.
//     vector<Mat> outputs;
//     net.forward(outputs, net.getUnconnectedOutLayersNames());
 
//     return outputs;
// }

// Mat post_process(Mat &input_image, vector<Mat> &outputs, const vector<string> &class_name)
// {
//     // Initialize vectors to hold respective outputs while unwrapping     detections.
//     vector<int> class_ids;
//     vector<float> confidences;
//     vector<Rect> boxes;
//     // Resizing factor.
//     float x_factor = input_image.cols / INPUT_WIDTH;
//     float y_factor = input_image.rows / INPUT_HEIGHT;
//     float *data = (float *)outputs[0].data;
//     // const int dimensions = 85;
//     // 25200 for default size 640.
//     const int rows = 25200;
//     // Iterate through 25200 detections.
//     for (int i = 0; i < rows; ++i)
//     {
//         float confidence = data[4];
//         // Discard bad detections and continue.
//         if (confidence >= CONFIDENCE_THRESHOLD)
//         {
//             float * classes_scores = data + 5;
//             // Create a 1x85 Mat and store class scores of 80 classes.
//             Mat scores(1, class_name.size(), CV_32FC1, classes_scores);
//             // Perform minMaxLoc and acquire the index of best class  score.
//             Point class_id;
//             double max_class_score;
//             minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
//             // Continue if the class score is above the threshold.
//             if (max_class_score > SCORE_THRESHOLD)
//             {
//                 // Store class ID and confidence in the pre-defined respective vectors.
//                 confidences.push_back(confidence);
//                 class_ids.push_back(class_id.x);
//                 // Center.
//                 float cx = data[0];
//                 float cy = data[1];
//                 // Box dimension.
//                 float w = data[2];
//                 float h = data[3];
//                 // Bounding box coordinates.
//                 int left = int((cx - 0.5 * w) * x_factor);
//                 int top = int((cy - 0.5 * h) * y_factor);
//                 int width = int(w * x_factor);
//                 int height = int(h * y_factor);
//                 // Store good detections in the boxes vector.
//                 boxes.push_back(Rect(left, top, width, height));
//             }
//         }
//         // Jump to the next row.
//         data += 85;
//     }

//         vector<int> indices;
//     NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, indices);
//     for (int i = 0; i < int(indices.size()); i++)
//     {
//         int idx = indices[i];
//         Rect box = boxes[idx];
//         int left = box.x;
//         int top = box.y;
//         int width = box.width;
//         int height = box.height;
//         // Draw bounding box.
//         rectangle(input_image, Point(left, top), Point(left + width, top + height), BLUE, 3*THICKNESS);
//         // Get the label for the class name and its confidence.
//         string label = format("%.2f", confidences[idx]);
//         label = class_name[class_ids[idx]] + ":" + label;
//         // Draw class labels.
//         draw_label(input_image, label, left, top);
//     }
//     return input_image;
// }


// int main()
// {
//     // Load class list.
//     vector<string> class_list;
//     ifstream ifs("coco.names");
//     string line;
//     while (getline(ifs, line))
//     {
//         class_list.push_back(line);
//     }
//     // Load image.
//     Mat frame;
//     frame = imread("/home/silver/Documents/HumanDetecterAndTracker/p.jpg");
//     // Load model.
//     Net net;
//     net = readNet("/home/silver/Documents/HumanDetecterAndTracker/yolov5s.onnx");
//     vector<Mat> detections;     // Process the image.
//     detections = pre_process(frame, net);
//     Mat img = post_process(frame, detections, class_list);
//     // Put efficiency information.
//     // The function getPerfProfile returns the overall time for     inference(t) and the timings for each of the layers(in layersTimes).
//     vector<double> layersTimes;
//     double freq = getTickFrequency() / 1000;
//     double t = net.getPerfProfile(layersTimes) / freq;
//     string label = format("Inference time : %.2f ms", t);
//     putText(img, label, Point(20, 40), FONT_FACE, FONT_SCALE, RED);
//     // cout<<"Bjjefore"<<endl;
//     imshow("Output", img);
//     waitKey(0);
//     return 0;
// }

// int main(int, char **)
// {
//     auto net = cv::dnn::readNet("yolov5s.onnx");
//     cout << CV_VERSION << std::endl;
//     return 0;
// }

// #include <opencv2/opencv.hpp>

// int main(int, char **)
// {
//     auto net = cv::dnn::readNet("/home/silver/Documents/HumanDetecterAndTracker/yolov5s.onnx");
    
//     return 0;
// }

#include <fstream>

#include <opencv2/opencv.hpp>
#include "yolo.cpp"

/**
 * @brief The following function fetches all the classes of coco dataset
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> load_class_list()
{
    std::vector<std::string> class_list;
    std::ifstream ifs("/home/silver/Documents/HumanDetecterAndTracker/classes.txt");
    std::string line;
    while (getline(ifs, line))
    {
        class_list.push_back(line);
    }
    return class_list;
}
/**
 * @brief The function load_net reads the neural network from its provided location
 * 
 * @param net 
 * @param is_cuda 
 */
void load_net(cv::dnn::Net &net, bool is_cuda)
{
    auto result = cv::dnn::readNet("/home/silver/Documents/HumanDetecterAndTracker/yolov5n.onnx");
    if (is_cuda)
    {
        std::cout << "Trying for CUDA\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA_FP16);
    }
    else
    {
        std::cout << "Running on CPU\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }
    net = result;
}

const std::vector<cv::Scalar> colors = {cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0)};

const float INPUT_WIDTH = 640.0;
const float INPUT_HEIGHT = 640.0;
const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.7;

struct Detection
{
    int class_id;
    float confidence;
    cv::Rect box;
};

cv::Mat format_yolov5(const cv::Mat &source) {
    int col = source.cols;
    int row = source.rows;
    int _max = MAX(col, row);
    cv::Mat result = cv::Mat::zeros(_max, _max, CV_8UC3);
    source.copyTo(result(cv::Rect(0, 0, col, row)));
    return result;
}

void detect(cv::Mat &image, cv::dnn::Net &net, std::vector<Detection> &output, const std::vector<std::string> &className) {
    cv::Mat blob;

    auto input_image = format_yolov5(image);
    
    cv::dnn::blobFromImage(input_image, blob, 1./255., cv::Size(INPUT_WIDTH, INPUT_HEIGHT), cv::Scalar(), true, false);
    net.setInput(blob);
    std::vector<cv::Mat> outputs;
    net.forward(outputs, net.getUnconnectedOutLayersNames());

    float x_factor = input_image.cols / INPUT_WIDTH;
    float y_factor = input_image.rows / INPUT_HEIGHT;
    
    float *data = (float *)outputs[0].data;

    const int dimensions = 85;
    const int rows = 25200;
    
    std::vector<int> class_ids;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;

    for (int i = 0; i < rows; ++i) {

        float confidence = data[4];
        if (confidence >= CONFIDENCE_THRESHOLD) {

            float * classes_scores = data + 5;
            cv::Mat scores(1, className.size(), CV_32FC1, classes_scores);
            cv::Point class_id;
            double max_class_score;
            minMaxLoc(scores, 0, &max_class_score, 0, &class_id);
            if (max_class_score > SCORE_THRESHOLD) {

                confidences.push_back(confidence);

                class_ids.push_back(class_id.x);

                float x = data[0];
                float y = data[1];
                float w = data[2];
                float h = data[3];
                int left = int((x - 0.5 * w) * x_factor);
                int top = int((y - 0.5 * h) * y_factor);
                int width = int(w * x_factor);
                int height = int(h * y_factor);
                boxes.push_back(cv::Rect(left, top, width, height));
            }

        }

        data += 85;

    }

    std::vector<int> nms_result;
    cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
    for (int i = 0; i < nms_result.size(); i++) {
        int idx = nms_result[i];
        Detection result;
        result.class_id = class_ids[idx];
        result.confidence = confidences[idx];
        result.box = boxes[idx];
        output.push_back(result);
    }
}

int main(int argc, char **argv)
{

    std::vector<std::string> class_list = load_class_list();

    cv::Mat frame;
    cv::VideoCapture capture("/home/silver/Documents/HumanDetecterAndTracker/in.avi");
    if (!capture.isOpened())
    {
        std::cerr << "Error opening video file\n";
        return -1;
    }

    bool is_cuda = argc > 1 && strcmp(argv[1], "cuda") == 0;

    cv::dnn::Net net;
    load_net(net, is_cuda);

    auto start = std::chrono::high_resolution_clock::now();
    int frame_count = 0;
    float fps = -1;
    int total_frames = 0;

    while (true)
    {
        capture.read(frame);
        if (frame.empty())
        {
            std::cout << "End of stream\n";
            break;
        }

        std::vector<Detection> output;
        detect(frame, net, output, class_list);

        frame_count++;
        total_frames++;

        int detections = output.size();

        for (int i = 0; i < detections; ++i)
        {

            auto detection = output[i];
            auto box = detection.box;
            auto classId = detection.class_id;
            const auto color = colors[classId % colors.size()];
            cv::rectangle(frame, box, color, 3);

            cv::rectangle(frame, cv::Point(box.x, box.y - 20), cv::Point(box.x + box.width, box.y), color, cv::FILLED);
            cv::putText(frame, class_list[classId].c_str(), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }

        if (frame_count >= 30)
        {

            auto end = std::chrono::high_resolution_clock::now();
            fps = frame_count * 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            frame_count = 0;
            start = std::chrono::high_resolution_clock::now();
        }

        if (fps > 0)
        {

            std::ostringstream fps_label;
            fps_label << std::fixed << std::setprecision(2);
            fps_label << "FPS: " << fps;
            std::string fps_label_str = fps_label.str();

            cv::putText(frame, fps_label_str.c_str(), cv::Point(10, 25), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
        }

        cv::imshow("output", frame);

        if (cv::waitKey(1) != -1)
        {
            capture.release();
            std::cout << "finished by user\n";
            break;
        }
    }

    std::cout << "Total frames: " << total_frames << "\n";

    return 0;
}
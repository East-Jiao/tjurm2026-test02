#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    using namespace cv;

    std::pair<Rect,RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    Mat gray,binary;
    Rect rec;
    RotatedRect rrec;

    cvtColor(input, gray, COLOR_BGR2GRAY);                      //灰
    threshold(gray, binary, 50, 255, THRESH_BINARY_INV);            //二
    findContours(binary,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    

    double max = contourArea(contours[0]);
    if(contours.empty())
    {
        res.first = Rect();
        res.second = RotatedRect();
        return res;
    }
    else
    {
        for(int i = 1;i < contours.size();i++)
        {
            if(max > contourArea(contours[i]))
            {
                max = contourArea(contours[i]);
            }
        }
    }
    rec = boundingRect(contours[max]);
    rrec = minAreaRect(contours[max]);
    res.first = rec;
    res.second = rrec;

    return res;
}
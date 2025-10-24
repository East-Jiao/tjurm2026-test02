#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     * 
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE
    using namespace cv;
    //IOU = 重合面积 / 并的面积
    int x1 = max(a.x,b.x);  //左上角
    int y1 = max(a.y,b.y);
    int x2 = min(a.x+a.width,b.x+b.width);  //右下角
    int y2 = min(a.y+a.height,b.y+b.height);
    int width = max(0,x2-x1);
    int height = max(0,y2-y1);
    double jiaoji = width * height;
    double bingji = a.area() + b.area() - jiaoji;
    float IOU;
    if(bingji != 0)
    {
        IOU = jiaoji / bingji;
    }

    return IOU;
}
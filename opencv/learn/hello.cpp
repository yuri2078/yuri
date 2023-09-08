#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  Mat src = imread("1.png"); // 读取一张图片，返回图片数据Mat -> 矩阵， matrix
  imshow("yuri", src); // 显示图片 第一个参数是图片窗口名称
  waitKey(0); 
  destroyAllWindows(); // 销毁所有窗口

  return 0;
}
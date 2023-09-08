#include "../include/tool.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <yuri.h>

using namespace cv;

namespace yuri {


void Tool::imageChange(const Mat &image) {
  Mat gray, hsv;
  cvtColor(image, gray, COLOR_RGB2GRAY); // 图片格式转换
  cvtColor(image, hsv, COLOR_RGB2HSV);

  showImage("gray", gray);
  showImage("hsv", hsv);

  imwrite("2.png", gray); // 写入图片

  destroyAllWindows();
}

void Tool::showImage(const std::string& windowName ,const Mat &image) {
  imshow(windowName, image); // 在windowname 的窗口上 显示image图像
  waitKey(); // 阻塞程序 n 毫秒 0 则一直阻塞
}

Mat Tool::readImage(const std::string &fileName) {
  return imread(fileName);
}

void Tool::imageInfo(const cv::Mat &image) {
  // 图片宽度 长度 通道
  info << "width -> " << image.cols << " height -> " << image.rows << " channels -> " << image.channels();
//   info << "数据\n" << image;
}

void Tool::copyImage(const cv::Mat &im, cv::Mat &cp_im) {
  // 两种克隆方式
  cp_im = im.clone();
  cp_im.copyTo(im);

  // cp_im = im; 只克隆指针不克隆数据

  // 新建一个 512x512 3通道的图像 8 表示8位 u表示 unsized c3 表示3通道
  Mat mat = Mat::zeros(Size(512, 512), CV_8UC3);
  imageInfo(mat);
  // 格式化三个通道 也可以是四个通道 三通道对应bgr
  mat = Scalar(127,127,127); 
  showImage("img", mat);
}
} // namespace yuri

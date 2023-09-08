#include "./include/tool.h"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  yuri::Tool tool;
  Mat image = imread("1.png");
  tool.imageChange(image);
  return 0;
}
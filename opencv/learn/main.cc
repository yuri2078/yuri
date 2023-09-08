#include "./include/tool.h"
#include <opencv2/imgcodecs.hpp>

using namespace cv;

int main() {
  yuri::Tool tool;
  Mat image = tool.readImage("1.png"), img;
  tool.copyImage(image, img);
  return 0;
}
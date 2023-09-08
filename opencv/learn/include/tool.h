#include <opencv2/core/mat.hpp>

namespace yuri {
class Tool {
public:
  // 将图片转换成gray hsv并显示
  void imageChange(const cv::Mat &image);

  // 显示图片
  void showImage(const std::string &windowName, const cv::Mat &image);

  // 读取图片
  cv::Mat readImage(const std::string &fileName);

  // 显示图片信息
  void imageInfo(const cv::Mat &image);

  // 复制图片信息
  void copyImage(const cv::Mat &im, cv::Mat &cp_im);
};
}
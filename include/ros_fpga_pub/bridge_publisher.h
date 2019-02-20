#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static const std::string OPENCV_WINDOW_1 = "Image window";
static const std::string OPENCV_WINDOW_2 = "Gray image window";
static const std::string OPENCV_WINDOW_3 = "Filtered image window";
int *difffilter(cv::Mat src, cv::Mat dst);

//IMAGE IS 640 x 480

class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher gimage_pub_;
  image_transport::Publisher image_pub_;

public:
  ImageConverter();

  ~ImageConverter();

  void imageCb(const sensor_msgs::ImageConstPtr& msg);
};

#include <opencv2/tracking/tracking.hpp>
#include <opencv2/opencv.hpp>

class Video {
    public:
        Video(const char *path);
        void Play();
        void InitBBox();

    private:
        void OpenVideo();
        void InitTracker(cv::Mat frame);
        const char *path_;
        cv::VideoCapture *video_;
        cv::Rect2d bbox_;
        cv::Ptr<cv::Tracker> tracker_;
};
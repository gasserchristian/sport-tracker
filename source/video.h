#include <opencv2/tracking/tracking.hpp>
#include <opencv2/opencv.hpp>

class Video {
    public:
        Video(const char *path);
        void Play(bool save, const char *folder, const char *file);
        void InitBBox(bool save, const char *folder, const char *file);

    private : void OpenVideo();
        void InitTracker(cv::Mat frame);
        const char *path_;
        bool saveBbox_;
        cv::VideoCapture *video_;
        cv::Rect2d bbox_;
        cv::Ptr<cv::Tracker> tracker_;
};
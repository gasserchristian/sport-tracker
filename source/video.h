#include <opencv2/opencv.hpp>

class Video {
    public:
        Video(const char *path);
        void Play();
        void InitBBox();

    private:
        void OpenVideo();
        const char *path_;
        cv::VideoCapture *video_;
        cv::Rect2d bbox_;
};
namespace cv
{
    class VideoCapture;
}
class Video {
    public:
        Video(const char *path);
        void Play();
    private:
        const char* path_;
        void OpenVideo();
        // cv::VideoCapture video_;
};
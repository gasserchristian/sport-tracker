#include <opencv2/tracking/tracking.hpp>
#include "video.h"

Video::Video(const char* path) {
    this->path_ = path;
    this->OpenVideo();
}

void Video::Play() {
    // init 2D image (matrix)
    cv::Mat frame;
    this->video_->read(frame); // get first image

    // create visualisation window
    cv::namedWindow("Play video", cv::WINDOW_NORMAL);
    cv::resizeWindow("Play video", frame.cols / 2, frame.rows / 2);

    // looping through video (consecutive frames)
    while (true) {
        this->video_->read(frame);
        // break at the end of the video
        if (frame.empty())
        {
            printf("[i] end of video\n");
            break;
        }
        if (!this->bbox_.empty())
        {
            cv::rectangle(frame, this->bbox_, cv::Scalar(0, 255, 0), 2);
            printf("height %f\n",this->bbox_.height);
        }
        // show the current image
        imshow("Play video", frame);
        // slow down the loop to see the video
        if (cv::waitKey(5) >= 0)
            break;
    }
}

void Video::InitBBox() {
    cv::Mat frame;
    this->video_->read(frame);
    cv::namedWindow("ROI selection", cv::WINDOW_NORMAL);
    cv::resizeWindow("ROI selection", frame.cols / 2, frame.rows / 2);
    cv::Rect2d bbox =  cv::selectROI("ROI selection", frame);
    this->bbox_ = bbox;
    cv::destroyAllWindows();
}

void Video::OpenVideo() {
    this->video_ = new cv::VideoCapture(this->path_);
    if (!this->video_->isOpened())
    {
        printf("[e] Error on loading video");
    }
    printf(
        "[i] Video frame rate %f [Hz]\n",
        this->video_->get(cv::CAP_PROP_FPS)
    );
}
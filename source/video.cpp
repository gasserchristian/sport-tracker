#include "savebbox.h"
#include "video.h"

const char *Concat(const char *str1, const char *str2, const char *str3)
{
    std::string result = std::string(str1) + std::string(str2);
    result = result + std::string(str3);
    return result.c_str();
}

Video::Video(const char* path) {
    path_ = path;
    OpenVideo();
}

void Video::InitTracker(cv::Mat frame)
{
    tracker_ = cv::TrackerCSRT::create();
    tracker_->init(frame,this->bbox_);
}

void Video::Play(bool save, const char *folder, const char *file)
{
    // save state
    this->saveVideo_ = save;
    this->videoFolder_ = folder;
    this->videoName_ = file;

    // init file saving instance
    BboxFile bboxfile;
    if (this->saveBbox_)
    {
        bboxfile.Open(
            Concat(bboxFolder_, "/", bboxName_)
        );
    }

    // init 2D image (matrix)
    cv::Mat frame;
    this->video_->read(frame); // get first image

    // init tracking variables for looping
    bool trackSuccess = false; // if pattern detected
    cv::Rect2d bbox = this->bbox_;
    cv::Rect bboxRect(bbox.x, bbox.y, bbox.width, bbox.height);

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
            bboxfile.Close();
            break;
        }
        // draw a rectangle if there is a bounding box
        if (!this->bbox_.empty())
        {
            cv::rectangle(frame, bboxRect, cv::Scalar(0, 255, 0), 2);
            trackSuccess = this->tracker_->update(frame, bboxRect);
            bboxfile.SaveLine(
                bboxRect.x,
                bboxRect.y,
                bboxRect.width,
                bboxRect.height
            );
        }
        // show the current image
        imshow("Play video", frame);
        // slow down the loop to see the video
        if (cv::waitKey(5) >= 0)
            break;
    }
}

void Video::InitBBox(bool save, const char *folder, const char *file)
{
    this->saveBbox_ = save;
    this->bboxFolder_ = folder;
    this->bboxName_ = file;

    // get the first video frame
    cv::Mat frame;
    this->video_->read(frame);

    // select the region of interest
    cv::namedWindow("ROI selection", cv::WINDOW_NORMAL);
    cv::resizeWindow("ROI selection", frame.cols / 2, frame.rows / 2);
    cv::Rect2d bbox =  cv::selectROI("ROI selection", frame);
    this->bbox_ = bbox;
    cv::destroyAllWindows();

    // init the tracker
    this->InitTracker(frame);
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
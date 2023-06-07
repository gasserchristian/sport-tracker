#include "video.h"
#include <opencv2/opencv.hpp>
#include <opencv2/tracking/tracking.hpp>

Video::Video(const char* path) {
    this->path_ = path;
    this->OpenVideo();
}

void Video::Play() {
    return;
}

void Video::OpenVideo() {
    return;
}
#include<opencv2/opencv.hpp>
#include<opencv2/tracking/tracking.hpp>
#include<iostream>
#include<stdio.h>
#include"./parser/parser.h"

int main(void)
{
    Metadata md = Metadata();
    // print recap
    printf("[i] Input video: %s\n",md.GetVideoPath());
    printf("[i] Output folder: %s\n",md.GetOutPath());
    printf("[i] Save video: %s\n",(md.ShouldSaveVideo())?"YES":"NO");
    printf("[i] Save bbox: %s\n",(md.ShouldSaveBbox())?"YES":"NO");
    return 0;
}

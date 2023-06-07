#include<iostream>
#include<stdio.h>
#include"./parser/parser.h"
#include"./video.h"

int main(void)
{
    // open and print metadata
    Metadata md = Metadata();
    md.Recap(); // print metadata

    // open video
    Video video = Video(md.GetVideoPath());
    video.InitBBox();
    video.Play();
    
    return 0;
}

#include<iostream>
#include<stdio.h>
#include"./parser/parser.h"
#include"./video.h"

int main(void)
{
    // open and print metadata
    Metadata md = Metadata();
    md.Recap(); // print metadata

    // open video and init bbox
    Video video = Video(md.GetVideoPath());
    video.InitBBox(
        md.ShouldSaveBbox(),
        md.GetOutPath(),
        md.GetBboxPath()
    );

    // Play video
    video.Play(
        md.ShouldSaveVideo(),
        md.GetOutPath(),
        md.GetVideoPath()
    );

    return 0;
}

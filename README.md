# README

## Get started

### Install OpenCV

Install OpenCV 4.x [^1] from Github on Linux (WSL):

```bash
git clone <url OpenCV repo>
mkdir -p build && cd build
cmake ../opencv -D WITH_FFMPEG=ON
make -j4
sudo make install
```

### Install OpenCV contrib

Install OpenCV contribution library. Go to main directory and do followings:

```bash
git clone <url OpenCV contrib repo>
cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules/ ../opencv/
make -j5
sudo make install
```

### Compile the project

```bash
g++ -I/usr/local/include/opencv4 -L./build/lib source/main.cpp -o main.out source/parser/parser.cpp tinyxml/tinyxml2.cpp source/video.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_tracking source/savebbox.cpp
```

## Edit the config file

`config.xml` is a simple xml document that contains all informations about video and the saving parameters.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<tracking outputPath="./experiment-1">
    <video name="video.mp4" save="True" />
    <boundingBox name="bbox.txt" />
    <tracker type="csrt" />
</tracking>
```

The `tracking` tag is mandatory. If the `outputPath` is not set (output folder) then it is the current location. The `video` tag is for information about the  input video and if the output should be saved. Its `name` attribute is mandatory. The `boundingBox` is optional but if it is there, the bounding box for each frame of the video will be stored. Its attribute name is also optional and the default output name is `boundingbox.txt`. Finally, the `tracker` tag indicates the type of tracker. For the moment, `csrt` is the only available type.

**Notes:** for the moment, the output name of the bounding box is `bbox.txt` and the output folder is the current working directory. This has to be fixed.


[^1]: GeeksforGeeks. “How to Install Opencv in C++ on Linux?,” June 23, 2022. https://www.geeksforgeeks.org/how-to-install-opencv-in-c-on-linux/.
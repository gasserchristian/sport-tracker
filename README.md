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


[^1]: GeeksforGeeks. “How to Install Opencv in C++ on Linux?,” June 23, 2022. https://www.geeksforgeeks.org/how-to-install-opencv-in-c-on-linux/.
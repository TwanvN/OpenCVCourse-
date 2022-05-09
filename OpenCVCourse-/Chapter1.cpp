#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showImage();
void showVideo();
void showCam();

void main() {
	//showImage();
	//showVideo();
	showCam();
}

void showImage() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey();
}

void showVideo() {
	string path = "resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;

	while(true) {
		cap.read(img);

		imshow("Image", img);
		waitKey(20);
	}
}

void showCam() {
	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);

		imshow("Image", img);
		waitKey(1);
	}
}
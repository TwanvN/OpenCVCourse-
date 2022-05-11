#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int checkColor();

void main() {
	checkColor();
}

int checkColor() {
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgHSV, mask;

	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue min", "Trackbars", &hmin, 179);
	createTrackbar("Hue max", "Trackbars", &hmax, 179);
	createTrackbar("Sat min", "Trackbars", &smin, 255);
	createTrackbar("Sat max", "Trackbars", &smax, 255);
	createTrackbar("Val min", "Trackbars", &vmin, 255);
	createTrackbar("Val max", "Trackbars", &vmax, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("HSV", imgHSV);
		imshow("Mask", mask);
		waitKey(1);
	}

	return 0;
}
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
	showImage();
}

void showImage() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray;
	Mat imgGaus;
	Mat imgCanny;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgGaus, Size(7, 7), 5, 0);
	Canny(imgGaus, imgCanny, 25, 75);

	imshow("Image", img);
	imshow("Gray", imgGray);
	imshow("Blur", imgGaus);
	imshow("Blur", imgCanny);
	waitKey();
}
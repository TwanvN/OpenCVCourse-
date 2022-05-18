#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

void main() {
	
	// Create the empty image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// Draw on the image
	circle(img, Point(360, 250), 100, Scalar(0, 0, 0), 5);
	circle(img, Point(360, 250), 75, Scalar(0, 0, 0), 5);
	rectangle(img, Point(175, 100), Point(350, 400), Scalar(0, 0, 0), 5);
	rectangle(img, Point(180, 105), Point(345, 395), Scalar(0, 196, 255), FILLED);
	rectangle(img, Point(175, 50), Point(350, 100), Scalar(0, 0, 0), 5);

	// Write text on the image
	putText(img, "Pils", Point(210, 470), FONT_HERSHEY_PLAIN, 4, Scalar(0, 0, 0), 5);

	// Show the image
	imshow("Image", img);

	// Wait for user input
	waitKey();
}
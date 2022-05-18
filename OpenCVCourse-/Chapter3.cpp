#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	// Reading the image and loading it
	string path = "Resources/bier.jpg";
	Mat img = imread(path);

	// Defined image transforms
	Mat imgResized, imgCrop;

	// Resize the imaga
	resize(img, imgResized, Size(), 0.5, 0.5);

	// Crop the image
	Rect roi(175, 50, 300, 600);
	imgCrop = img(roi);

	// Show all three images
	imshow("Image", img);
	imshow("Resize", imgResized);
	imshow("Cropped", imgCrop);

	// Wait for user input
	waitKey();
}
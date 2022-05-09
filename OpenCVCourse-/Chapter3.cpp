#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	string path = "Resources/bier.jpg";
	Mat img = imread(path);
	Mat imgResized, imgCrop;

	//cout << img.size() << endl;
	resize(img, imgResized, Size(), 0.5, 0.5);

	Rect roi(175, 50, 300, 600);
	imgCrop = img(roi);

	imshow("Image", img);
	imshow("Resize", imgResized);
	imshow("Cropped", imgCrop);

	waitKey();
}
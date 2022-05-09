#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

float w = 350, h = 750;
Mat matrix, imgWarp, imgResized;

void main() {

	string path = "Resources/phone.jpg";
	Mat img = imread(path);

	resize(img, imgResized, Size(), 0.20, 0.20);

	Point2f src[4] = { {1739, 939}, {2528, 1196}, {744, 2501}, {1563, 3016} };
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	imshow("Image", imgResized);
	imshow("ImageWarp", imgWarp);

	waitKey();
}
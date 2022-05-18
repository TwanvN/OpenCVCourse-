#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showImage();
void getContours(cv::Mat imgDil, cv::Mat img);

cv::Mat imgGray, imgGaus, imgCanny, imgDilated, imgEroded;

void main() {
	showImage();
}

void showImage() {
	//Image resources
	string path = "Resources/shapes.png";
	Mat img = imread(path);

	//Pre-processing
	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imgGray, imgGaus, cv::Size(7, 7), 5, 0);
	cv::Canny(imgGaus, imgCanny, 25, 75);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(4, 4));
	cv::dilate(imgCanny, imgDilated, kernel);

	//Checking for the contours
	getContours(imgDilated, img);

	//Showing images
	imshow("Image", img);

	waitKey();
}

void getContours(cv::Mat imgDilated, cv::Mat img) {
	vector<vector<Point>> contours;
	vector<cv::Vec4i> hierarchy;

	//Finding the contours of the shapes
	findContours(imgDilated, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]); //Calculating the area of a shape

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		string objectType;

		if (area > 1000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true); //Calculating the amount of corners per shape

			boundRect[i] = boundingRect(conPoly[i]); //Calculating bounding box of shape
			int objCorner = (int)conPoly[i].size(); //Amount of corners of shape

			//If-else statement to check what shape it is
			if (objCorner == 3) {
				objectType = "Triangle";
			}
			else if (objCorner == 4) {

				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;

				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Square";
				}
				else {
					objectType = "Rectangle";
				}
			}
			else if (objCorner > 4) {
				objectType = "Circle";
			}

			//Printing the outlines, bounding box and the shape type on the original image
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, {boundRect[i].x, boundRect[i].y - 5} , FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255), 2);
		}
	}
}
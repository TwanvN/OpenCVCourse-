#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


void video();
void ballstripes();

void main() {
	ballstripes();
}

void video() {
	std::string path = "Resources/test.png";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgGaus, imgCanny, imgDilated, imgEroded;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, imgGaus, cv::Size(7, 7), 5, 0);
	cv::Canny(imgGaus, imgCanny, 25, 75);

	// Create circle kernel
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(4,4));

	// dilate + erode
	cv::dilate(imgCanny, imgDilated, kernel);
	cv::erode(imgDilated, imgEroded, kernel);

	cv::imshow("Image", img);
	cv::imshow("Gray", imgGray);
	cv::imshow("Blur", imgGaus);
	cv::imshow("Canny", imgCanny);
	cv::imshow("dilate", imgDilated);
	cv::imshow("erode", imgEroded);


	cv::waitKey();
}

void ballstripes()
{
	std::string path = "Resources/ball_stripes.png";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgEroded, imgDilated;

	// Turning the image to grayscale
	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

	// Create circle kernel
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(4, 4));

	// erode + dilate the grayscale image (opening operator)
	cv::dilate(imgGray, imgDilated, kernel);
	cv::erode(imgDilated, imgEroded, kernel);
	

	// Show the image
	cv::imshow("Image", img);
	cv::imshow("erode", imgEroded);

	cv::waitKey();
}


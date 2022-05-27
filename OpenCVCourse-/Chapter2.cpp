#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


void ballstripes();
void canyyTest();
void cannySliders();

void main() {
	//ballstripes();
	//canyyTest();
	cannySliders();
}

void canyyTest() {
	std::string path = "Resources/test.png";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgGaus, imgCanny, imgDilated, imgEroded;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imgGray, imgGaus, cv::Size(7, 7), 5, 0);
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

void cannySliders()
{
	std::string path = "Resources/lovensdijkstraat_image.png";
	cv::Mat img = cv::imread(path);
	cv::Mat imgGray, imgGaus, imgCanny, imgDilated, imgEroded;

	// Create the value's
	int threshold1 = 25, threshold2 = 75;

	// Operate to grayscale + blur
	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img, imgGaus, cv::Size(7, 7), 5, 0);
	
	cv::namedWindow("Trackbars", (640, 200));
	cv::createTrackbar("Threshold 1", "Trackbars", &threshold1, 255);
	cv::createTrackbar("Threshold 2", "Trackbars", &threshold2, 255);
	
	
	
	while (true)
	{
		cv::Canny(imgGaus, imgCanny, threshold1, threshold2);

		cv::imshow("original", img);
		cv::imshow("Canny", imgCanny);

		cv::waitKey(1);
	}
	
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


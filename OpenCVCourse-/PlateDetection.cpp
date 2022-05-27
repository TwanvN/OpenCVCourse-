#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

void splitLicensePlate(cv::Mat plate, std::string name);

void main() {
	cv::VideoCapture cap(0);
	cv::Mat img;

	// Define the cascade for a face
	cv::CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_russian_plate_number.xml");

	// Null check
	if (faceCascade.empty()) return;

	// Run through camera
	while (true) {
		cap.read(img);

		// Detect the faces
		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		// Draw the detected faces
		for (int i = 0; i < faces.size(); i++)
		{
			cv::Rect face = faces[i];

			cv::Mat plateCrop = img(face);
			cv::imwrite("Resources/Plates/" + std::to_string(i) + ".png", plateCrop);


			cv::rectangle(img, face.tl(), face.br(), cv::Scalar(255, 0, 255), 3);

			splitLicensePlate(plateCrop, "nummerplaat" + std::to_string(i));
		}

		// Show the image
		cv::imshow("Image", img);
		cv::waitKey(1);
	}

}

#define START_SHIFT 40
#define END_SHIFT 50
#define NUMBER_OF_LETTERS 7.0

void splitLicensePlate(cv::Mat plateImage, std::string name)
{
	int letterLength = (plateImage.cols - (START_SHIFT + END_SHIFT)) / NUMBER_OF_LETTERS;

	for (int i = 0; i < NUMBER_OF_LETTERS; i++)
	{

		cv::Rect split = cv::Rect(START_SHIFT + (letterLength * i), 0, letterLength, plateImage.rows);

		cv::Mat letterCrop = plateImage(split);
		cv::imwrite("Resources/Plates/" + name + "_" + std::to_string(i) + ".png", letterCrop);
	}

}
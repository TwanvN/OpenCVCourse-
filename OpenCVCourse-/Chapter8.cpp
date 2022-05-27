#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	VideoCapture cap(0);
	Mat img;

	// Define the cascade for a face
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	// Null check
	if (faceCascade.empty()) return;

	// Run through camera
	while (true) {
		cap.read(img);

		// Detect the faces
		std::vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		// Draw the detected faces
		for (Rect face : faces)
			cv::rectangle(img, face.tl(), face.br(), Scalar(255, 0, 255), 3);

		// Show the image
		imshow("Image", img);
		waitKey(1);
	}
}
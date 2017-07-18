#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace cv;
using namespace std;
int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);



int main() {
	HW01_TestFunction();
	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}

int HW01_TestFunction() {
	Mat img = imread("lena.jpg");
	Mat gry_img;
	Mat binary_img;
	cvtColor(img, gry_img, COLOR_BGR2GRAY);
	threshold(gry_img, binary_img, 100.0, 255.0, THRESH_BINARY);
	imshow("InputImage", img);
	imwrite("image.jpg", img);
	imshow("GrayImage", gry_img);
	imwrite("image.jpg", gry_img);
	imshow("BinaryImage", binary_img);
	imwrite("image.jpg", binary_img);
	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs) {
	string file[8] = { "capture/1.jpg", "capture/2.jpg", "capture/3.jpg", "capture/4.jpg", "capture/5.jpg", "capture/6.jpg", "capture/7.jpg", "capture/8.jpg" };
	int i = 0;
	vector<string>home;
	for (i = 0; i < numberOfImgs; i++) {
		home.push_back(file[i]);
		Mat img = imread(home[i]);
		Mat gry_img;
		Mat binary_img;
		cvtColor(img, gry_img, COLOR_BGR2GRAY);
		threshold(gry_img, binary_img, 100.0, 255.0, THRESH_BINARY);

		namedWindow("InputImage");
		namedWindow("GrayImage");
		namedWindow("BinaryImage");
		moveWindow("InputImage", 0, 20);
		moveWindow("GrayImage", 300, 20);
		moveWindow("BinaryImage", 600, 20);

		imshow("InputImage", img);
		imshow("GrayImage", gry_img);
		imshow("BinaryImage", binary_img);
		while (1) {
			if (waitKey(0) == 13) break;
		}
	}
	return 0;
}






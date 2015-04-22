#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "image_features.hpp"

void detect_by_sift(Mat img, vector<KeyPoint> &key_points)
{
	SIFT sift;
	sift(img, Mat(), key_points, cv::noArray());
}

void detect_by_surf(Mat img, vector<KeyPoint> &key_points)
{
	SURF surf;
	surf(img, Mat(), key_points, cv::noArray());
}

void detect_by_fast(Mat img, vector<KeyPoint> &key_points)
{
	int threshold = 20;
	FAST(img, key_points, threshold	);
}

void detect_by_orb(Mat img, vector<KeyPoint> &key_points)
{
	int threshold = 20;
	ORB orb;
	orb(img, Mat(), key_points, cv::noArray());
}

void detect_by_mser(Mat img, vector<KeyPoint> &key_points)
{
	int threshold = 20;
	BRISK mser;
	mser(img, Mat(), key_points, cv::noArray());
}
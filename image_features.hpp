#ifndef IMAGE_FEATURES_HPP__
#define IMAGE_FEATURES_HPP__

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"


using namespace cv;
using namespace std;

enum Detector 
{
	__SIFT 	= 1,
	__SURF 	= 2,
	__FAST 	= 3,
	__BRISK = 4,
	__ORB   = 5,
	__FREAK = 6,
};

enum Descriptor
{
	_SIFT 	= 10,
	_SURF 	= 20,
	_BRIEF 	= 30,
	_BRISK 	= 40,
	_ORB   	= 50,
	_FREAK 	= 60,
};

enum Matcher
{
	BF 		= 100,
	BF_L1 	= 200,
	BF_HAM 	= 300,
	BF_HAM2 = 400,
	FLANN  	= 500,
};


void detect_by(Detector type, Mat img, vector<KeyPoint> &keypoints);
void descript_by(Descriptor type, Mat img, vector<KeyPoint> keypoints, Mat &descriptors);
void match_by(Matcher type, Mat descriptor1, Mat descriptor2, vector<DMatch> &matches );

#endif

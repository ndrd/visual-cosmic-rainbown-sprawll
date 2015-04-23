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
	_SIFT 	= 1,
	_SURF 	= 2,
	_BRIEF 	= 3,
	_BRISK 	= 4,
	_ORB   	= 5,
	_FREAK 	= 6,
};

enum Matcher
{
	BF 		= 1,
	BF_L1 	= 2,
	BF_HAM 	= 3,
	BF_HAM2 = 4,
	FLANN  	= 5,
};

struct Combination
{
	Detector detector;
	Descriptor descriptor;
	Matcher matcher;
};

struct TestData
{
	string image_1_name;
	string image_2_name;
	string combination_name;
	vector<KeyPoint> kp1;
	vector<KeyPoint> kp2;
	Mat desc1;
	Mat desc2;
	vector<DMatch> matches;
	double time;
};


void detect_by(Detector type, Mat img, vector<KeyPoint> &keypoints);
void descript_by(Descriptor type, Mat img, vector<KeyPoint> keypoints, Mat &descriptors);
void match_by(Matcher type, Mat descriptor1, Mat descriptor2, vector<DMatch> &matches);
void generate_combinations(vector<Combination> &combs);
void run_combination(Combination comb,Mat img1, Mat img2, vector<TestData> &data);
void run_tests(vector<Combination> combs, string img1_path, vector<string> images, vector<TestData> &results);

string combination_name(Combination comb);
void print_results(TestData results);

#endif

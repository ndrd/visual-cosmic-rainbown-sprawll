#ifndef IMAGE_FEATURES_HPP__
#define IMAGE_FEATURES_HPP__

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"


using namespace cv;
using namespace std;

void detect_by_sift(Mat img, vector<KeyPoint> &keypoints);
void detect_by_surf(Mat img, vector<KeyPoint> &keypoints);
void detect_by_fast(Mat img, vector<KeyPoint> &keypoints);
void detect_by_orb(Mat img, vector<KeyPoint> &keypoints);
void detect_by_mser(Mat img, vector<KeyPoint> &keypoints);


#endif

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "image_features.hpp"

void descript_by(Descriptor type, Mat img, vector<KeyPoint> keypoints, Mat &descriptors)
{
	string name;

	switch(type)
	{
		case _SIFT:
			name = "SIFT";
			break;

		case _SURF:
			name = "SURF";
			break;

		case _BRIEF:
			name = "BRIEF";
			break;

		case _BRISK:
			name = "BRISK";
			break;

		case _ORB:
			name = "ORB";
			break;

		case _FREAK:
			name = "FREAK";
			break;
	}

	Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create(name);
	descriptor->compute(img, keypoints, descriptors);
}

void detect_by(Detector type, Mat img, vector<KeyPoint> &keypoints)
{
	string name;

	switch(type)
	{
		case __SIFT:
			name = "SIFT";
			break;

		case __SURF:
			name = "SURF";
			break;

		case __FAST:
			name = "FAST";
			break;

		case __BRISK:
			name = "BRISK";
			break;

		case __ORB:
			name = "ORB";
			break;

		case __FREAK:
			name = "FREAK";
			break;

		default:
			cout << "No se encontro el detector\n";
			break;
	}

	Ptr<FeatureDetector> detector = FeatureDetector::create(name);
	detector->detect(img, keypoints);
}

void match_by(Matcher type, Mat descriptor1, Mat descriptor2, vector<DMatch> &matches )
{
	string name;

	switch(type)
	{		

		case BF:
			name = "BruteForce";
			break;

		case BF_L1:
			name = "BruteForce-L1";
			break;

		case BF_HAM:
			name = "BruteForce-Hamming";
			break;

		case BF_HAM2:
			name = "BruteForce-Hamming(2)";
			break;

		case FLANN:
			name = "FlannBased";
			break;

		default:
			cout << "No se encontro el emparejador\n";
			break;

	}

	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(name);
	matcher->match(descriptor1, descriptor2, matches);
}
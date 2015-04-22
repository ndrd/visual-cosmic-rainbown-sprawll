#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "image_features.hpp"


void detect_by(Detector type, Mat img, vector<KeyPoint> &keypoints)
{
	cv::initModule_nonfree();

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

void descript_by(Descriptor type, Mat img, vector<KeyPoint> keypoints, Mat &descriptors)
{
	cv::initModule_nonfree();

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

		default:
			cout << "No se encontro" << endl;

	}

	Ptr<DescriptorExtractor> descriptor = DescriptorExtractor::create(name);
	descriptor->compute(img, keypoints, descriptors);
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

void generate_combinations(vector<Combination> &combs)
{
	Combination comb;

	for (int i = __SIFT; i < __FREAK; ++i)
	{
		for (int j = _SIFT; j < __FREAK; ++j)
		{
			for (int k = BF; k < FLANN; ++k)
			{
				comb.detector = static_cast<Detector>(i);
				comb.descriptor = static_cast<Descriptor>(j);
				comb.matcher = static_cast<Matcher>(k);

				combs.push_back(comb);
				
			}	
		}
	}
}

void run_combination(Combination comb, ImageData data)
{
	cout << combination_name(comb) << endl;

	detect_by(comb.detector, data.img1, data.kp1);
	detect_by(comb.detector, data.img2, data.kp2);

	descript_by(comb.descriptor, data.img1, data.kp1, data.desc1);
	descript_by(comb.descriptor, data.img2, data.kp2, data.desc2);

	match_by(comb.matcher, data.desc1, data.desc2, data.matches);
}

string combination_name(Combination comb)
{
	string name;

	switch(comb.detector)
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

	name += " - ";

	switch(comb.descriptor)
	{
		case _SIFT:
			name += "SIFT";
			break;

		case _SURF:
			name += "SURF";
			break;

		case _BRIEF:
			name += "BRIEF";
			break;

		case _BRISK:
			name += "BRISK";
			break;

		case _ORB:
			name += "ORB";
			break;

		case _FREAK:
			name += "FREAK";
			break;
	
	}
	
	name += " - ";

	switch(comb.matcher)
	{		
		case BF:
			name += "BruteForce";
			break;

		case BF_L1:
			name += "BruteForce-L1";
			break;

		case BF_HAM:
			name += "BruteForce-Hamming";
			break;

		case BF_HAM2:
			name += "BruteForce-Hamming(2)";
			break;

		case FLANN:
			name += "FlannBased";
			break;

		default:
			cout << "No se encontro el emparejador\n";
			break;
	}

	return name;
}



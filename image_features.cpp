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

	for (int i = __SIFT; i <= __FREAK; ++i)
	{
		for (int j = _SIFT; j <= __FREAK; ++j)
		{
			for (int k = BF; k <= FLANN; ++k)
			{
				comb.detector = static_cast<Detector>(i);
				comb.descriptor = static_cast<Descriptor>(j);
				comb.matcher = static_cast<Matcher>(k);

				combs.push_back(comb);
				
			}	
		}
	}
}

void run_combination(Combination comb, Mat img1, Mat img2,  TestData &data)
{
	data.combination_name =  combination_name(comb);

	double t = (double)getTickCount();

	detect_by(comb.detector, img1, data.kp1);
	detect_by(comb.detector, img2, data.kp2);

	descript_by(comb.descriptor, img1, data.kp1, data.desc1);
	descript_by(comb.descriptor, img2, data.kp2, data.desc2);

	match_by(comb.matcher, data.desc1, data.desc2, data.matches);

	data.time = ((double)getTickCount() - t) / getTickFrequency();

}

void run_tests(vector<Combination> combinations, string image_path, 
            vector<string> images_path, vector<TestData> &results)
{
    cout << "Running " << combinations.size() << " combinations "
        << " over " << images_path.size() << "images." << endl;

    Mat img1 = imread(image_path);

    for (int i = 0; i < images_path.size(); ++i)
    {
        Mat img2 = imread(images_path[i]);

        for (int j = 0; j < combinations.size(); ++j)
        {
            try
            {
            	TestData data;

        		data.image_1_name = image_path;
        		data.image_2_name = images_path[i];

                run_combination(combinations[i], img1, img2, data);
                print_results(data);
                results.push_back(data);

            } 
            catch(exception &e){}
        }

    }

}

void print_results(TestData data) {
	cout << data.combination_name << " with " << data.image_1_name << " and "
		<< data.image_2_name << " find " << data.matches.size() << " matches, takes " << data.time << " seconds" << endl;
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



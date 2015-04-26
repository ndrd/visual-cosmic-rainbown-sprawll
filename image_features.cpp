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
            vector<string> images_path, vector<TestData> &results, string path_name)
{
    cout << "Running " << combinations.size() << " combinations "
        << " over " << images_path.size() << "images." << endl;

    Mat img1 = imread(image_path);

    cout << image_path << " - " << path_name << endl;

    for (int i = 0; i < combinations.size(); ++i)
    {

        for (int j = 0; j < images_path.size(); ++j)
        {
        	Mat img2 = imread(images_path[j]);

            try
            {
            	TestData data;

        		data.image_1_name = image_path;
        		data.image_2_name = images_path[j];
        		data.combination_name = combination_name(combinations[i]);

                run_combination(combinations[i], img1, img2, data);
                print_result(data);
                results.push_back(data);

            } 
            catch(exception &e){}
        }

    }

}

void print_results(vector<TestData> results) {
	for (int i = 0; i < results.size(); ++i)
	{
		print_result(results[i]);
	}
}

void default_combinations(vector<Combination> &combs) 
{
	Combination c1;
	c1.detector = __SIFT;
	c1.descriptor= _SIFT;
	c1.matcher = BF;

	Combination c2;
	c2.detector = __SURF;
	c2.descriptor = _SURF;
	c2.matcher = BF;

	Combination c3;
	c3.detector = __SIFT;
	c3.descriptor = _SURF;
	c3.matcher = BF;

	Combination c4;
	c4.detector = __SURF;
	c4.descriptor = _SIFT;
	c4.matcher = BF;

	Combination c5;
	c5.detector = __FAST;
	c5.descriptor = _ORB;
	c5.matcher = BF_HAM2;

	Combination c6;
	c6.detector = __FAST;
	c6.descriptor = _BRIEF;
	c6.matcher = BF;

	combs.push_back(c1);
	combs.push_back(c2);
	combs.push_back(c3);
	combs.push_back(c4);
	combs.push_back(c5);
	combs.push_back(c6);

}


void print_result(TestData data) {
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



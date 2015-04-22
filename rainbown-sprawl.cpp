#include <iostream>
#include "opencv2/opencv.hpp"
#include "image_features.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    if(argc < 2)
        return -1;

    Mat img = imread(argv[1]);

    vector<KeyPoint> key_points, key_points2;

    detect_by(__SURF, img, key_points);
    detect_by(__SIFT, img, key_points2);

    Mat output_img, output_img2;
    drawKeypoints(img, key_points, output_img);
    drawKeypoints(img, key_points2, output_img2);

    namedWindow("Image");
    imshow("Image", output_img);
    namedWindow("Image2");
    imshow("Image2", output_img2);
    waitKey(0);

   
    destroyWindow("Image2");

    return 0;
}
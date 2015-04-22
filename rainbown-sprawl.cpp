#include <iostream>
#include "opencv2/opencv.hpp"
#include "image_features.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    if(argc < 3)
        return -1;

    Mat img = imread(argv[1]);
    Mat img2 = imread(argv[2]);

    vector<Combination> combinations;
    generate_combinations(combinations);

    ImageData data;
    data.img1 = img;
    data.img2 = img2;

    cout << "\nRuning " << combinations.size() << "\n";

    for (int i = 0; i < combinations.size(); ++i)
    {
        try
        {
            run_combination(combinations[i], data);
        } 
        catch(exception &e){}
    }

/*
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
*/
    return 0;
}
#include <iostream>
#include "opencv2/opencv.hpp"
#include "image_features.hpp"

using namespace cv;
using namespace std;

void help();


int main(int argc, char** argv)
{

    if(argc < 3) {
        help();
        return -1;
    }

    string img1 = argv[1];
    string path = argv[2];
    vector<string> images_path; 
    cv::glob(path, images_path, false);
    
    vector<Combination> combinations;
    generate_combinations(combinations);

    vector<TestData> results;
    run_tests(combinations,  img1, images_path, results);

    return 0;
}

void help() {
    cout << "Usage: " << endl;
    cout << "./rainbown-sprawl image_to_find folder_with_images " << endl;
}


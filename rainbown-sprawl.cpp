#include <iostream>
#include "opencv2/opencv.hpp"
#include "image_features.hpp"

using namespace cv;
using namespace std;

void help();
void detectors_test(vector<TestData> &results, string img1, vector<string> images_to_test, string path_name);


int main(int argc, char* argv[])
{

    if(argc < 3 ){
        help();
        return -1;
    }

    string  cmd = argv[1];

    if (cmd == "--test-detectors") 
    {
        vector<string> paths_to_run;
        vector < vector <string> > folders;   

        for (int i = 2; i < argc; ++i)
        {
            string path = argv[i];
            vector<string> images_path; 
            cv::glob(path, images_path, false);
            folders.push_back(images_path);
            paths_to_run.push_back(path);
        }

        /* loading image to test */
        vector<string> images_to_test;
        vector< vector<TestData> > results;


        for (int i = 0; i < paths_to_run.size(); ++i)
        {
            string img = paths_to_run[i] + "/test.jpg";

            for (int j = 0; j < folders.size(); ++j)
            {
                vector<TestData> result_data;
                detectors_test(result_data,img, folders[i], paths_to_run[i]);
                results.push_back(result_data);
            }
        }

 
    } else if (cmd == "--video-raster")
    {
        cout << argc << " arg1" << endl; 
    }
    
    return 0;
}

void help() {
    cout << "Usage: " << endl;
    cout << "./rainbown-sprawl [options ] file_folder  " << endl;
    cout << "[options ]:" << endl;
    cout << "--test-detectors folder1 folder2 ... foldern" << endl;
    cout << "   each folder must have an image named test.* wich will be compared with the rest of the set" << endl;
}

void detectors_test(vector<TestData> &results, string img1, vector<string> images_to_test, string path_name)
{
    vector<Combination> combinations;
    default_combinations(combinations);

    run_tests(combinations,  img1, images_to_test, results, path_name);


}


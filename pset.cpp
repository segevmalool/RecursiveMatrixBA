//By Segev Malool -- A quick way to visualize the powerset ordered by set inclusion

#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <sstream>

using namespace std; 
using namespace cv;

int main (int argc, char * argv[]) {
    namedWindow("halppiner", WINDOW_NORMAL);
    srand(time(NULL));

    int k;
    istringstream ss(*(argv+1));
    ss >> k;

    Mat tmp1;    
    Mat tmp2;
    Mat N = (Mat_<double>(2,2) << 0,1,0,0); //The power set lattice/boolean algebra represented as an adjacency matrix
    Mat z;
    Mat I;
    int i = 1;
    Mat II = Mat::eye(pow(2,k+1),pow(2,k+1),CV_64F);

    while (i <= k) {
      z = Mat::zeros(pow(2,i), pow(2,i), CV_64F);
      I = N+Mat::eye(pow(2,i), pow(2,i), CV_64F);

      vconcat(N, z, tmp1);
      vconcat(I, N, tmp2);
      hconcat(tmp1, tmp2, N);

      i++;      
    }
    i = 1;
    Mat NT = N.t();

    imwrite("pset.png",N+NT);
    imshow("halppiner", N+NT);

    while (!(waitKey(33)==27));
    return(0);
}

/*

 * multithresh.cpp
 *
 *  Created on: 19-Jan-2016
 *      Author: mukesh_kumar
 *      function
 *      int calculatethreshold(Mat img);
 *
 *      calculate threshold using Otsu's Binarization method and return int ;
 *      link for Otsu's Binarization
 *      https://en.wikipedia.org/wiki/Otsu%27s_method#Method
 *
 */
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int calculatethreshold(Mat img){
	int nbHistLevels = 256;
	   // calculate histogram
	   int *histData = (int*)calloc(nbHistLevels, sizeof(int));
	   int ptr = 0;

	   while (ptr < img.total()) {
	        int h = img.data[ptr];
	        histData[h]++;
	        ptr ++;
	     }
	   // total number of pixels
	      int total = img.total();
	      float sum = 0;
	      int t;
	      float sumB = 0;
	      int wB = 0;
	      int wF = 0;
	      float varMax = 0;
	      int threshold = 0;
	         for (t=0; t < nbHistLevels; t++)
	              sum += t * histData[t];
	         for (t=0; t < nbHistLevels; t++) {
	            wB += histData[t];               // Weight Background
	            if (wB == 0)
	               continue;
	            wF = total - wB;                 // Weight Foreground
	            if (wF == 0)
	               break;
	            sumB += (float) (t * histData[t]);
	            float mB = sumB / wB;            // Mean Background
	            float mF = (sum - sumB) / wF;    // Mean Foreground
	            // Calculate Between Class Variance
	            float varBetween = (float)wB * (float)wF * (mB - mF) * (mB - mF);
	            // Check if new maximum found
	            if (varBetween > varMax) {
	               varMax = varBetween;
	               threshold = t;
	            }
	         }
	  return threshold;
}
int main(int argc, char **argv) {
Mat img=imread(argv[1],0);
Mat src32f;
img.convertTo(src32f,CV_8UC1);               //convert image to CV_8UC1
int thresholdvalue=calculatethreshold(src32f);// calculate threshold value
cout<<"Otsu's Binarization threshold for image is "<<threshold<<endl;
namedWindow("threshold image",WINDOW_AUTOSIZE);
Mat dest;
threshold(img,dest,(double)thresholdvalue,255,THRESH_OTSU);
imshow("threshold image",dest);
waitKey();
return 0;
}






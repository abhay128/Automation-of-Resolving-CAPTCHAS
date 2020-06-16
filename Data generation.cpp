/*
 *
 *
 *  
 *      Author: Abhay and Renuka
 */


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// global variables
const int MIN_CONTOUR_AREA = 40;

const int RESIZED_IMAGE_WIDTH = 20;
const int RESIZED_IMAGE_HEIGHT = 30;


int main(int, char** argv)
{
std::vector<std::vector<cv::Point> > ptContours;// declare contours vector
std::vector<cv::Vec4i> v4iHierarchy;// declare contours hierarchy
cv::Mat matClassificationInts;	// these are our training classifications, note we will have to perform some conversions before writing to file later
// these are our training images, due to the data types that the KNN object KNearest requires,
cv::Mat matTrainingImages;// we have to declare a single Mat, then append to it as though it's a vector,
// also we will have to perform some conversions before writing to file later
// possible chars we are interested in are digits 0 through 9, put these in vector intValidChars
std::vector<int> intValidChars= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
std::vector<char> charValidChars={'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z','a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k','l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z'};
//std::vector<>

Mat matGrayscale;
Mat matThreshCopy;
Mat matBlurred;
Mat matThresh;
Mat src = imread"20Doller.jpg",IMREAD_COLOR);
imshow("Source Image", src);// Show source image
cv::cvtColor(src, matGrayscale, CV_BGR2GRAY);// convert to grayscale
cv::GaussianBlur(matGrayscale,matBlurred,cv::Size(5, 5),0);
// input image
// output image
// smoothing window width and height in pixels
// sigma value, determines how much the image will be blurred, zero makes function choose the sigma value
// filter image from grayscale to black and white
cv::adaptiveThreshold(matBlurred,matThresh,255,cv::ADAPTIVE_THRESH_GAUSSIAN_C,cv::THRESH_BINARY_INV,11,2);
// input image
// output image
// make pixels that pass the threshold full white
// use gaussian rather than mean, seems to give better results
// invert so foreground will be white, background will be black
// size of a pixel neighborhood used to calculate threshold value
// constant subtracted from the mean or weighted mean
cv::imshow("matThresh", matThresh);


matThreshCopy = matThresh.clone();// make a copy of the thresh image, this in necessary b/c findContours modifies the image
cv::findContours(matThreshCopy,ptContours,v4iHierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
// input image, make sure to use a copy since the function will modify this image in the course of finding contours
// output contours
// output hierarchy
// retrieve the outermost contours only
// compress horizontal, vertical, and diagonal segments and leave only their end points

for (int i = 0; i < ptContours.size(); i++)
{						// for each contour
	if (cv::contourArea(ptContours[i]) > MIN_CONTOUR_AREA)
	{			// if contour is big enough to consider
		cv::Rect boundingRect = cv::boundingRect(ptContours[i]);// get the bounding rect
		cv::rectangle(src, boundingRect, cv::Scalar(0, 0, 255), 1);// draw red rectangle around each contour as we ask user for input
		cv::Mat matROI = matThresh(boundingRect);// get ROI image of bounding rect
		cv::Mat matROIResized;
		cv::resize(matROI, matROIResized, cv::Size(RESIZED_IMAGE_WIDTH, RESIZED_IMAGE_HEIGHT));// resize image, this will be more consistent for recognition and storage
		cv::imshow("matROI", matROI);// show ROI image for reference
		cv::imshow("matROIResized", matROIResized);// show resized ROI image for reference
		cv::imshow("matTrainingNumbers", src);// show training numbers image, this will now have red rectangles drawn on it
		int intChar = cv::waitKey(0);			// get key press
		cout<<"\n"<<intChar;
		if (intChar == 27)
		{		// if esc key was pressed
			return(0);				// exit program
		}
		if (intChar == 65506)// || intChar == 65509)//65506=shift && 65509=caps lock
		{
			intChar = cv::waitKey(0);
			cout<<"\n"<<intChar;
			if (intChar == 27)
			{		// if esc key was pressed
					return(0);				// exit program
			}
			else if(intChar == 65601)
			{
				intChar=65;
			}
			else if(intChar == 65602)
			{
				intChar=66;
			}
			else if(intChar == 65603)
			{
				intChar=67;
			}
			else if(intChar == 65604)
			{
				intChar=68;
			}
			else if(intChar == 65605)
			{
				intChar=69;
			}
			else if(intChar == 65606)
			{
				intChar=70;
			}
			else if(intChar == 65607)
			{
				intChar=71;
			}
			else if(intChar == 65608)
			{
				intChar=72;
			}
			else if(intChar == 65609)
			{
				intChar=73;
			}
			else if(intChar == 65610)
			{
				intChar=74;
			}
			else if(intChar == 65611)
			{
				intChar=75;
			}
			else if(intChar == 65612)
			{
				intChar=76;
			}
			else if(intChar == 65613)
			{
				intChar=77;
			}
			else if(intChar == 65614)
			{
				intChar=78;
			}
			else if(intChar == 65615)
			{
				intChar=79;
			}
			else if(intChar == 65616)
			{
				intChar=80;
			}
			else if(intChar == 65617)
			{
				intChar=81;
			}
			else if(intChar == 65618)
			{
				intChar=82;
			}
			else if(intChar == 65619)
			{
				intChar=83;
			}
			else if(intChar == 65620)
			{
				intChar=84;
			}
			else if(intChar == 65621)
			{
				intChar=85;
			}
			else if(intChar == 65622)
			{
				intChar=86;
			}
			else if(intChar == 65623)
			{
				intChar=87;
			}
			else if(intChar == 65624)
			{
				intChar=88;
			}
			else if(intChar == 65625)
			{
				intChar=89;
			}
			else if(intChar == 65626)
			{
				intChar=90;
			}
		}
		if ((std::find(intValidChars.begin(), intValidChars.end(), intChar) != intValidChars.end())||(std::find(charValidChars.begin(), charValidChars.end(), intChar) != charValidChars.end()))
		{  // else if the char is in the list of chars we are looking for . . .
			matClassificationInts.push_back(intChar);		// append classification char to integer list of chars (we will convert later before writing to file)
			cv::Mat matImageFloat;							// now add the training image (some conversion is necessary first) . . .
			matROIResized.convertTo(matImageFloat, CV_32FC1);		// convert Mat to float
			cv::Mat matImageReshaped = matImageFloat.reshape(1, 1);		// flatten
			matTrainingImages.push_back(matImageReshaped);		// add to Mat as though it was a vector, this is necessary due to the data types that KNearest.train accepts
		}// end if
	}// end if
}// end for

// save classifications to file ///////////////////////////////////////////////////////
char answer;
cout<<"\nHave changed node name?????...continue..???(y/n)  : ";
cin>>answer;
if(answer=='y')
{
cv::Mat matClassificationFloats;
matClassificationInts.convertTo(matClassificationFloats, CV_32FC1);// convert ints to floats
cv::FileStorage fsClassifications("classifications.xml", cv::FileStorage::APPEND);// open the classifications file
if (fsClassifications.isOpened() == false)
{// if the file was not opened successfully
	std::cout << "error, unable to open training classifications file, exiting program\n\n";// show error message
	return(0);// and exit program
}
//int k=1;
//char x=std::rand();

fsClassifications <<"classification24"<<matClassificationFloats;// write classifications into classifications section of classifications file
fsClassifications.release();// close the classifications file

// save training images to file ///////////////////////////////////////////////////////

cv::FileStorage fsTrainingImages("images.xml", cv::FileStorage::APPEND);// open the training images file
if (fsTrainingImages.isOpened() == false)
{// if the file was not opened successfully
	std::cout << "error, unable to open training images file, exiting program\n\n";// show error message
	return(0);// and exit program
}
fsTrainingImages << "image24" << matTrainingImages;// write training images into images section of images file
fsTrainingImages.release();// close the training images file

	std::cout<<ptContours.size();
	std::cout << "training complete\n\n";
    //waitKey(0);
    return 0;
}
else
{
	return 0;
}
}



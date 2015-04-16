#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * i_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
	int n_pixels = image.getHeight() * image.getWidth();

	for (int i = 0; i <= n_pixels; i++){
		RGB p = image.getPixel(i);
		double r = (double)p.r * 0.21;
		double g = (double)p.g * 0.72;
		double b = (double)p.b * 0.07;
		
		unsigned char c =(int)( r + g + b);

		i_image->setPixel(i,c);

	}


	return i_image;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}
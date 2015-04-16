#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	// int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	// (DONE)TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	int n_pixels = other.getWidth() * other.getHeight();
	intensity_map = new Intensity[n_pixels];
	for (int i = 0; i < n_pixels; i++){
		intensity_map[i] = other.getPixel(i);
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: Create a copy from the other object
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	intensity_map = new Intensity[width * height];

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: Initialize pixel storage
}

IntensityImageStudent::~IntensityImageStudent() {

	delete[] intensity_map;

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] intensity_map;
	intensity_map = new Intensity[width * height];

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[] intensity_map;
	int n_pixels = other.getWidth() * other.getHeight();
	intensity_map = new Intensity[n_pixels];

	for (int i = 0; i < n_pixels; i++){
		intensity_map[i] = other.getPixel(i);
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	if (x < getWidth() && y < getHeight()){
		intensity_map[y * getWidth() + x] = pixel;
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i < getWidth()*getHeight()){
		intensity_map[i] = pixel;
	}

	//int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	if (x < getWidth() && y < getHeight()){
		return intensity_map[y * getWidth() + x];
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: no comment needed :)
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {

	if (i < getWidth()*getHeight()){
		return intensity_map[i];
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE)TODO: see setPixel(int i, RGB pixel)
	return 0;
}
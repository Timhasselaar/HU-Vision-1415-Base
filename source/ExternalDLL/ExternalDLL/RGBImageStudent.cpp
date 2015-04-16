#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//(DONE) TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	int n_pixels = other.getWidth() * other.getHeight();
	rgb_map = new RGB[n_pixels];
	for (int i = 0; i < n_pixels; i++){
		rgb_map[i] = other.getPixel(i);
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	rgb_map = new RGB[width*height];

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	delete[] rgb_map;

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] rgb_map;
	rgb_map = new RGB[width*height];

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] rgb_map;
	int n_pixel = other.getWidth() * other.getHeight();
	rgb_map = new RGB[n_pixel];
	for (int i = 0; i < n_pixel; i++){
		rgb_map[i] = other.getPixel(i);
	}

	//throwError = 0, e = 1 / throwError;
	//(DONE) TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	if (x < getWidth() && y < getHeight()){
		rgb_map[y*getWidth()+x] = pixel;
	}

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i < getWidth()*getHeight()){
		rgb_map[i] = pixel;
	}

	//int throwError = 0, e = 1 / throwError;
	/*
	* (DONE)
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	if (x < getWidth() && y < getHeight()){
		return rgb_map[y*getWidth()+x];
	}
	return 0;

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: no comment needed :)
}

RGB RGBImageStudent::getPixel(int i) const {
	if (i < getWidth()*getHeight()){
		return rgb_map[i];
	}
	return 0;

	//int throwError = 0, e = 1 / throwError;
	//(DONE) TODO: see setPixel(int i, RGB pixel)
}
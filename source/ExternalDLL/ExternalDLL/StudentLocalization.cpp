#include "StudentLocalization.h"
#include "ImageIO.h"
#include "ImageFactory.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	RGBImage * debugImage = ImageFactory::newRGBImage();
	ImageIO::intensityToRGB(image, *debugImage);

	//Create the eye features to return
	Feature featureLeftEye = Feature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature featureRightEye = Feature(Feature::FEATURE_EYE_RIGHT_RECT);

	//Add the left eye rect
	featureLeftEye.addPoint(Point2D<double>(10,10));
	featureLeftEye.addPoint(Point2D<double>(20, 20));

	//Add the right eye rect
	featureRightEye.addPoint(Point2D<double>(30, 10));
	featureRightEye.addPoint(Point2D<double>(40, 20));

	//Put the eye features
	features.putFeature(featureRightEye);
	features.putFeature(featureLeftEye);

	//Save debug image
	ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Localization-5/debug.png"));
	delete debugImage;
	return true;
}
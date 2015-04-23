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
   int x_top_left_left_eye = 0;
   int y_top_left_left_eye = 0;
   int x_bottom_right_left_eye = 0;
   int y_bottom_right_left_eye = 0;
   featureLeftEye.addPoint(Point2D<double>(x_top_left_left_eye, y_top_left_left_eye));
   featureLeftEye.addPoint(Point2D<double>(x_bottom_right_left_eye, y_bottom_right_left_eye));

	//Add the right eye rect
   int x_top_left_right_eye = 0;
   int y_top_left_right_eye = 0;
   int x_bottom_right_right_eye = 0;
   int y_bottom_right_right_eye = 0;
   featureRightEye.addPoint(Point2D<double>(x_top_left_right_eye, y_top_left_right_eye));
   featureRightEye.addPoint(Point2D<double>(x_bottom_right_right_eye, y_bottom_right_right_eye));

   //Draw rectangles on RGB_Map
   for (int i = x_top_left_left_eye; i <= x_bottom_right_left_eye; i++){
      debugImage->setPixel(i, y_top_left_left_eye, RGB(255, 255, 0));
      debugImage->setPixel(i, y_bottom_right_left_eye, RGB(255, 255, 0));
   }
   for (int i = y_top_left_left_eye; i <= y_bottom_right_left_eye; i++){
      debugImage->setPixel(x_top_left_left_eye, i, RGB(255, 255, 0));
      debugImage->setPixel(x_bottom_right_left_eye, i, RGB(255, 255, 0));
   }

   for (int i = x_top_left_right_eye; i <= x_bottom_right_right_eye; i++){
      debugImage->setPixel(i, y_top_left_right_eye, RGB(255, 255, 0));
      debugImage->setPixel(i, y_bottom_right_right_eye, RGB(255, 255, 0));
   }
   for (int i = y_top_left_right_eye; i <= y_bottom_right_right_eye; i++){
      debugImage->setPixel(x_top_left_right_eye, i, RGB(255, 255, 0));
      debugImage->setPixel(x_bottom_right_right_eye, i, RGB(255, 255, 0));
   }

	//Put the eye features
	features.putFeature(featureRightEye);
	features.putFeature(featureLeftEye);

	//Save debug image
	ImageIO::saveRGBImage(*debugImage, ImageIO::getDebugFileName("Localization-5/debug.png"));
	delete debugImage;
	return true;
}
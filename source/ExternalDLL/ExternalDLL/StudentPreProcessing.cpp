#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include <stdio.h>
#include <iostream>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
   IntensityImage * i_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
   int n_pixels = image.getHeight() * image.getWidth();

   for (int i = 0; i <= n_pixels; i++){
      RGB p = image.getPixel(i);
      double r = (double)p.r * 0.21;
      double g = (double)p.g * 0.72;
      double b = (double)p.b * 0.07;

      unsigned char c = (int)(r + g + b);

      i_image->setPixel(i, c);

   }


   return i_image;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
   return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
   IntensityImage * i_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
   int max = 0; int min = 0;
   int firstAndThirdThreeKernelLines[] = { 0, 0, 0, 1 ,1,1, 0, 0, 0 };
   int secondThreeKernelLines[] = { 1,1,1,-4,-4,-4,1,1,1 };
   for (int image_x = 0; image_x < image.getWidth(); image_x++){
      for (int image_y = 0; image_y < image.getHeight(); image_y++){
         int total_intensity = 0;
         for (int kernel_x = 0; kernel_x < 9; kernel_x++){
            for (int kernel_y = 0; kernel_y < 9; kernel_y++){
               int kernel_on_image_x = image_x + kernel_x - 4;
               int kernel_on_image_y = image_y + kernel_y - 4;

               //First check if the x coordinate isn't outside of the image
               if (kernel_on_image_x < 0){ kernel_on_image_x = 0; }
               else if (kernel_on_image_x >= image.getWidth()){ kernel_on_image_x = image.getWidth() - 1; }
               else{ kernel_on_image_x = image_x + kernel_x - 4; }


               //Also check if the y coordinate isn't outside of the image
               if (kernel_on_image_y < 0){ kernel_on_image_y = 0; }
               else if (kernel_on_image_y >= image.getHeight()){ kernel_on_image_y = image.getHeight() - 1; }
               else{ kernel_on_image_y = image_y + kernel_y - 4; }

               if (kernel_y >= 3 && kernel_y <= 5){
                  int ints = (int)image.getPixel(kernel_on_image_x, kernel_on_image_y);
                  int nextints = ints * secondThreeKernelLines[kernel_x];
                  total_intensity += nextints;
               }
               else{
                  total_intensity += (int)image.getPixel(kernel_on_image_x, kernel_on_image_y) * firstAndThirdThreeKernelLines[kernel_x];
               }
               //std::cout << kernel_on_image_x << ", " << kernel_on_image_y << " = " << total_intensity << "\n";
            }
         }
         int new_intensity = 255 -(total_intensity/20 + 128);

         /* Checking for the maximum and minimum values
         if (new_intensity < min){
            min = new_intensity;
         }
         if (new_intensity > max) {
            max = new_intensity;
         }
         */

         // quick thresholding, values obtained by testing
         // TODO: Write test rapport on these values
         if (new_intensity < 120){
            new_intensity = 0;
         }
         else if (new_intensity > 200){
            new_intensity = 0;
         }
         else {
            new_intensity = 255;
         }
         i_image->setPixel(image_x, image_y, new_intensity);
      }
   }
   //std::cout << min << ", " << max;
   return i_image;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
   return nullptr;
}
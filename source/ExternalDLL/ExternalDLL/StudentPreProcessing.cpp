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
   int firstAndThirdThreeKernelLines[] = { 0, 0, 0, 1, 1, 1, 0, 0, 0 };
   int secondThreeKernelLines[] = { 1, 1, 1, -4, -4, -4, 1, 1, 1 };
   for (int image_x = 0; image_x < image.getWidth(); image_x++){
      for (int image_y = 0; image_y < image.getHeight(); image_y++){
         int total_intensity = 0;
         for (int kernel_x = image_x - 4; kernel_x <= image_x + 4; kernel_x++){
            for (int kernel_y = image_y - 4; kernel_y <= image_y + 4; kernel_y++){
               int temp_kernel_x;
               int temp_kernel_y;

               //First check if the x coordinate isn't outside of the image
               if (kernel_x < 0){ temp_kernel_x = 0; }
               else if (kernel_x >= image.getWidth()){ temp_kernel_x = image.getWidth() - 1; }
               else{ temp_kernel_x = kernel_x; }


               //Also check if the y coordinate isn't outside of the image
               if (kernel_y < 0){ temp_kernel_y = 0; }
               else if (kernel_y >= image.getHeight()){ temp_kernel_y = image.getHeight() - 1; }
               else{ temp_kernel_y = kernel_y; }

               //Set what array is used for the kernel
               if (kernel_y < image_y - 1 || kernel_y > image_y + 1){
                  total_intensity += image.getPixel(temp_kernel_x, temp_kernel_y) * secondThreeKernelLines[kernel_x - image_x + 4];
               }
               else {
                  total_intensity += image.getPixel(temp_kernel_x, temp_kernel_y) * firstAndThirdThreeKernelLines[kernel_x - image_x + 4];
               }
            }
         }
         int new_intensity = (-total_intensity / 36);
         i_image->setPixel(image_x, image_y, new_intensity);
      }
   }
   return i_image;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
   return nullptr;
}
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

               // kernel_y = 0, 1, 2 betekend de bovenste 3 regels van de kernel,
               // kernel_y = 3, 4, 5 betekend de middelste 3 regels van de kernel,
               // en kernely_y = 6, 7, 8 betekend weer de bovenste (gelijk aan de onderste) 3 regels van de kernel.
               if (kernel_y >= 3 && kernel_y <= 5){
                  total_intensity += (int)image.getPixel(kernel_on_image_x, kernel_on_image_y) * secondThreeKernelLines[kernel_x];
               }
               else{
                  total_intensity += (int)image.getPixel(kernel_on_image_x, kernel_on_image_y) * firstAndThirdThreeKernelLines[kernel_x];
               }
               //std::cout << kernel_on_image_x << ", " << kernel_on_image_y << " = " << total_intensity << "\n";
            }
         }
         // Het totaal van de waardes in de kernel is 36.
         // Dus door de waarde te delen door 36 zul je altijd een resultaat tussen -255 en 255 krijgen.
         int new_intensity = total_intensity;

         // Uit de kernel komen waardes tussen de -2000 en 2000.
         // Om dit af te vangen verhogen we alles onder de 0 naar 0,
         // En verlagen we alles boven de 255 naar 255.
         if (new_intensity < 0){
            new_intensity = 0;
         }
         if (new_intensity > 255) {
            new_intensity = 255;
         }
         i_image->setPixel(image_x, image_y, new_intensity);
      }
   }
   return i_image;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
   IntensityImage * i_image = new IntensityImageStudent(image.getWidth(), image.getHeight());
   // After trying a few values, 220 gave the result closest to the original image.
   const int threshhold = 220;
   for (int image_x = 0; image_x < image.getWidth(); image_x++){
      for (int image_y = 0; image_y < image.getHeight(); image_y++){
         int intensity = image.getPixel(image_x, image_y);
         if (intensity >= threshhold){
            i_image->setPixel(image_x, image_y, 0);
         }
         else {
            i_image->setPixel(image_x, image_y, 255);
         }
      }
   }
   return i_image;
}
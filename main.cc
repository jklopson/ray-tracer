#include "vec3.h"
#include "ray.h"
#include "color.h"

#include <iostream>

using namespace std;

int main(){

    //image
    int image_width = 256;
    int image_height = 256;

    //render
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for(int j = 0; j < image_height; j++){
        clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush << '\n';
        for(int i = 0; i < image_width; i++){
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(cout, pixel_color);
        }
    }
    clog << "\rDone.    \n";
}
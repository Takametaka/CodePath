#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <complex.h>
#include <math.h>

#define MAX_IT 1000

#define WIDTH_X 3.0
#define WIDTH_Y 2.0

//rgb stored as 24 most right bit of uint32_t

uint32_t color_function(int n)
{
    double perc = (double)n/(double)MAX_IT;   
    uint8_t r = 0xFF*perc*perc;
    uint8_t g = 0x00;
    uint8_t b = 0x55*sqrt(perc);
    return (r<<16) + (g<<8) + b;
}

int main(int argc, char **argv)
{
    if(5 != argc)
    {
        fprintf(stderr,"Wrong number of arguments\n");
        exit(1);
    }
    double sizex = atof(argv[1]);
    double sizey = sizex*2.0/3.0;
    
    double complex center = atof(argv[2]) + I*atof(argv[3]);
    double zoom = atof(argv[4]);

    double width_x = WIDTH_X / zoom;
    double width_y = WIDTH_Y / zoom;

    FILE *F = fopen("mandelbrot_set.ppm","w");
    if(NULL == F)
    {
        fprintf(stderr,"Failed to create ppm file\n");
        exit(1);
    }

    fprintf(F,"P3 %d %d 255\n",(int)sizex,(int)sizey);
    for(double y = 0; y < sizey; y++)
    {
        for(double x = 0; x < sizex; x++)
        {
            double complex c = (x / sizex) * width_x - (width_x / 2.0 - creal(center)) + I * ( (y / sizey) * width_y - (width_y / 2.0 + cimag(center)) );
            uint32_t color = 0x000000;
            double complex z = 0.0 + I*0.0;
            for(int it = 0; it < MAX_IT; it++)
            {

                if(creal(z)*creal(z) + cimag(z)*cimag(z) > 4)
                { color = color_function(it); break; }
                z = z*z+c;

            }
            fprintf(F,"%d %d %d\n", (color>>16) & 0x000000FF, (color>>8) & 0x000000FF, color & 0x000000FF);
        }
    }
    fclose(F);
    return 0;
}

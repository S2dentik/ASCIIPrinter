#include "FileReader.c"
#include <stdlib.h>
#include <stdio.h>

#define MAX_INTENSITY 255.0 


const char* ramp = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!1I;:,\"`'. ";
const char* reverse_ramp = " .'`\",:;I1!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";


float getIntensity(Pixel pixel) {
    return (pixel.Red * 0.299 + pixel.Green * 0.587 + pixel.Blue * 0.114) / MAX_INTENSITY; 
}

char getCharacter(float intensity) {
    return ramp[(int)(intensity * 60)];
}

char *getAsciiString(Pixel *pixels, int size, int width, int height) {
    int i, j, string_index = 0;
    char string[size + height + 1];
    for (i = height - 1; i >= 0; i--) {
	for (j = 0; j < width; j++) {
	    int index = (width) * i + j;
	    string[string_index++] = getCharacter(getIntensity(pixels[index]));
	}
	string[string_index++] = '\n';
    }

    return string;
}

#include "FileReader.c"
#include <stdlib.h>
#include <stdio.h>

#define MAX_INTENSITY 255.0 
static const char *INTENSITY_STRING = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!1I;:,\"`'. ";

float getIntensity(Pixel pixel) {
    return (pixel.Red * 0.299 + pixel.Green * 0.587 + pixel.Blue * 0.114) / MAX_INTENSITY; 
}

char getCharacter(float intensity) {
    return INTENSITY_STRING[(int)(intensity * 60)];
}

char *getAsciiString(Pixel *pixels, int size, int width, int height) {
    int i, j, string_index = 0;
    char string[size + height + 1];
    for (i = height - 1; i >= 0; i--) {
	for(j = 0; j < width; j++) {
	    string[string_index++] = getCharacter(getIntensity(pixels[(width) * i + j]));
	}
	string[string_index++] = '\n';
    }

    return string;
}

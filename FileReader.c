#include <stdio.h>
#include <stdlib.h>

typedef struct Pixel {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} Pixel ;

Pixel* getPixels(const char* path, int *size, int *width, int *height) {
    FILE *file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    
    unsigned char *string = malloc(fsize + 1);

    int startingByte;

    fseek(file, 10, SEEK_SET);
    fread(&startingByte, 4, 1, file);
    fseek(file, 18, SEEK_SET);
    fread(width, 4, 1, file);
    fseek(file, 22, SEEK_SET);
    fread(height, 4, 1, file);
    fseek(file, 34, SEEK_SET);
    fread(size, 4, 1, file);

    fseek(file, startingByte, SEEK_SET); 
    fread(string, *size, 1, file);
    fclose(file);

    Pixel pixels[*size];
    int i, j = 0;

    for(i = 0; i < *size; i += 3) {
	Pixel pixel;
	pixel.Red = string[i];
	pixel.Green = string[i+1];
	pixel.Blue = string[i+2];
	pixels[j] = pixel;
	j++;
    }

    
    return pixels;
}

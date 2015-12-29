#include <stdio.h>
#include <stdlib.h>

#define BMP_STARTING_ARRAY_BYTE 10
#define BMP_IMAGE_WIDTH_BYTE 18
#define BMP_IMAGE_HEIGHT_BYTE 22
#define BMP_IMAGE_SIZE_BYTE 34

typedef struct Pixel {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} Pixel ;

Pixel* getPixels(const char* path, int *size, int *width, int *height) {
    FILE *file = fopen(path, "rb");
    int startingByte, i;

    fseek(file, BMP_STARTING_ARRAY_BYTE, SEEK_SET);
    fread(&startingByte, 4, 1, file);
    fseek(file, BMP_IMAGE_WIDTH_BYTE, SEEK_SET);
    fread(width, 4, 1, file);
    fseek(file, BMP_IMAGE_HEIGHT_BYTE, SEEK_SET);
    fread(height, 4, 1, file);
    fseek(file, BMP_IMAGE_SIZE_BYTE, SEEK_SET);
    fread(size, 4, 1, file);

    unsigned char *image_array = malloc(*size + 1);
    fseek(file, startingByte, SEEK_SET); 
    fread(image_array, *size, 1, file);
    fclose(file);

    Pixel pixels[*size];

    for(i = 0; i < *size; i += 3) {
	Pixel pixel;
	pixel.Red = image_array[i];
	pixel.Green = image_array[i+1];
	pixel.Blue = image_array[i+2];
	pixels[i / 3] = pixel;
    }
 
    return pixels;
}

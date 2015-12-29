#include "ASCIIArt.c"

int main(int argc, char *argv[]) {
    int size, width, height;
    Pixel *pixels = getPixels(argv[1], &size, &width, &height); 
    char *asciiString = getAsciiString(pixels, size, width, height);

    FILE *output = fopen("out", "w");
    fputs(asciiString, output);
    fclose(output);
    
    return 0;
}



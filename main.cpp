#include <stdio.h>
#include <string.h>
#include <cstdlib>

int main(int argc, char **argv) {

    // Setting up sizes with argv or static
    size_t resSize = (argc > 2) ? strlen(argv[1]) + strlen(argv[2]) + 3 /* space + \n + \0 */: 8;
    size_t colorSize = 4;

    int width, height;

    char res[resSize];

    if (argc > 2) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);

        snprintf(res, sizeof(res), "%s %s", argv[1], argv[2]);
    } else {
        width = 800;
        height = 600;

        snprintf(res, sizeof(res) /* supposed to be 8 */, "800 600");
    }

    char colorFormat[colorSize] = "255";
    char magic[] = "P3";

    // Setting up header
    size_t ppmHeaderSize = resSize + colorSize + strlen(magic) +1;
    char ppm_header[ppmHeaderSize];
    snprintf(ppm_header, sizeof(ppm_header), "%s\n%s\n%s", magic, res, colorFormat);

    // Printing header
    printf("%s\n", ppm_header);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if((x > width*0.25 && x < width*0.75) && (y > height*0.33 && y < height*0.66)) {
                printf("0 200 180 ");
            }
            else {
                printf("255 255 255 ");
            } 
        }
        printf("\n");
    }

    return 0;
}

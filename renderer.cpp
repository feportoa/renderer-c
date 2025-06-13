#include <cstdio>
#include <cstdlib>
#include "renderer.h"

RenderSurface *createSurface(int w, int h) {
    // Screen definition
    RenderSurface *s = (RenderSurface*)malloc(sizeof(RenderSurface));
    if (!s) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }
    s->width = w;
    s->height = h;

    // Creating a framebuffer
    s->pixels = (vec3*)malloc(sizeof(vec3) * w * h);
    if (!s->pixels) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }
    
    return s;
}

void freeSurface(RenderSurface *s) {
    if (s == NULL) return;
    free(s->pixels);
    free(s);
    return;
}

void fillBuffer(RenderSurface* s, vec3 color) {
    for (int i = 0; i < (s->width * s->height); i++) {
        s->pixels[i] = color;
    }

    return;
}

vec2 normalize(RenderSurface *s, vec2 p) {
    float x_normalized = (p.x - s->width)/(s->width /* - surface minimun width, which is 0 in screen space */ );
    float y_normalized = (p.y - s->height)/(s->height);
    
    return vec2 {x_normalized, y_normalized};
}

vec2 inverseMapping(RenderSurface *s, vec2 p) {
    float x_inverse = ( (p.x)/2 ) * s->width;
    float y_inverse = ( (p.y)/2 ) * s->height;

    return vec2 {x_inverse, y_inverse};
}

void renderPPM(RenderSurface *s) {
    // PPM Header
    const char *magic = "P3";
    const char *color = "255";
    printf("%s\n%d %d\n%s\n", magic, s->width, s->height, color);

    vec3 *pixels = s->pixels;

    for (int i = 0; i < s->height ; i++) {
        for (int j = 0; j < s->width; j++) {
            vec3 currentRGB = pixels[i * s->width + j];
            printf("%d %d %d ", (int)currentRGB.x, (int)currentRGB.y, (int)currentRGB.z);
            fflush(stdout);
        }
        printf("\n");
    }
    return;
}

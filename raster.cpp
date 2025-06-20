#include <stdio.h>
#include "raster.h"

int drawHorizontal(RenderSurface* s, vec2 start, vec2 end) {
    if (start.y != end.y) {
        perror("Cannot compute different y values.");
        return -1;
    }

    /* What if it goes from left to right? Start is bigger than end! */
    float y = start.y;
    float x_start = (start.x < end.x) ? start.x : end.x;
    float x_end = (start.x < end.x) ? end.x : start.x;

    vec3 lineColor = {0, 0, 0};

    for (int i = x_start; i < x_end; i++) {
        s->pixels[(int)y * s->width + i] = lineColor;
    }

    return 0;
}

int drawVertical(RenderSurface* s, vec2 start, vec2 end) {
    if (start.x != end.x) {
        perror("Cannot compute different x values.");
        return -1;
    }

    /* What if it goes from downside to upside? Start is bigger than end! */
    float x = start.x;
    float y_start = (start.y < end.y) ? start.y : end.y;
    float y_end = (start.y < end.y) ? end.y : start.y;

    vec3 lineColor = {0, 0, 0};

    for (int i = y_start; i < y_end; i++) {
        s->pixels[i * s->width + (int)x] = lineColor;
    }

    return 0;
}

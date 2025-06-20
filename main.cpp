#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "vecalg.h"
#include "renderer.h"
#include "raster.h"

float ratioCalc(int w, int h) {
    float ratio = w/h;
    return ratio;
}

int main() {
    float aspectRatio = 16.0/9.0;

    // Defining screen
    int width, height;
    width = 800;
    height = width/aspectRatio;

    // Creating screen RenderSurface
    RenderSurface *screen; 
    screen = createSurface(width, height);
    vec3 *color = (vec3*)malloc(sizeof(vec3));
    setColor(color, 255, 0, 180);

    fillBuffer(screen, *color);

    vec2 verticeOne = {300, 150};
    vec2 verticeTwo = {100, 150};

    int res = drawHorizontal(screen, verticeOne, verticeTwo);
    if (res != 0) {
        return res;
    }

    verticeOne = {600, 400};
    verticeTwo = {600, 100};
    res = drawVertical(screen, verticeOne, verticeTwo); 
    if (res != 0) {
        return res;
    }

    // Rendering pixel display
    renderPPM(screen);
    freeSurface(screen);

    return 0;
}

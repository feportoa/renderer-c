#ifndef RENDERER_H
#define RENDERER_H
#include "vecalg.h"

typedef struct {
    int width, height;
    vec3 *pixels; // Framebuffer
} RenderSurface;

/**
 * @brief Renders the current space/framebufferfor a PPM image.
 *
 * @param RenderSurface Pointer to the rendering space to be rendered
 *
 * @note Writes only as plain P3 (ASCII) PPM format.
 */
void renderPPM(RenderSurface *s);

/**
 * @brief Create a RenderSurface
 *
 * Creates a RenderSurface containing a framebuffer.
 *
 * @param int w Width of the surface
 * @param int h Height of the surface
 * @return Pointer to the new RenderSurface
 *
 * @note Memory allocated to create space. Free it with freeSurface() function.
 */
RenderSurface *createSurface(int w, int h);

/**
 * @brief Frees memory allocated for space
 *
 * @param RenderSurface s Pointer to the space to free
 * @note Frees both the framebuffer and the RenderSurface struct.
 */
void freeSurface(RenderSurface *s);

/**
 * @brief Fills the framebuffer with the desired color.
 *
 * @param RenderSurface s Pointer to the RenderSurface/framebuffer
 * @param vec3 color The color to apply to all pixels
 */
void fillBuffer(RenderSurface *s, vec3 color);

/**
 * @brief Converts a point from screen space to device coordinates
 *
 * @param RenderSurface s Pointer to current rendering surface
 * @param vec2 p Point in screen coordinates
 *
 * @return vec2 Point normalized
 */
vec2 normalize(RenderSurface *s, vec2 p);

/**
 * @brief Converts a point from normalized space to screen coordinates
 * 
 * @param RenderSurface s Pointer to current rendering surface
 * @param vec2 p Point in normalized space
 */
vec2 inverseMapping(RenderSurface *s, vec2 p);

#endif

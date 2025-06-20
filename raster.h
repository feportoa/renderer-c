#ifndef RASTER_H
#define RASTER_H
#include "vecalg.h"
#include "renderer.h"

int drawHorizontal(RenderSurface *s, vec2 start, vec2 end);

int drawVertical(RenderSurface *s, vec2 start, vec2 end);

#endif

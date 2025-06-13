#include "vecalg.h"

// 2D Vectors
vec2 v2_add(vec2 a, vec2 b) {
    vec2 res = {a.x + b.x, a.y + b.y};
    return res;
}

vec2 v2_subtract(vec2 a, vec2 b) {
    vec2 res = {a.x - b.x, a.y - b.y};
    return res;
}

vec2 v2_scalar_multiplication(float a, vec2 b) {
    vec2 res = {a * b.x, a * b.y};
    return res;
}

float v2_dot(vec2 a, vec2 b) {
    vec2 multiplied = {a.x * b.x, a.y * b.y};
    float res = multiplied.x + multiplied.y;
    return res;
}

// To-Do 3D Vectors


// Color functions - Using vec3
void setColor(vec3 *vec, float r, float g, float b) {
    vec->x = r;
    vec->y = g;
    vec->z = b;
    return;
}


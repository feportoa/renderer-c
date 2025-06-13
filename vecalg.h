#ifndef VECALG_H
#define VECALG_H

typedef struct {
    float x;
    float y;
} vec2;

typedef struct {
    float x;
    float y;
    float z;
} vec3;

v2 v2_add(v2 a, v2 b); // Do NOT use pointers, can overwrite original values
v2 v2_subtract(v2 a, v2 b);
v2 v2_scalar_multiplication(float a, v2 b);
v2 v2_scalar_division(float a, v2 b);
float v2_dot(v2 a, v2 b);
float v2_cross(v2 a, v2 b);

#endif

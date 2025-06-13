#include "vecalg.h"

v2 v2_add(v2 a, v2 b) {
    v2 res = {a.x + b.x, a.y + b.y};
    return res;
}

v2 v2_subtract(v2 a, v2 b) {
    v2 res = {a.x - b.x, a.y - b.y};
    return res;
}

v2 v2_scalar_multiplication(float a, v2 b) {
    v2 res = {a * b.x, a * b.y};
    return res;
}

float v2_dot(v2 a, v2 b) {
    v2 multplied = {a.x * b.x, a.y * b.y};
    float res = multiplied.x + multiplied.y;
    return res;
}

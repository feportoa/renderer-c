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

/**
 * @brief Sum operation with 2 different vectors
 *
 * @param vec2 a First vector
 * @param vec2 b Second vector
 *
 * @return vec2 Returns a vector with the results
 */
vec2 v2_add(vec2 a, vec2 b); 

/**
 * @brief Subtraction operation with 2 different vectors
 *
 * @param vec2 a First vector
 * @param vec2 b Second vector
 *
 * @return vec2 Returns a vector with the results
 */
vec2 v2_subtract(vec2 a, vec2 b);

/**
 * @brief Multiplication between a scalar and a vector
 *
 * @param float a Scalar value
 * @param vec2 b Vector value
 *
 * @return vec2 Returns a vector with the results
 */
vec2 v2_scalar_multiplication(float a, vec2 b);

/**
 * @brief Division between a scalar and a vector
 *
 * @param float a Scalar value
 * @param vec2 b Vector value
 *
 * @return vec2 Returns a vector with the results
 */
vec2 v2_scalar_division(float a, vec2 b);

/**
 * @brief Makes a dot product operation
 *
 * @param vec2 a First vector
 * @param vec2 b Second vector
 *
 * @return Float with the result
 */
float v2_dot(vec2 a, vec2 b);

/**
 * @brief Modifies a specific vec3 color pointer 
 *
 * @param vec3 vec Pointer to your color vec3
 * @param r Red color
 * @param g Green color
 * @param b Blue color
 */
void setColor(vec3 *vec, float r, float g, float b);
#endif

/*

Copyright (c) 2023 Eugenio Arteaga A.

Permission is hereby granted, free of charge, to any 
person obtaining a copy of this software and associated 
documentation files (the "Software"), to deal in the 
Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice 
shall be included in all copies or substantial portions
of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef SIMPLE_PIXEL_MATH_H
#define SIMPLE_PIXEL_MATH_H

/******************
***** spxmath *****
 Simple PiXel Math
*******************
@Eugenio Arteaga A.
*******************

C89 header only math and linear algebra solution for
graphics, physics and game development.

****************************************************/

/* Useful Math Macros */

#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif /* DEFAULT_SOURCE */

#define SPXM_DIV(n) ((n) == 0.0F ? 0.0F : 1.0F / (n))
#define SPXM_ABS(n) (((n) >= 0) ? (n) : -(n))
#define SPXM_SIGN(n) (((n) >= 0) ? 1 : -1)
#define SPXM_MAX(n, m) (((n) > (m)) ? (n) : (m))
#define SPXM_MIN(n, m) (((n) < (m)) ? (n) : (m))
#define SPXM_CLAMP(n, min, max) (((n) > (max)) ? (max) : ((n) < (min)) ? (min) : (n))
#define SPXM_LERP(a, b, t) ((a) + (t) * ((b) - (a)))
#define SPXM_ILERP(min, max, n) (((max) - (min)) ? ((n) - (min)) / ((max) - (min)) : 0)

/* Simple Pixel Math */



#ifndef IVEC2_TYPE_DEFINED
#define IVEC2_TYPE_DEFINED

typedef struct ivec2 {
    int x, y;
} ivec2;

#endif /* IVEC2_TYPE_DEFINED */

#ifndef IVEC3_TYPE_DEFINED
#define IVEC3_TYPE_DEFINED

typedef struct ivec3 {
    int x, y, z;
} ivec3;

#endif /* IVEC3_TYPE_DEFINED */

#ifndef IVEC4_TYPE_DEFINED
#define IVEC4_TYPE_DEFINED

typedef struct ivec4 {
    int x, y, z, w;
} ivec4;

#endif /* IVEC4_TYPE_DEFINED */

#ifndef VEC2_TYPE_DEFINED
#define VEC2_TYPE_DEFINED

typedef struct vec2 {
    float x, y;
} vec2;

#endif /* VEC2_TYPE_DEFINED */

#ifndef VEC3_TYPE_DEFINED
#define VEC3_TYPE_DEFINED

typedef struct vec3 {
    float x, y, z;
} vec3;

#endif /* VEC3_TYPE_DEFINED */

#ifndef VEC4_TYPE_DEFINED
#define VEC4_TYPE_DEFINED

typedef struct vec4 {
    float x, y, z, w;
} vec4;

#endif /* VEC4_TYPE_DEFINED */

#ifndef MAT4_TYPE_DEFINED
#define MAT4_TYPE_DEFINED

typedef struct mat4 {
    float data[4][4];
} mat4;

#endif /* MAT4_TYPE_DEFINED */

float randf(void);
float absf(float n);
float signf(float n);
float maxf(float n, float m);
float minf(float n, float m);
float clampf(float n, float min, float max);
float lerpf(float a, float b, float t);
float ilerpf(float min, float max, float n);
float smoothlerpf(float a, float b, float t);
float remapf(float min, float max, float a, float b, float n);
float rad2deg(float rad);
float deg2rad(float deg);

vec2 vec2_rand(void);
vec2 vec2_uni(float n);
vec2 vec2_new(float x, float y);
vec2 vec2_add(vec2 p, vec2 q);
vec2 vec2_sub(vec2 p, vec2 q);
vec2 vec2_mult(vec2 p, float n);
vec2 vec2_div(vec2 p, float n);
vec2 vec2_norm(vec2 p);
vec2 vec2_cross(vec2 p, vec2 q);
vec2 vec2_prod(vec2 p, vec2 q);
vec2 vec2_lerp(vec2 p, vec2 q, float t);
vec2 vec2_from_rad(float rad);
float vec2_sqmag(vec2 p);
float vec2_mag(vec2 p);
float vec2_sqdist(vec2 p, vec2 q);
float vec2_dist(vec2 p, vec2 q);
float vec2_dot(vec2 p, vec2 q);
float vec2_rads(vec2 p);

#define vec2_rads_inline(p) atan2f(p.y, p.x)
#define vec2_sqmag_inline(p) (p.x * p.x + p.y * p.y)
#define vec2_mag_inline(p) sqrtf(p.x * p.x + p.y * p.y)
#define vec2_dot_inline(p, q) (p.x * q.x + p.y * q.y)
#define vec2_rads_inline(p) atan2f(p.y, p.x)
#define vec2_add_inline(p, q) do { p.x += q.x; p.y += q.y; } while (0)
#define vec2_sub_inline(p, q) do { p.x -= q.x; p.y -= q.y; } while (0)
#define vec2_prod_inline(p, q) do { p.x *= q.x; p.y *= q.y; } while (0)
#define vec2_mult_inline(p, n) do { p.x *= n; p.y *= n; } while (0)
#define vec2_div_inline(p, n) do { n = SPXM_DIV(n); p.x *= n; p.y *= n; } while (0)
#define vec2_norm_inline(p) do \
{ float n = vec2_mag_inline(p); vec2_mult_inline(p, n); } while (0)
#define vec2_lerp_inline(p, q, t) do \
{ p.x += t * (q.x - p.x); p.y += t * (q.y - p.y); } while (0)
#define vec2_cross_inline(p, q) do \
{ float n = p.x - q.x; p.x = -(p.y - q.y); p.y = n; } while (0)

vec3 vec3_rand(void);
vec3 vec3_uni(float n);
vec3 vec3_new(float x, float y, float z);
vec3 vec3_add(vec3 p, vec3 q);
vec3 vec3_sub(vec3 p, vec3 q);
vec3 vec3_mult(vec3 p, float f);
vec3 vec3_div(vec3 p, float f);
vec3 vec3_norm(vec3 p);
vec3 vec3_cross(vec3 p, vec3 q);
vec3 vec3_prod(vec3 p, vec3 q);
vec3 vec3_lerp(vec3 p, vec3 q, float t);
float vec3_sqmag(vec3 p);
float vec3_mag(vec3 p);
float vec3_sqdist(vec3 p, vec3 q);
float vec3_dist(vec3 p, vec3 q);
float vec3_dot(vec3 p, vec3 q);

vec4 vec4_rand(void);
vec4 vec4_uni(float n);
vec4 vec4_new(float x, float y, float z, float w);
vec4 vec4_add(vec4 p, vec4 q);
vec4 vec4_sub(vec4 p, vec4 q);
vec4 vec4_mult(vec4 p, float n);
vec4 vec4_div(vec4 p, float n);
vec4 vec4_norm(vec4 p);
vec4 vec4_prod(vec4 a, vec4 b);
vec4 vec4_lerp(vec4 a, vec4 b, float t);
float vec4_sqmag(vec4 p);
float vec4_mag(vec4 p);
float vec4_sqdist(vec4 p, vec4 q);
float vec4_dist(vec4 p, vec4 q);
float vec4_dot(vec4 p, vec4 q);
vec4 vec4_mult_mat4(vec4 p, mat4 m);

mat4 mat4_id(void);
mat4 mat4_zero(void);
mat4 mat4_translate(mat4 m, vec3 p);
mat4 mat4_mult(mat4 m1, mat4 m2);
mat4 mat4_mult_vec4(mat4 m, vec4 v);
mat4 mat4_mult_vec3(mat4 m, vec3 v);
mat4 mat4_scale(mat4 m, vec3 v);
mat4 mat4_rot(mat4 m, float deg, vec3 rot_axis);
mat4 mat4_perspective_RH(float fov, float aspect, float near, float far);
mat4 mat4_perspective_LH(float fov, float aspect, float near, float far);
mat4 mat4_look_at_RH(vec3 eye_position, vec3 eye_direction, vec3 eye_up);
mat4 mat4_look_at_LH(vec3 eye_position, vec3 eye_direction, vec3 eye_up);
mat4 mat4_ortho(float left, float right, float bottom, float top);
mat4 mat4_perspective(float fov, float aspect, float near, float far);
mat4 mat4_look_at(vec3 eye_position, vec3 eye_direction, vec3 eye_up);
mat4 mat4_model(vec3 translation, vec3 scale, vec3 rot_axis, float rot_degs);

vec2 vec2_from_ivec2(ivec2 p);
vec3 vec3_from_ivec3(ivec3 p);
vec4 vec4_from_ivec4(ivec4 p);
ivec2 ivec2_from_vec2(vec2 p);
ivec3 ivec3_from_vec3(vec3 p);
ivec4 ivec4_from_vec4(vec4 p);

#ifdef SPXM_APPLICATION

/******************
***** spxmath *****
 Simple PiXel Math
*******************
* IMPLEMENTATION  *
*******************/

#include <stdlib.h>
#include <math.h>

/* useful utilities and functions */

float randf(void)
{
	return (float)rand() / (float)RAND_MAX;
}

float absf(float n)
{
	return n < 0.0F ? -n : n;
}

float signf(float n)
{
	return n < 0.0F ? -1.0F : 1.0F;
}

float minf(float n, float m)
{
	return n < m ? n : m;
}

float maxf(float n, float m)
{
	return n > m ? n : m;
}

float clampf(float n, float min, float max)
{
	return n > max ? max : n < min ? min : n;
}

float lerpf(float a, float b, float t)
{
	return a + t * (b - a);
}

float smoothlerpf(float a, float b, float t)
{
	return a + (t * t * (3.0 - 2.0 * t)) * (b - a);
}

float ilerpf(float min, float max, float n)
{
	return (max - min) != 0.0F ? (n - min) / (max - min) : 0.0F;
}

float remapf(float min, float max, float a, float b, float n)
{
	return lerpf(a, b, ilerpf(min, max, n));
}

float rad2deg(float rad)
{
	return rad * (180.0F / M_PI);
}

float deg2rad(float deg)
{
	return deg / (180.0F / M_PI);
}

/* vec2 implementation */

vec2 vec2_rand(void)
{
    vec2 p;
    p.x = randf();
    p.y = randf();
    return p;
}

vec2 vec2_uni(float n)
{
    vec2 p;
    p.x = n;
    p.y = n;
    return p;
}

vec2 vec2_new(float x, float y)
{ 
    vec2 p;
    p.x = x;
    p.y = y; 
    return p;
}

vec2 vec2_add(vec2 p, vec2 q)
{
    p.x += q.x;
    p.y += q.y;
    return p;
}

vec2 vec2_sub(vec2 p, vec2 q)
{
	p.x -= q.x;
    p.y -= q.y;
    return p;
}

vec2 vec2_mult(vec2 p, float n)
{
    p.x *= n;
    p.y *= n;
    return p;
}

vec2 vec2_div(vec2 p, float n)
{
	n = n == 0.0F ? 0.0F : 1.0F / n; 
    p.x *= n;
    p.y *= n;
    return p;
}

vec2 vec2_norm(vec2 p)
{
    float n = sqrtf(p.x * p.x + p.y * p.y);
    n = n == 0.0F ? 0.0F : 1.0F / n;
    p.x *= n;
    p.y *= n;
    return p;
}

vec2 vec2_cross(vec2 p, vec2 q)
{
	float y = p.x - q.x;
    p.x = -(p.y - q.y),
    p.y = y;
    return p;
}

vec2 vec2_prod(vec2 p, vec2 q)
{
    p.x *= q.x;
    p.y *= q.y;
    return p;
}

vec2 vec2_lerp(vec2 p, vec2 q, float t)
{
    p.x += t * (q.x - p.x);
    p.y += t * (q.y - p.y);
    return p;
}

vec2 vec2_from_rad(float rad)
{
	vec2 p;
    p.x = cosf(rad);
    p.y = sinf(rad);
    return p;
}

float vec2_sqmag(vec2 p)
{
	return p.x * p.x + p.y * p.y;
}

float vec2_mag(vec2 p)
{
	return sqrtf(p.x * p.x + p.y * p.y);
}

float vec2_sqdist(vec2 p, vec2 q)
{
    p.x -= q.x;
    p.y -= q.y;
	return p.x * p.x + p.y * p.y;
}

float vec2_dist(vec2 p, vec2 q)
{
    p.x -= q.x;
    p.y -= q.y;
	return sqrtf(p.x * p.x + p.y * p.y);
}

float vec2_dot(vec2 p, vec2 q)
{
	return p.x * q.x + p.y * q.y;
}

float vec2_rads(vec2 p)
{
	return atan2f(p.y, p.x);
}

/* vec3 implementation */

vec3 vec3_rand(void)
{
    vec3 p;
    p.x = randf();
    p.y = randf();
    p.z = randf();
    return p;
}

vec3 vec3_uni(float n)
{
    vec3 p;
    p.x = n;
    p.y = n;
    p.z = n;
    return p;
}

vec3 vec3_new(float x, float y, float z)
{
    vec3 p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

vec3 vec3_add(vec3 p, vec3 q)
{
    p.x += q.x;
    p.y += q.y;
    p.z += q.z;
    return p;
}

vec3 vec3_sub(vec3 p, vec3 q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z;
    return p;
}

vec3 vec3_mult(vec3 p, float n)
{
    p.x *= n;
    p.y *= n;
    p.z *= n;
    return p;
}

vec3 vec3_div(vec3 p, float n)
{
    n = n == 0.0F ? 0.0F : 1.0F / n;
    p.x *= n;
    p.y *= n;
    p.z *= n;
    return p;
}

vec3 vec3_norm(vec3 p)
{
    float n = sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
    n = n == 0.0F ? 0.0F : 1.0F / n;
    p.x *= n;
    p.y *= n;
    p.z *= n;
    return p;
}

vec3 vec3_cross(vec3 p, vec3 q)
{
    vec3 v;
    v.x = p.y * q.z - q.y * p.z;
    v.y = p.z * q.x - q.z * p.x;
    v.z = p.x * q.y - q.x * p.y;
    return v;
}

vec3 vec3_prod(vec3 p, vec3 q)
{
    p.x *= q.x;
    p.y *= q.y;
    p.z *= q.z;
    return p;
}

vec3 vec3_lerp(vec3 p, vec3 q, float t)
{
    p.x += t * (q.x - p.x);
    p.y += t * (q.y - p.y);
    p.z += t * (q.z - p.z);
    return p;
}

float vec3_sqmag(vec3 p)
{
    return p.x * p.x + p.y * p.y + p.z * p.z; 
}

float vec3_mag(vec3 p)
{
    return sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
}

float vec3_sqdist(vec3 p, vec3 q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z;
    return p.x * p.x + p.y * p.y + p.z * p.z; 
}

float vec3_dist(vec3 p, vec3 q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z; 
    return sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
}

float vec3_dot(vec3 p, vec3 q)
{
    return p.x * q.x + p.y * q.y + p.z * q.z;
}

/* vec4 implementation */

vec4 vec4_rand(void)
{
    vec4 p;
    p.x = randf();
    p.y = randf();
    p.z = randf();
    p.w = randf();
    return p;
}

vec4 vec4_uni(float n)
{
    vec4 p;
    p.x = n;
    p.y = n;
    p.z = n;
    p.w = n;
    return p;
}

vec4 vec4_new(float x, float y, float z, float w)
{
    vec4 p;
    p.x = x;
    p.y = y;
    p.z = z;
    p.w = w;
    return p;
}

vec4 vec4_add(vec4 p, vec4 q)
{
    p.x += q.x;
    p.y += q.y;
    p.z += q.z;
    p.w += q.w;
    return p;
}

vec4 vec4_sub(vec4 p, vec4 q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z;
    p.w -= q.w;
    return p;
}

vec4 vec4_mult(vec4 p, float n)
{
    p.x *= n;
    p.y *= n;
    p.z *= n;
    p.w *= n;
    return p;
}

vec4 vec4_div(vec4 p, float n)
{
    n = n == 0.0F ? 0.0F : 1.0F / n; 
    p.x *= n;
    p.y *= n;
    p.z *= n;
    p.w *= n;
    return p;
}

vec4 vec4_norm(vec4 p)
{
    float n = sqrtf(p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w);
    n = n == 0.0F ? 0.0F : 1.0F / n;
    p.x *= n;
    p.y *= n;
    p.z *= n;
    p.w *= n;
    return p;
}

vec4 vec4_prod(vec4 p, vec4 q)
{
    p.x *= q.x;
    p.y *= q.y;
    p.z *= q.z;
    p.w *= q.w;
    return p;
}

vec4 vec4_lerp(vec4 p, vec4 q, float t)
{ 
    p.x += t * (q.x - p.x);
    p.y += t * (q.y - p.y);
    p.z += t * (q.z - p.z);
    p.w += t * (q.w - p.w);
    return p;
}

float vec4_sqmag(vec4 p)
{
    return p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w;
}

float vec4_mag(vec4 p)
{
    return sqrtf(p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w);
}

float vec4_sqdist(vec4 p, vec4 q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z;
    p.w -= q.w;
    return p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w;
}

float vec4_dist(vec4 p, vec4 q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z;
    p.w -= q.w;
    return sqrtf(p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w);
}

float vec4_dot(vec4 p, vec4 q)
{
    return p.x * q.x + p.y * q.y + p.z * q.z + p.w * q.w;
}

vec4 vec4_mult_mat4(vec4 p, mat4 m)
{
    vec4 q;
    q.x = p.x * m.data[0][0] + p.y * m.data[1][0] + p.z * m.data[2][0] + p.w * m.data[3][0];
    q.y = p.x * m.data[0][1] + p.y * m.data[1][1] + p.z * m.data[2][1] + p.w * m.data[3][1];
    q.z = p.x * m.data[0][2] + p.y * m.data[1][2] + p.z * m.data[2][2] + p.w * m.data[3][2];
    q.w = p.x * m.data[0][3] + p.y * m.data[1][3] + p.z * m.data[2][3] + p.w * m.data[3][3];
    return q;
}

/* 4 x 4 matrix operations */

mat4 mat4_id(void)
{
    mat4 m = {{
        {1.0F, 0.0F, 0.0F, 0.0F},
        {0.0F, 1.0F, 0.0F, 0.0F},
        {0.0F, 0.0F, 1.0F, 0.0F},
        {0.0F, 0.0F, 0.0F, 1.0F}
    }};
    return m;
}

mat4 mat4_zero(void)
{
    mat4 m = {{{0.0F}}};
    return m;
}

mat4 mat4_translate(mat4 m, vec3 p)
{
    m.data[3][0] = p.x;
    m.data[3][1] = p.y;
    m.data[3][2] = p.z;
    return m;
}

mat4 mat4_mult(mat4 m1, mat4 m2)
{
    mat4 m;
    m.data[0][0] = m1.data[0][0] * m2.data[0][0] + m1.data[1][0] * m2.data[0][1] + m1.data[2][0] * m2.data[0][2] + m1.data[3][0] * m2.data[0][3];
    m.data[0][1] = m1.data[0][1] * m2.data[0][0] + m1.data[1][1] * m2.data[0][1] + m1.data[2][1] * m2.data[0][2] + m1.data[3][1] * m2.data[0][3];
    m.data[0][2] = m1.data[0][2] * m2.data[0][0] + m1.data[1][2] * m2.data[0][1] + m1.data[2][2] * m2.data[0][2] + m1.data[3][2] * m2.data[0][3];
    m.data[0][3] = m1.data[0][3] * m2.data[0][0] + m1.data[1][3] * m2.data[0][1] + m1.data[2][3] * m2.data[0][2] + m1.data[3][3] * m2.data[0][3];
    m.data[1][0] = m1.data[0][0] * m2.data[1][0] + m1.data[1][0] * m2.data[1][1] + m1.data[2][0] * m2.data[1][2] + m1.data[3][0] * m2.data[1][3];
    m.data[1][1] = m1.data[0][1] * m2.data[1][0] + m1.data[1][1] * m2.data[1][1] + m1.data[2][1] * m2.data[1][2] + m1.data[3][1] * m2.data[1][3];
    m.data[1][2] = m1.data[0][2] * m2.data[1][0] + m1.data[1][2] * m2.data[1][1] + m1.data[2][2] * m2.data[1][2] + m1.data[3][2] * m2.data[1][3];
    m.data[1][3] = m1.data[0][3] * m2.data[1][0] + m1.data[1][3] * m2.data[1][1] + m1.data[2][3] * m2.data[1][2] + m1.data[3][3] * m2.data[1][3];
    m.data[2][0] = m1.data[0][0] * m2.data[2][0] + m1.data[1][0] * m2.data[2][1] + m1.data[2][0] * m2.data[2][2] + m1.data[3][0] * m2.data[2][3];
    m.data[2][1] = m1.data[0][1] * m2.data[2][0] + m1.data[1][1] * m2.data[2][1] + m1.data[2][1] * m2.data[2][2] + m1.data[3][1] * m2.data[2][3];
    m.data[2][2] = m1.data[0][2] * m2.data[2][0] + m1.data[1][2] * m2.data[2][1] + m1.data[2][2] * m2.data[2][2] + m1.data[3][2] * m2.data[2][3];
    m.data[2][3] = m1.data[0][3] * m2.data[2][0] + m1.data[1][3] * m2.data[2][1] + m1.data[2][3] * m2.data[2][2] + m1.data[3][3] * m2.data[2][3];
    m.data[3][0] = m1.data[0][0] * m2.data[3][0] + m1.data[1][0] * m2.data[3][1] + m1.data[2][0] * m2.data[3][2] + m1.data[3][0] * m2.data[3][3];
    m.data[3][1] = m1.data[0][1] * m2.data[3][0] + m1.data[1][1] * m2.data[3][1] + m1.data[2][1] * m2.data[3][2] + m1.data[3][1] * m2.data[3][3];
    m.data[3][2] = m1.data[0][2] * m2.data[3][0] + m1.data[1][2] * m2.data[3][1] + m1.data[2][2] * m2.data[3][2] + m1.data[3][2] * m2.data[3][3];
    m.data[3][3] = m1.data[0][3] * m2.data[3][0] + m1.data[1][3] * m2.data[3][1] + m1.data[2][3] * m2.data[3][2] + m1.data[3][3] * m2.data[3][3];
    return m;
}

mat4 mat4_mult_vec4(mat4 m, vec4 p)
{
    m.data[0][0] *= p.x;
    m.data[0][1] *= p.x;
    m.data[0][2] *= p.x;
    m.data[0][3] *= p.x;
    m.data[1][0] *= p.y;
    m.data[1][1] *= p.y;
    m.data[1][2] *= p.y;
    m.data[1][3] *= p.y;
    m.data[2][0] *= p.z;
    m.data[2][1] *= p.z;
    m.data[2][2] *= p.z;
    m.data[2][3] *= p.z;
    m.data[3][0] *= p.w;
    m.data[3][1] *= p.w;
    m.data[3][2] *= p.w;
    m.data[3][3] *= p.w;
    return m;
}

mat4 mat4_mult_vec3(mat4 m, vec3 p)
{
    m.data[0][0] *= p.x;
    m.data[0][1] *= p.x;
    m.data[0][2] *= p.x;
    m.data[0][3] *= p.x;
    m.data[1][0] *= p.y;
    m.data[1][1] *= p.y;
    m.data[1][2] *= p.y;
    m.data[1][3] *= p.y;
    m.data[2][0] *= p.z;
    m.data[2][1] *= p.z;
    m.data[2][2] *= p.z;
    m.data[2][3] *= p.z;
    return m;
}

mat4 mat4_scale(mat4 m, vec3 p)
{
    mat4 M = {{{0.0F}}};
    M.data[0][0] = p.x;
    M.data[1][1] = p.y;
    M.data[2][2] = p.z;
    M.data[3][3] = 1.0F;
    return mat4_mult(M, m);
}

mat4 mat4_rot(mat4 mat, float deg, vec3 rot_axis)
{
    float c, s;
    vec3 axis, temp;
    mat4 rot = {{{0.0F}}}, m = {{{0.0F}}};

    c = cosf(deg);
    s = sinf(deg);

    axis = vec3_norm(rot_axis);
	temp = vec3_mult(axis, 1.0f - c);

    rot.data[0][0] = c + temp.x * axis.x;
    rot.data[0][1] = temp.x * axis.y + s * axis.z;
    rot.data[0][2] = temp.x * axis.z - s * axis.y;
    rot.data[1][0] = temp.y * axis.x - s * axis.z;
    rot.data[1][1] = c + temp.y * axis.y;
    rot.data[1][2] = temp.y * axis.z + s * axis.x;
    rot.data[2][0] = temp.z * axis.x + s * axis.y;
    rot.data[2][1] = temp.z * axis.y - s * axis.x;
    rot.data[2][2] = c + temp.z * axis.z;

    m.data[0][0] = mat.data[0][0] * rot.data[0][0] + mat.data[1][0] * rot.data[0][1] + mat.data[2][0] * rot.data[0][2];
    m.data[0][1] = mat.data[0][1] * rot.data[0][0] + mat.data[1][1] * rot.data[0][1] + mat.data[2][1] * rot.data[0][2];
    m.data[0][2] = mat.data[0][2] * rot.data[0][0] + mat.data[1][2] * rot.data[0][1] + mat.data[2][2] * rot.data[0][2];
    m.data[1][0] = mat.data[0][0] * rot.data[1][0] + mat.data[1][0] * rot.data[1][1] + mat.data[2][0] * rot.data[1][2];
    m.data[1][1] = mat.data[0][1] * rot.data[1][0] + mat.data[1][1] * rot.data[1][1] + mat.data[2][1] * rot.data[1][2];
    m.data[1][2] = mat.data[0][2] * rot.data[1][0] + mat.data[1][2] * rot.data[1][1] + mat.data[2][2] * rot.data[1][2];
    m.data[2][0] = mat.data[0][0] * rot.data[2][0] + mat.data[1][0] * rot.data[2][1] + mat.data[2][0] * rot.data[2][2];
    m.data[2][1] = mat.data[0][1] * rot.data[2][0] + mat.data[1][1] * rot.data[2][1] + mat.data[2][1] * rot.data[2][2];
    m.data[2][2] = mat.data[0][2] * rot.data[2][0] + mat.data[1][2] * rot.data[2][1] + mat.data[2][2] * rot.data[2][2];
    m.data[3][0] = mat.data[3][0];
    m.data[3][1] = mat.data[3][1];
    m.data[3][2] = mat.data[3][2];
    m.data[3][3] = mat.data[3][3];
    return m;
}

mat4 mat4_perspective_RH(float fov, float aspect, float near, float far)
{
    mat4 m = {{{0.0F}}};
    float tan_half_fov = tanf(fov / 2.0f);
    m.data[0][0] = 1.0f / (aspect * tan_half_fov);
    m.data[1][1] = 1.0f / tan_half_fov;
    m.data[2][2] = (far + near) / (far - near);
    m.data[2][3] = 1.0f;
    m.data[3][2] = (2.0f * far * near) / (far - near);
    return m;
}

mat4 mat4_perspective_LH(float fov, float aspect, float near, float far)
{
    mat4 m = {{{0.0F}}};
    float tan_half_fov = tanf(fov / 2.0f);
    m.data[0][0] = 1.0f / (aspect * tan_half_fov);
    m.data[1][1] = 1.0f / tan_half_fov;
    m.data[2][2] = (far + near) / (far - near);
    m.data[2][3] = 1.0f;
    m.data[3][2] = - (2.0f * far * near) / (far - near);
    return m;
}

mat4 mat4_look_at_RH(vec3 eye_position, vec3 eye_direction, vec3 eye_up)
{
    vec3 f, s, u;
    mat4 m = {{{0.0F}}};
    f = vec3_norm(vec3_sub(eye_direction, eye_position));
    s = vec3_norm(vec3_cross(f, eye_up));
    u = vec3_cross(s, f);
    m.data[0][0] = s.x;
    m.data[1][0] = s.y;
    m.data[2][0] = s.z;
    m.data[0][1] = u.x;
    m.data[1][1] = u.y;
    m.data[2][1] = u.z;
    m.data[0][2] = -f.x;
    m.data[1][2] = -f.y;
    m.data[2][2] = -f.z;
    m.data[3][0] = -vec3_dot(s, eye_position);
    m.data[3][1] = -vec3_dot(u, eye_position);
    m.data[3][2] = vec3_dot(f, eye_position);
    m.data[3][3] = 1.0f;
    return m;
}

mat4 mat4_look_at_LH(vec3 eye_position, vec3 eye_direction, vec3 eye_up)
{
    vec3 f, s, u;
    mat4 m = {{{0.0F}}};
    f = vec3_norm(vec3_sub(eye_direction, eye_position));
    s = vec3_norm(vec3_cross(eye_up, f));
    u = vec3_cross(f, s);
    m.data[0][0] = s.x;
    m.data[1][0] = s.y;
    m.data[2][0] = s.z;
    m.data[0][1] = u.x;
    m.data[1][1] = u.y;
    m.data[2][1] = u.z;
    m.data[0][2] = f.x;
    m.data[1][2] = f.y;
    m.data[2][2] = f.z;
    m.data[3][0] = -vec3_dot(s, eye_position);
    m.data[3][1] = -vec3_dot(u, eye_position);
    m.data[3][2] = -vec3_dot(f, eye_position);
    m.data[3][3] = 1.0f;
    return m;
}

mat4 mat4_ortho(float left, float right, float bottom, float top)
{
    mat4 ret = mat4_id();
    ret.data[0][0] = 2.0f / (right - left);
    ret.data[1][1] = 2.0f / (top - bottom);
    ret.data[2][2] = - 1.0f;
    ret.data[3][0] = - (right + left) / (right - left);
    ret.data[3][1] = - (top + bottom) / (top - bottom);
    return ret;
}

mat4 mat4_perspective(float fov, float aspect, float near, float far)
{
    return mat4_perspective_RH(fov, aspect, near, far);
}

mat4 mat4_look_at(vec3 eye_position, vec3 eye_direction, vec3 eye_up)
{
    return mat4_look_at_RH(eye_position, eye_direction, eye_up);
}

mat4 mat4_model(vec3 translation, vec3 scale, vec3 rot_axis, float rot_degs)
{
    mat4 model = mat4_scale(mat4_id(), scale);
    model = mat4_rot(model, rot_degs, rot_axis);
    model = mat4_translate(model, translation);
    return model;
}

/* convert betwen integer and float vector types */

vec2 vec2_from_ivec2(ivec2 p)
{
    vec2 q;
    q.x = (float)p.x;
    q.y = (float)p.y;
    return q;
}

vec3 vec3_from_ivec3(ivec3 p)
{
    vec3 q;
    q.x = (float)p.x;
    q.y = (float)p.y;
    q.z = (float)p.z;
    return q;
}

vec4 vec4_from_ivec4(ivec4 p)
{
    vec4 q;
    q.x = (float)p.x;
    q.y = (float)p.y;
    q.z = (float)p.z;
    q.w = (float)p.w;
    return q;
}

ivec2 ivec2_from_vec2(vec2 p)
{
	ivec2 q;
    q.x = (int)p.x;
    q.y = (int)p.y;
    return q;
}

ivec3 ivec3_from_vec3(vec3 p)
{
	ivec3 q;
    q.x = (int)p.x;
    q.y = (int)p.y;
    q.z = (int)p.z;
    return q;
}

ivec4 ivec4_from_vec4(vec4 p)
{
	ivec4 q;
    q.x = (int)p.x;
    q.y = (int)p.y;
    q.z = (int)p.z;
    q.w = (int)p.w;
    return q;
}

#endif /* SPXM_APPLICATION */
#endif /* SIMPLE_PIXEL_MATH_H */


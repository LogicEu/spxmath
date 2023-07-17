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

#define SPXM_ABS(n) (((n) >= 0) ? (n) : -(n))
#define SPXM_SIGN(n) (((n) >= 0) ? 1 : -1)
#define SPXM_MAX(n, m) (((n) > (m)) ? (n) : (m))
#define SPXM_MIN(n, m) (((n) < (m)) ? (n) : (m))
#define SPXM_CLAMP(n, min, max) (((n) > (max)) ? (max) : ((n) < (min)) ? (min) : (n))
#define SPXM_LERP(a, b, t) ((a) + (t) * ((b) - (a)))
#define SPXM_ILERP(min, max, n) (((max) - (min)) ? ((n) - (min)) / ((max) - (min)) : 0)

/* Simple Pixel Math */

typedef struct ivec2 {
    int x, y;
} ivec2;

typedef struct ivec3 {
    int x, y, z;
} ivec3;

typedef struct ivec4 {
    int x, y, z, w;
} ivec4;

typedef struct vec2 {
    float x, y;
} vec2;

typedef struct vec3 {
    float x, y, z;
} vec3;

typedef struct vec4 {
    float x, y, z, w;
} vec4;

float randf(void);
float absf(float n);
float signf(float n);
float maxf(float n, float m);
float minf(float n, float m);
float clampf(float n, float min, float max);
float lerpf(float a, float b, float t);
float ilerpf(float min, float max, float n);
float smootlerpf(float a, float b, float t);
float remapf(float min, float max, float a, float b, float n);
float rad2deg(float rad);
float deg2rad(float deg);

vec2 vec2_rand(void);
vec2 vec2_new(float x, float y);
vec2 vec2_add(vec2 p, vec2 q);
vec2 vec2_sub(vec2 p, vec2 q);
vec2 vec2_mult(vec2 p, float n);
vec2 vec2_div(vec2 p, float n);
vec2 vec2_norm(vec2 p);
vec2 vec2_cross(vec2 p, vec2 q);
vec2 vec2_lerp(vec2 a, vec2 b, float t);
vec2 rad2vec2(float rad);
float vec2_dot(vec2 p, vec2 q);
float vec2_sqmag(vec2 p);
float vec2_mag(vec2 p);
float vec2_to_rad(vec2 p);

vec2 vec2_from_ivec2(ivec2 p);
ivec2 ivec2_from_vec2(vec2 p);

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

float smootlerpf(float a, float b, float t)
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

vec2 vec2_lerp(vec2 a, vec2 b, float t)
{
    a.x = a.x + t * (b.x - a.x);
    a.y = a.y + t * (b.y - a.y);
    return a;
}

vec2 rad2vec2(float rad)
{
	vec2 p;
    p.x = cosf(rad);
    p.y = sinf(rad);
    return p;
}

float vec2_dot(vec2 p, vec2 q)
{
	return p.x * q.x + p.y * q.y;
}

float vec2_sqmag(vec2 p)
{
	return p.x * p.x + p.y * p.y;
}

float vec2_mag(vec2 p)
{
	return sqrtf(p.x * p.x + p.y * p.y);
}

float vec2_to_rad(vec2 p)
{
	return atan2f(p.y, p.x);
}

/* convert betwen integer and float vector types */

vec2 vec2_from_ivec2(ivec2 p)
{
    vec2 q;
    q.x = (float)p.x;
    q.y = (float)p.y;
    return q;
}

ivec2 ivec2_from_vec2(vec2 p)
{
	ivec2 q;
    q.x = (int)p.x;
    q.y = (int)p.y;
    return q;
}

#endif /* SPXM_APPLICATION */
#endif /* SIMPLE_PIXEL_MATH_H */


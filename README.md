# spxmath

Simple header only math library for graphics, physics and game development in C.
From vector, matrixes, to pseudo-random number generators and other useful math
functions.

This header is part of the [spxx](https://github.com/LogicEu/spxx.git) project and 
it is compatible across platforms from C89 trough C++20. Perfectly suitable for
doing CPU math for OpenGL applications, similar to libraries like 
[glm](https://github.com/g-truc/glm.git).

## Header-Only

As a header only solution, you need to define 
SPXM_APPLICATION before including spxmath.h to access the
implementation details. Otherwise you only declare the interface.

```C
#define SPXM_APPLICATION
#include <spxmath.h>
```

## Dependencies

The only external dependencies are the C standard library and the standard C math
library. The only header included by the implementation is math.h

```shell
gcc source.c -o program -lm
```

## API

Generic but very useful functions

```C


float absf(float n); // returns the absolute value of n
float signf(float n); // returns -1.0 or 1.0 depending on the sign of n
float maxf(float n, float m); // returns the maximum value between n and m
float minf(float n, float m); // returns the minimum value between n and m
float clampf(float n, float min, float max); // returns n clamped between n and m
float lerpf(float a, float b, float t); // returns the linear interpolation of a to b at t
float ilerpf(float min, float max, float n); // returns the inverse linear interpolation
float smoothlerpf(float a, float b, float t); // returns a smoother linear interpolation
float remapf(float min, float max, float a, float b, float n); // remaps coordinates
float rad2deg(float rad); // radians to degrees
float deg2rad(float deg); // degrees to radians


```

There are some useful platform independent pseudo-random number generator functions.


```C

float        spxrandf(void); // returns a normalized random value between 0.0 and 1.0
unsigned int spxrand(void); // returns and unsigned integer between 0 and SPXM_RANDMAX
unsigned int spxrand_hash(unsigned int n); // returns a pseudo-random hash seeded at n
void         spxrand_seed_set(unsigned int n); // sets a new seed for all random functions
unsigned int spxrand_seed_get(void); // gets the current seed

```

The main types implemented by spxmath.h are the following:

```C

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


```


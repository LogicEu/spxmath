# spxmath

Simple header only math library for graphics, physics and game development in C.
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
library. The only headers included by the implementation are stdlib.h and math.h

```shell
gcc source.c -o program -lm
```

## API

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

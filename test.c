#define SPXM_APPLICATION
#include <spxmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(int argc, char** argv)
{
    int i, count = 100;
    float min = FLT_MAX, max = FLT_MIN, sum = 0.0F;

    if (argc > 1) {
        count = atoi(argv[1]);
        spxrand_seed_set(argc > 2 ? atoi(argv[2]) : 0);
    }

    for (i = 0; i < count; ++i) {
        float m = spxrandf();
        printf("%f\n", m);
        min = m < min ? m : min;
        max = m > max ? m : max;
        sum += m;
    }

    printf("min: %f\n", min);
    printf("max: %f\n", max);
    printf("average: %f\n", sum / (float)count);
    return 0;
}


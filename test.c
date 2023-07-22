#define SPXM_APPLICATION
#include <spxmath.h>

int main(void)
{
    float n;
    vec2 a2, b2, c2;
    a2 = vec2_rand();
    b2 = vec2_uni(1.0F);
    c2 = vec2_new(0.0F, 1.0F);
    c2 = vec2_add(vec2_sub(a2, b2), vec2_prod(a2, c2));
    n = vec2_mag(c2);
    return (int)n;
}

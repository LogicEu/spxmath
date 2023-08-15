#define SPXM_APPLICATION
#include <spxmath.h>

int main(void)
{
    float n;
    vec2 a, b, c;
    mat4 m;

    a = vec2_rand();
    b = vec2_uni(1.0F);
    c = vec2_new(0.0F, 1.0F);
    c = vec2_add(vec2_sub(a, b), vec2_prod(a, c));
    n = vec2_mag(c);    
    m = mat4_id();
    return (int)(n * m.data[0][0]);
}

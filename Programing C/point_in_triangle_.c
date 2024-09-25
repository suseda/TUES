#include <stdio.h>

struct point { float x, y; };
struct triangle { struct point a, b, c; };

double triangle_face(struct point p1, struct point p2, struct point p3)
{
    double face = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;
    return (face > 0) ? (face) : (-face);
}

int z_buffer(struct triangle triangles[], int count, struct point p)
{
    for (int i = 0; i < count; i++)
        if (triangle_face(p, triangles[i].b, triangles[i].c) + triangle_face(p, triangles[i].a, triangles[i].c) + triangle_face(p, triangles[i].b, triangles[i].a) <= triangle_face(triangles[i].a, triangles[i].b, triangles[i].c))
            return i;
    return -1;
}

void main()
{
    struct triangle a[2] = { { {-2, -2}, {4, -2}, {0, 1} }, { {2, 2}, {10, 2}, {4, 7} } };
    struct point p = { 4,4 };
    printf("Index: %d", z_buffer(a, 2, p));
}

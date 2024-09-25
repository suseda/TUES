

struct point
{
    float x, y;
};
struct triangle
{
    struct point a, b, c;
};
float triangle_face(struct triangle t)
{
    int res = (t.a.x * (t.b.y - t.c.y) + t.b.x * (t.c.y - t.a.y) + t.c.x * (t.a.y - t.b.y)) / 2;
    if (res < 0)
        res = -res;
    return res;
}

enum { no, yes } inside_triangle(struct triangle t, struct point p)
{
    struct triangle t1 = { t.a, t.b, p };
    struct triangle t2 = { t.b, t.c, p };
    struct triangle t3 = { t.c, t.a, p };
    struct triangle ts = { t.a, t.b, t.c };
    return (triangle_face(t1) + triangle_face(t2) + triangle_face(t3)) <= triangle_face(ts);
}

int z_buffer(struct triangle triangles[], int count, struct point p)
{
    int i = 0;
    while (count--)
    {
        float res = inside_triangle(triangles[i], p);
        if (res == yes)
            return i;
        i++;
    }
    return -1;
}
void main()
{
    struct triangle a[] = { {{1, 2}, {2, 1}, {3, 3}}, {{4, 0}, {3, 2}, {6, 3}} };
    struct point p = { 4, 2 };
    int res = z_buffer(a, 2, p);
}
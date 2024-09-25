struct point
{
    double x, y;
};

double triangle_face(struct point a, struct point b, struct point c)
{
    double face;
    face = ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y))) / 2;
    if (face < 0)
        face = -face;
    return face;
}

double convex_polygon_face(struct point* convex_polygon, unsigned points)
{
    double face = 0;
    for (int a = 1, b = 2; b < points;)
        face += triangle_face(*convex_polygon, convex_polygon[a++], convex_polygon[b++]);
    return face;
}

void main()
{
    struct point a[] = { {1,-7},{-3,5},{9,7},{19,0},{15,-5},{10,-9} };
    convex_polygon_face(a, 6);
}
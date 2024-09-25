#define SWAP(t, x, y) \
    {                 \
        t z = *(x);   \
        *(x) = *(y);  \
        *(y) = z;     \
    }
struct point
{
    float x, y;
};
struct section
{
    struct point start, end;
};
struct triangle
{
    struct point a, b, c;
};

unsigned triangle_face(struct triangle t)
{
    int res = (t.a.x * (t.b.y - t.c.y) + t.b.x * (t.c.y - t.a.y) + t.c.x * (t.a.y - t.b.y)) / 2;
    return res;
}

double min(double a, double b)
{
    if (a < b)
        return a;
    return b;
}

double max(double a, double b)
{
    if (a > b)
        return a;
    return b;
}
enum bool
{
    false,
    true
};

enum bool find_intersection(struct point* result, struct section a, struct section b)
{
    double g = ((a.start.x - a.end.x) * (b.start.y - b.end.y) - (a.start.y - a.end.y) * (b.start.x - b.end.x));
    if (g == 0)
        return false;
    result->x = ((a.start.x * a.end.y - a.start.y * a.end.x) * (b.start.x - b.end.x) - (a.start.x - a.end.x) * (b.start.x * b.end.y - b.start.y * b.end.x)) / g;
    result->y = ((a.start.x * a.end.y - a.start.y * a.end.x) * (b.start.y - b.end.y) - (a.start.y - a.end.y) * (b.start.x * b.end.y - b.start.y * b.end.x)) / g;

    int min_x_a = min(a.start.x, a.end.x);
    int max_x_a = max(a.start.x, a.end.x);
    int min_x_b = min(b.start.x, b.end.x);
    int max_x_b = max(b.start.x, b.end.x);

    int min_y_a = min(a.start.y, a.end.y);
    int max_y_a = max(a.start.y, a.end.y);
    int min_y_b = min(b.start.y, b.end.y);
    int max_y_b = max(b.start.y, b.end.y);

    return min_x_a <= result->x && result->x <= max_x_a &&
        min_x_b <= result->x && result->x <= max_x_b &&
        min_y_a <= result->y && result->y <= max_y_a &&
        min_y_b <= result->y && result->y <= max_y_b;
}
enum bool inside(struct point* a, struct point x)
{

    struct point* start = a, * end = a + 1;
    int s = 0;
    struct triangle t = { *start, *end, x };
    if (triangle_face(t) < 0)
    {
        for (; start->x != end->x && start->y != end->y; start++, end++)
            if (triangle_face(t) > 0)
                return false;
    }
    else
    {
        for (; start->x != end->x && start->y != end->y; start++, end++)
            if (triangle_face(t) > 0)
                return false;
    }

    return true;
}

enum bool intersect_polygons(struct point* result, const struct point* polygon1, const struct point* polygon2)
{
    const struct point* fst_st = polygon1, * fst_end = polygon1 + 1, * scn_st = polygon2, * scn_end = polygon2 + 1;
    struct point se4_polygon;
    struct section a = { *fst_st, *fst_end };
    struct section b = { *scn_st, *scn_end };
    struct point* fst_point = result;
    int d = 0;

    for (; fst_end->x != polygon1->x || fst_end->y != polygon1->y; fst_st++, fst_end++, scn_st++, scn_end++)
    {
        for (; scn_st->x != polygon2->x || scn_st->y != polygon2->y; scn_st++, scn_end++)
        {
            struct section a = { *fst_st, *fst_end };
            struct section b = { *scn_st, *scn_end };

            if (find_intersection(&se4_polygon, a, b) == true)
            {
                *result++ = se4_polygon;
                if (d == 0)
                    *fst_point = se4_polygon;

                d++;
                if (d == 3)
                    return true;
                struct triangle p = { *fst_end, *scn_st, *fst_point };
                int left_right = triangle_face(p);

                if (left_right < 0 || d == 2)
                {
                    SWAP(const struct point*, &fst_st, &scn_st);
                    SWAP(const struct point*, &fst_end, &scn_end);
                    SWAP(const struct point*, &polygon1, &polygon2);
                }

                scn_st = polygon2, scn_end = polygon2 + 1;
                fst_st++;
                fst_end++;
            }
        }
        if (d)
            *result++ = *fst_st, * result++ = *fst_end;
        scn_st = polygon2, scn_end = polygon2 + 1;
    }

    if (inside(scn_st, *fst_st))
    {

        struct point* o = polygon1;
        do
        {
            *result++ = *o;
            o++;
        } while (polygon1->x != o->x || polygon1->y != o->y);
        *result++ = *o;
        return true;
    }
    else
    {
        struct point* o = polygon2;
        do
        {
            *result++ = *o;
            o++;
        } while (polygon2->x != o->x || polygon2->y != polygon2->y);
        *result++ = *o;
        return true;
    }
    return false;
}
void main()
{
    struct point result[100];
    struct point pol1[] = { {2, 3}, {1, 2}, {4, 2}, {5, 3}, {3, 5}, {2, 5}, {2, 3} };
    struct point pol2[] = { {4, 0}, {6, 1}, {6, 4}, {5, 5}, {3, 4}, {3, 3}, {2, 1}, {4, 0} };
    //struct point pol1[] = {{1, 4}, {1, 1}, {5, 1}, {4, 3}, {1, 4}};
    //struct point pol2[] = {{2, 2}, {3, 2}, {3, 3}, {2, 3}, {2, 2}};
    //rightest_point(pol1);
    enum bool res = intersect_polygons(result, pol1, pol2);
}

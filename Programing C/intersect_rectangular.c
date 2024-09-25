#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
typedef struct { float x, y; }point;
typedef struct { point start, end; }section;
typedef struct { point a, b; }rectangle;
typedef enum { false, true }bool;
void swap(section* array, int i, int j)
{
	section c = array[i];
	array[i] = array[j];
	array[j] = c;
}
bool do_they_intersect(point a, point q, point r)
{
	if (q.x <= MAX(a.x, r.x) && q.x >= MIN(a.x, r.x) && q.y <= MAX(a.y, r.y) && q.y >= MIN(a.y, r.y))
		return true;
	return false;
}
int are_they_parallel(point p, point q, point r)
{
	float value = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (value == 0)
		return 0;
	return (value > 0) ? 1 : 2;
}
bool find_intersection(section a, section b, point* result)
{
	int o1 = are_they_parallel(a.start, a.end, b.start);
	int o2 = are_they_parallel(a.start, a.end, b.end);
	int o3 = are_they_parallel(b.start, b.end, a.start);
	int o4 = are_they_parallel(b.start, b.end, a.end);
	int t = 0;
	if (o1 != o2 && o3 != o4)
		t = 1;
	if (o1 == 0 && do_they_intersect(a.start, b.start, a.end))
		t = 1;
	if (o2 == 0 && do_they_intersect(a.start, b.end, a.end))
		t = 1;
	if (o3 == 0 && do_they_intersect(b.start, a.start, b.end))
		t = 1;
	if (o4 == 0 && do_they_intersect(b.start, a.end, b.end))
		t = 1;
	if (t)
	{
		result->x = ((a.start.x * a.end.y - a.start.y * a.end.x) * (b.start.x - b.end.x) - (a.start.x - a.end.x) * (b.start.x * b.end.y - b.start.y * b.end.x)) / ((a.start.x - a.end.x) * (b.start.y - b.end.y) - (a.start.y - a.end.y) * (b.start.x - b.end.x));
		result->y = ((a.start.x * a.end.y - a.start.y * a.end.x) * (b.start.y - b.end.y) - (a.start.y - a.end.y) * (b.start.x * b.end.y - b.start.y * b.end.x)) / ((a.start.x - a.end.x) * (b.start.y - b.end.y) - (a.start.y - a.end.y) * (b.start.x - b.end.x));
		return true;
	}
	return false;
}
float triangle_face(point a, point b, point c)
{
	float face = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2;
	if (face <= 0)
		return -face;
	return face;
}
bool inside_rectangle(rectangle r, point p)
{
	point A = { r.a.x,r.a.y }, B = { r.b.x,r.a.y }, C = { r.b.x,r.b.y }, D = { r.a.x,r.b.y };
	float f = (B.x - A.x) * (C.y - B.y);
	float f1 = triangle_face(A, p, B), f2 = triangle_face(B, p, C), f3 = triangle_face(C, p, D), f4 = triangle_face(D, p, A);
	if (f >= f1 + f2 + f3 + f4)
		return true;
	return false;
}
unsigned crop(section* array, unsigned length, rectangle within)
{
	section AB = { { within.a.x ,within.a.y },{ within.b.x,within.a.y } }, BC = { { within.b.x,within.a.y },{ within.b.x,within.b.y } },
		CD = { { within.b.x,within.b.y }, { within.a.x,within.b.y } }, DA = { { within.a.x,within.b.y },{ within.a.x ,within.a.y } };
	point intersection[4] = { {-1,-1},{-1,-1},{-1,-1},{-1,-1} };
	for (int i = length - 1; i >= 0; i--)
	{
		if (find_intersection(array[i], AB, &intersection[0]) || find_intersection(array[i], BC, &intersection[1]) || find_intersection(array[i], CD, &intersection[2]) || find_intersection(array[i], DA, &intersection[3]))
		{
			find_intersection(array[i], BC, &intersection[1]);
			find_intersection(array[i], CD, &intersection[2]);
			find_intersection(array[i], DA, &intersection[3]);
			for (int j = 0; j < 4; j++)
			{
				if (intersection[j].x != -1)
				{
					if (inside_rectangle(within, array[i].start))
					{
						if (array[i].start.x != intersection[j].x || array[i].start.y != intersection[j].y)
							array[i].end = intersection[j];
					}
					else
					{
						if (array[i].end.x != intersection[j].x || array[i].end.y != intersection[j].y)
							array[i].start = intersection[j];
					}
				}
			}
			for (int n = 0; n < 4; n++)
				intersection[n].x = -1, intersection[n].y = -1;
		}
		else
		{
			swap(array, i, --length);
		}
	}
	return length;
}
void main()
{
	rectangle r = { {1,0},{4,4} };
	section array[] = { {{0,1},{5,1}}, {{6,6},{8,4}}, {{8,3},{11,3}}, {{1,3},{5,1}} };
	crop(array, 4, r);
}
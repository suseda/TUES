public class Trapezoid extends Figure
{
    int a,b,h;
    Point p1,p2,p3,p4,p_for_h;

    public Trapezoid(String name,double  x,double  y,int a, int b, int h)
    {
        super(x,y,name);
        this.a = a;
        this.b = b;
        this.h = h;
        this.p1 = new Point(x+a/2.0,y+a/2.0);
        this.p_for_h = new Point(x+a/2.0,y-a/2.0);
        this.p3 = new Point(x-a/2.0,y-a/2.0);
        this.p4 = new Point(x-a/2.0,y+a/2.0);
        this.p2 = new Point(p_for_h.x+(b-a),y-a/2.0);
    }

    public double area(Point p1, Point p2,Point p3)
    {
        return Math.abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y))/2);
    }

    public boolean PointInTriangle(Point p1,Point p2,Point p3,Point p)
    {
        double A = area (p1, p2, p3);
        double A1 = area (p, p2, p3);
        double A2 = area (p1, p, p3);
        double A3 = area (p1, p2, p);

        return (A == A1 + A2 + A3);
    }

    @Override
    public boolean OverlapSquare(Square s)
    {
        Region region = new Region(s.p1.x,s.p1.y,s.p3.x,s.p3.y);
        if(p1.x >= region.x1 && p1.x < region.x2 && p1.y >= region.y1 && p1.y < region.y2)
            return true;
        if(p2.x >= region.x1 && p2.x < region.x2 && p2.y >= region.y1 && p2.y < region.y2)
            return true;
        if(p3.x >= region.x1 && p3.x < region.x2 && p3.y >= region.y1 && p3.y < region.y2)
            return true;
        if(p4.x >= region.x1 && p4.x < region.x2 && p4.y >= region.y1 && p4.y < region.y2)
            return true;
        return false;
    }

    @Override
    public boolean OverlapRectangle(Rectangle r)
    {
        Region region = new Region(r.p1.x,r.p1.y,r.p3.x,r.p3.y);
        if(p1.x >= region.x1 && p1.x < region.x2 && p1.y >= region.y1 && p1.y < region.y2)
            return true;
        if(p2.x >= region.x1 && p2.x < region.x2 && p2.y >= region.y1 && p2.y < region.y2)
            return true;
        if(p3.x >= region.x1 && p3.x < region.x2 && p3.y >= region.y1 && p3.y < region.y2)
            return true;
        if(p4.x >= region.x1 && p4.x < region.x2 && p4.y >= region.y1 && p4.y < region.y2)
            return true;
        return false;

    }

    @Override
    public boolean OverlapCircle(Circle c)
    {
        if(c.PointInCircle(p1))
            return true;
        if(c.PointInCircle(p2))
            return true;
        if(c.PointInCircle(p3))
            return true;
        if(c.PointInCircle(p4))
            return true;
        return false;
    }

    @Override
    public boolean OverlapTrapezoid(Trapezoid t)
    {
        Region region = new Region(t.p1.x,t.p1.y,t.p3.x,t.p3.y);
        if(p1.x >= region.x1 && p1.x < region.x2 && p1.y >= region.y1 && p1.y < region.y2)
            return true;
        if(p2.x >= region.x1 && p2.x < region.x2 && p2.y >= region.y1 && p2.y < region.y2)
            return true;
        if(p3.x >= region.x1 && p3.x < region.x2 && p3.y >= region.y1 && p3.y < region.y2)
            return true;
        if(p4.x >= region.x1 && p4.x < region.x2 && p4.y >= region.y1 && p4.y < region.y2)
            return true;

        if(PointInTriangle(p1,p_for_h,p2,t.p1))
            return true;
        if(PointInTriangle(p1,p_for_h,p2,t.p2))
            return true;
        if(PointInTriangle(p1,p_for_h,p2,t.p3))
            return true;
        if(PointInTriangle(p1,p_for_h,p2,t.p4))
            return true;
        return false;

    }

    @Override
    public String toString() {
        return "Trapezoid{" +
                " center=" + center +
                ", name='" + name+
                "a=" + a +
                ", b=" + b +
                ", h=" + h +
                '}';
    }


}

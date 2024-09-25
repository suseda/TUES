public class Rectangle extends Figure
{
    int a,b;
    Point p1,p2,p3,p4;

    public Rectangle(String name,double  x,double  y,int a, int b)
    {
        super(x,y,name);
        this.a = a;
        this.b = b;
        this.p1 = new Point(x+a/2.0,y+b/2.0);
        this.p2 = new Point(x+a/2.0,y-b/2.0);
        this.p3 = new Point(x-a/2.0,y-b/2.0);
        this.p4 = new Point(x-a/2.0,y+b/2.0);
    }

    @Override
    public boolean OverlapRectangle(Rectangle r)
    {
        Region region = new Region(p1.x,p1.y,p3.x,p3.y);
        if(r.p1.x >= region.x1 && r.p1.x < region.x2 && r.p1.y >= region.y1 && r.p1.y < region.y2)
            return true;
        if(r.p2.x >= region.x1 && r.p2.x < region.x2 && r.p2.y >= region.y1 && r.p2.y < region.y2)
            return true;
        if(r.p3.x >= region.x1 && r.p3.x < region.x2 && r.p3.y >= region.y1 && r.p3.y < region.y2)
            return true;
        if(r.p4.x >= region.x1 && r.p4.x < region.x2 && r.p4.y >= region.y1 && r.p4.y < region.y2)
            return true;

        return false;

    }

    @Override
    public boolean OverlapSquare(Square s)
    {
        Region region = new Region(p1.x,p1.y,p3.x,p3.y);
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
        Region region = new Region(p1.x,p1.y,p3.x,p3.y);
        if(t.p1.x >= region.x1 && t.p1.x < region.x2 && t.p1.y >= region.y1 && t.p1.y < region.y2)
            return true;
        if(t.p2.x >= region.x1 && t.p2.x < region.x2 && t.p2.y >= region.y1 && t.p2.y < region.y2)
            return true;
        if(t.p3.x >= region.x1 && t.p3.x < region.x2 && t.p3.y >= region.y1 && t.p3.y < region.y2)
            return true;
        if(t.p4.x >= region.x1 && t.p4.x < region.x2 && t.p4.y >= region.y1 && t.p4.y < region.y2)
            return true;

        if(t.PointInTriangle(t.p1,t.p_for_h,t.p2,p1))
            return true;
        if(t.PointInTriangle(t.p1,t.p_for_h,t.p2,p2))
            return true;
        if(t.PointInTriangle(t.p1,t.p_for_h,t.p2,p3))
            return true;
        if(t.PointInTriangle(t.p1,t.p_for_h,t.p2,p4))
            return true;
        return false;

    }

    @Override
    public String toString() {
        return "Rectangle{" +
                " center=" + center +
                ", name='" + name +
                ", a=" + a +
                ", b=" + b +'\'' +
                '}';
    }

}

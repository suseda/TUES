public class Circle extends Figure
{
    int r;

    public Circle(String name,double  x,double  y,int r)
    {
        super(x,y,name);
        this.r = r;
    }

    public boolean PointInCircle(Point p)
    {
        return ((p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y) <= r * r);
    }

    @Override
    public boolean OverlapRectangle(Rectangle r)
    {
        if(PointInCircle(r.p1))
            return true;
        if(PointInCircle(r.p2))
            return true;
        if(PointInCircle(r.p3))
            return true;
        if(PointInCircle(r.p4))
            return true;
        return false;
    }

    @Override
    public boolean OverlapSquare(Square s)
    {
        if(PointInCircle(s.p1))
            return true;
        if(PointInCircle(s.p2))
            return true;
        if(PointInCircle(s.p3))
            return true;
        if(PointInCircle(s.p4))
            return true;
        return false;
    }

    @Override
    public boolean OverlapCircle(Circle c)
    {
        double l = Math.sqrt((center.x-c.center.x)*(center.x-c.center.x)+(center.y-c.center.y)*(center.y-c.center.y));
        if(l>r+c.r || r>l+c.r || c.r>l+r)
            return true;
        return false;
    }

    @Override
    public boolean OverlapTrapezoid(Trapezoid t)
    {
        if(PointInCircle(t.p1))
            return true;
        if(PointInCircle(t.p2))
            return true;
        if(PointInCircle(t.p3))
            return true;
        if(PointInCircle(t.p4))
            return true;
        return false;
    }

    @Override
    public String toString() {
        return "Circle{" +
                " center=" + center +
                ", name='" + name +
                ",r=" + r +'\'' +
                '}';
    }
}

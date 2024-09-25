public abstract class  Figure {
    Point center;
    String name;

    public Figure(double  x,double  y,String name)
    {
        this.center = new Point(x,y);
        this.name = name;
    }

    abstract public boolean OverlapRectangle(Rectangle r);
    abstract public boolean OverlapSquare(Square s);
    abstract public boolean OverlapCircle(Circle c);
    abstract public boolean OverlapTrapezoid(Trapezoid t);

}

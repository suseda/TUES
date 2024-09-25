public class Region
{
    double x1,y1,x2,y2;

    public Region(double x1, double y1, double x2, double y2)
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public boolean CenterInRegion(Point point)
    {
        return point.x >= x1 && point.x < x2 && point.y >= y1 && point.y < y2;
    }

}

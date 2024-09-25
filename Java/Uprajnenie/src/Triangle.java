import java.util.ArrayList;
import java.lang.Math;

public class Triangle
{
    ArrayList<Point> points;

    public Triangle(ArrayList<Point> points)
    {
        this.points = points;
    }

    double area()
    {
        double res = points.get(0).x*(points.get(1).y - points.get(2).y) + points.get(1).x*(points.get(2).y - points.get(0).y) + points.get(2).x*(points.get(0).y - points.get(1).y);
        res = Math.abs(res/2);
        return res;
    }

    double perimeter()
    {
        double AB =  Math.sqrt( (points.get(1).x - points.get(0).x)*(points.get(1).x - points.get(0).x) + (points.get(1).y - points.get(0).y)*(points.get(1).y - points.get(0).y) );
        double BC =  Math.sqrt( (points.get(2).x - points.get(1).x)*(points.get(2).x - points.get(1).x) + (points.get(2).y - points.get(1).y)*(points.get(2).y - points.get(1).y) );
        double CA =  Math.sqrt( (points.get(0).x - points.get(2).x)*(points.get(0).x - points.get(2).x) + (points.get(0).y - points.get(2).y)*(points.get(0).y - points.get(2).y) );
        return AB + BC + CA;
    }
}

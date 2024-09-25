public class Rectangle extends Figure_with_points
{
    int a,b;
    public Rectangle(int x, int y, int a, int b)
    {
        super(x, y);
        this.a=a;
        this.b=b;
    }

    public double getS()
    {
        return a * b;
    }

    public double getP()
    {
        return 2*(a + b);
    }
}

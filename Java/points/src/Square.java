public class Square extends Figure_with_points
{
    int a;
    public Square(int x, int y,int a)
    {
        super(x, y);
        this.a=a;
    }

    public double getS()
    {
        return a * a;
    }

    public double getP()
    {
        return 4*a;
    }

}

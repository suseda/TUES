public abstract class Figure_with_points extends Figure
{
    int x,y;
    public Figure_with_points(int x, int y)
    {
        super(x, y);
    }

    @Override
    public abstract double getP();

    @Override
    public abstract double getS();


}

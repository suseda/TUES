public abstract class Figure extends Point
{
    int x,y;
    //double S,P;

    public Figure(int x, int y)
    {
        super(x,y);
        this.x=x;
        this.y=y;
    }


     public abstract double getS();

    public abstract double getP();
}

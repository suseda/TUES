import java.util.Vector;

public class Vector2 extends Vector
{
    private int X,Y;
    public static Vector2 up = new Vector2(0,1);
    public static Vector2 down = new Vector2(0, -1);
    public static Vector2 right = new Vector2(1, 0);
    public static Vector2 left = new Vector2(-1,0);
    public static Vector2 zero = new Vector2();
    public Vector2(int x, int y)
    {
        X = x;
        Y = y;
    }

    public Vector2()
    {
        X = 0;
        Y = 0;
    }

    public int getX() {
        return X;
    }

    public int getY() {
        return Y;
    }

    public void setX(int x) {
        X = x;
    }

    public void setY(int y) {
        Y = y;
    }
}

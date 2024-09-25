public class Mine
{
    char left_up,left_down,right_up,right_down;
    char color;

    public Mine(char color,char left_up,char left_down,char right_up,char right_down)
    {
        this.color = color;
        if(left_up == '1')
            this.left_up = color;
        else
            this.left_up=left_up;

        if(left_down == '1')
            this.left_down = color;
        else
            this.left_down=left_down;

        if(right_up == '1')
            this.right_up = color;
        else
            this.right_up = right_up;

        if(right_down == '1')
            this.right_down = color;
        else
            this.right_down = right_down;
    }


    Shape pull()
    {
        Shape s = new Shape(left_up,left_down,right_up,right_down);
        return s;
    }
}

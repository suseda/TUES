public class Rotate_machine extends Machine
{
    char direction;
    public Rotate_machine(char direction)
    {
        this.direction=direction;
    }


    @Override
    void push(Shape new_shape)
    {
        input.add(new_shape);
    }


    @Override
    Shape pull()
    {
        if(direction == 'l')
        {
            char tmp = input.firstElement().left_up;
            input.firstElement().left_up = input.firstElement().right_up;
            input.firstElement().right_up = input.firstElement().right_down;
            input.firstElement().right_down = input.firstElement().left_down;
            input.firstElement().left_down = tmp;
        }
        else
        {
            char tmp = input.firstElement().left_up;
            input.firstElement().left_up = input.firstElement().left_down;
            input.firstElement().left_down = input.firstElement().right_down;
            input.firstElement().right_down = input.firstElement().right_up;
            input.firstElement().right_up = tmp;
        }
        output.add(input.firstElement());
        input.pop();
        return output.firstElement();
    }
}

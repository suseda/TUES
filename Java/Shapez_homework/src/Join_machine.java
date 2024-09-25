public class Join_machine extends Machine
{

    @Override
    void push(Shape s)
    {
        input.add(s);
    }



    @Override
    Shape pull()
    {
        if(input.size() == 1)
            return input.firstElement();
        Shape s = input.get(input.size()-1);
        if(s.left_up == '0')
            s.left_up = input.firstElement().left_up;
        if(s.left_down == '0')
            s.left_down = input.firstElement().left_down;
        if(s.right_up == '0')
            s.right_up = input.firstElement().right_up;
        if(s.right_down == '0')
            s.right_down = input.firstElement().right_down;
        input.pop();
        input.pop();
        output.add(s);
        return output.firstElement();
    }
}

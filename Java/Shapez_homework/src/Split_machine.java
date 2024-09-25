public  class Split_machine extends Machine
{
    char how_to_cut;

    public Split_machine(char how_to_cut)
    {
        this.how_to_cut=how_to_cut;
    }
    @Override
    void push(Shape new_shape)
    {
        input.add(new_shape);
        if(how_to_cut == 'h')
        {
            Shape s1 = new Shape(input.firstElement().left_up, '0', input.firstElement().right_up, '0');
            output.add(s1);
            Shape s2 = new Shape('0',input.firstElement().left_down,'0',input.firstElement().right_down);
            output.add(s2);
        }

        if(how_to_cut == 'v')
        {
            Shape s1 = new Shape(input.firstElement().left_up,input.firstElement().left_down,'0','0');
            output.add(s1);
            Shape s2 = new Shape('0','0', input.firstElement().right_up, input.firstElement().right_down);
            output.add(s2);
        }
    }

    @Override
    Shape pull()
    {
     Shape s = output.get(output.size()-1);
     output.pop();
     return s;
    }
}

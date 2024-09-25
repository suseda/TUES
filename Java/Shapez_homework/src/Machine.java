import java.util.Stack;

public abstract class Machine
{
    protected Stack<Shape> input = new Stack<>();
    protected Stack<Shape> output = new Stack<>();

    abstract void push(Shape s);

    abstract Shape pull();
}

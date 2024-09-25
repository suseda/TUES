public class UIButton extends UIElement
{

    public UIButton(String name, String ID) {
        super(name, ID);
    }


    void onClick()
    {
        System.out.println("Button " + getName() + " was clicked!");
    }
}

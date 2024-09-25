public class UIBox extends UIElement
{

    public UIBox(String name, String ID) {
        super(name, ID);
    }

    void onMouseEnter()
    {
        System.out.println("On enter");
    }

    void onMouseExit()
    {
        System.out.println("On exit");
    }
}

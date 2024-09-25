public class UIInput extends UIElement
{
    private int value;

    public UIInput(String name, String ID, int value) {
        super(name, ID);
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    void onChange()
    {
        System.out.println("On change");
    }
    void onFocus()
    {
        System.out.println("On focus");
    }

}

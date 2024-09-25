public class UIText extends UIElement
{
    private String text;


    public UIText(String name, String ID,String text) {
        super(name, ID);
        this.text = text;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }
}

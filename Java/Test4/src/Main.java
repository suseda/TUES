import java.util.ArrayList;

public class Main
{
    public static void main(String[] args)
    {
        UIElement parent = new UIElement("Parent","0");
        UIBox box1 = new UIBox("Elem1","1");
        UIInput input1 = new UIInput("Elem2","2",1);
        UIInput input2 = new UIInput("Elem3","3",2);
        UIText text1 = new UIText("Elem4","4","Hello");


        ArrayList<UIElement> childs = new ArrayList<>();
        childs.add(box1);
        childs.add(input1);
        childs.add(input2);
        childs.add(text1);
        parent.setChilds(childs);
    }
}
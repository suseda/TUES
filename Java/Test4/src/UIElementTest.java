import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class UIElementTest {

    @org.junit.jupiter.api.Test
    void getParent()
    {
        UIElement parent = new UIElement("Parent","0");
        UIElement elem = new UIElement("Elem","1");

        elem.setParent(parent);

        assertEquals(parent,elem.getParent());
    }

    @org.junit.jupiter.api.Test
    void getChildren()
    {
        UIElement parent = new UIElement("Parent","0");
        UIElement elem = new UIElement("Elem","1");


        ArrayList<UIElement> childs = new ArrayList<>();
        childs.add(elem);
        parent.setChilds(childs);

        assertTrue(parent.getChildren().contains(elem));
    }

    @org.junit.jupiter.api.Test
    void findChildById()
    {
        UIElement parent = new UIElement("Parent","0");
        UIElement elem1 = new UIElement("Elem1","1");
        UIElement elem2 = new UIElement("Elem2","2");
        UIElement elem3 = new UIElement("Elem3","3");


        ArrayList<UIElement> childs = new ArrayList<>();
        childs.add(elem1);
        childs.add(elem2);
        childs.add(elem3);
        parent.setChilds(childs);

        assertEquals(parent.getChildren().get(0).getID(),"1");
        assertEquals(parent.getChildren().get(1).getID(),"2");
        assertEquals(parent.getChildren().get(2).getID(),"3");
    }

    @org.junit.jupiter.api.Test
    void findChildrenByName()
    {
        UIElement parent = new UIElement("Parent","0");
        UIElement elem1 = new UIElement("Elem1","1");
        UIElement elem2 = new UIElement("Elem2","2");
        UIElement elem3 = new UIElement("Elem3","3");


        ArrayList<UIElement> childs = new ArrayList<>();
        childs.add(elem1);
        childs.add(elem2);
        childs.add(elem3);
        parent.setChilds(childs);

        assertEquals(parent.getChildren().get(0).getName(),"Elem1");
        assertEquals(parent.getChildren().get(1).getName(),"Elem2");
        assertEquals(parent.getChildren().get(2).getName(),"Elem3");
    }

    @org.junit.jupiter.api.Test
    void addEventHandler()
    {

    }

    @org.junit.jupiter.api.Test
    void triggerEvent()
    {

    }
}
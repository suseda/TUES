import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.function.Consumer;
import java.util.stream.Collectors;

public class UIElement {
    private String name, ID;
    private int width, height;
    private UIElement parent;
    private ArrayList<UIElement> children;

    HashMap<String,Consumer> events = new HashMap<>();


    public UIElement(String name, String ID) {
        this.name = name;
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public String getID() {
        return ID;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public UIElement getParent() {
        return parent;
    }

    public ArrayList<UIElement> getChildren() {
        return children;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public void setParent(UIElement parent) {
        this.parent = parent;
    }

    public void setChilds(ArrayList<UIElement> childs) {
        this.children = childs;
    }

    void addChild(UIElement elem) {
        getChildren().add(elem);
    }

    UIElement findChildById(String id) {
        for (int i = 0; i < children.size(); i++) {
            if (children.get(i).getID() == id)
                return children.get(i);
            else
                return children.get(i).findChildById(id);
        }
        return null;
    }


    ArrayList<UIElement> findChildrenByName(String name) {
        ArrayList<UIElement> list = new ArrayList(
                children.stream()
                        .filter(child -> child.getName() == name)
                        .collect(Collectors.toList()));

        return list;
    }

    void addEventHandler(String eventName, Consumer eventHandler) throws Exception
    {
        if(!events.containsKey(eventName))
            throw new Exception("This event doesnt exist");

        eventHandler.accept(events.get(eventName));

    }

    void triggerEvent(String eventName, Object eventPayload)
    {
        if (events.containsKey(eventName))
        {

        }
    }

    void demo()
    {

    }

}

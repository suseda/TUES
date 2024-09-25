public abstract class Item implements IUsableItem
{
    private String name;


    public Item(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    abstract void use(Farm farm, Vector2 position) throws Exception;


    abstract void use(Farm farm, Vector2 position, Vector2 direction, int powerLevel) throws Exception;

    public abstract void applyItem(Farm farm, Vector2 position, String name, int age_to_grow) throws Exception;
}

import java.util.ArrayList;

public class Order
{
    private int ID = 0;
    private ArrayList<Product> products_list;
    private String requirements;

    public Order( ArrayList<Product> products_list, String requirements) {
        this.ID = Main.ID;
        Main.ID++;
        this.products_list = products_list;
        this.requirements = requirements;
    }

    public int getID() {
        return ID;
    }

    public ArrayList<Product> getProducts_list() {
        return products_list;
    }

    public String getRequirements() {
        return requirements;
    }

    public void setID(int ID)
    {
        this.ID = ID;
    }

    public void setProducts_list(ArrayList<Product> products_list) {
        this.products_list = products_list;
    }

    public void setRequirements(String requirements) {
        this.requirements = requirements;
    }

    public static Order ClassicHam(Bread bread)
    {

        Order order = new Order(new ArrayList<Product>(),"Nothing");
        order.getProducts_list().add(bread);
        order.getProducts_list().add(new Meat("Ham"));
        order.getProducts_list().add(new Cheese("Yellow cheese"));
        order.getProducts_list().add(new Vegetables("Tomato"));
        order.getProducts_list().add(new Vegetables("Onion"));
        order.getProducts_list().add(new Vegetables("Cucumber"));
        order.getProducts_list().add(new Sauce("Mayonnaise"));

        return order;
    }//- шунка, кашкавал, домат, лук, краставица, майонеза

    public static Order LongBurger(Bread bread)
    {
        Order order = new Order(new ArrayList<Product>(),"Nothing");
        order.getProducts_list().add(bread);
        order.getProducts_list().add(new Meat("Veal"));
        order.getProducts_list().add(new Cheese("Cheese"));
        order.getProducts_list().add(new Vegetables("Iceberg"));
        order.getProducts_list().add(new Vegetables("Pickled cucumber"));
        order.getProducts_list().add(new Sauce("BBQ souse"));

        return order;
    } //- телешко, топено сирене, айсберг, кисели краставички, барбекю сос

    public static Order VeggieDelight(Bread bread)
    {
        Order order = new Order(new ArrayList<Product>(),"Nothing");
        order.getProducts_list().add(bread);
        order.getProducts_list().add(new Cheese("Yellow cheese"));
        order.getProducts_list().add(new Vegetables("Iceberg"));
        order.getProducts_list().add(new Vegetables("Olives"));
        order.getProducts_list().add(new Vegetables("Tomato"));
        order.getProducts_list().add(new Sauce("Ranch souse"));

        return order;
    } // - кашкавал, айсберг, маслини, домати, сос ранч


    boolean isValid()
    {
        int bread_cnt = 0,cheese_cnt = 0,vegetables_cnt = 0,souse_cnt = 0;
        ArrayList<Integer> allowed_cnt = new ArrayList<>();
        allowed_cnt.add(1);
        allowed_cnt.add(2);
        allowed_cnt.add(3);

        for(int i = 0; i < getProducts_list().size(); i++)
        {
            if(isInstance(getProducts_list().get(i),Bread.class))
                bread_cnt++;

            if(isInstance(getProducts_list().get(i),Vegetables.class))
                vegetables_cnt++;

            if(isInstance(getProducts_list().get(i),Sauce.class))
                souse_cnt++;

            if(isInstance(getProducts_list().get(i),Cheese.class))
                cheese_cnt++;
        }

        return bread_cnt == 1 && cheese_cnt == 1 && allowed_cnt.contains(vegetables_cnt) && allowed_cnt.contains(souse_cnt);
    }

    boolean isInstance(Object object, Class<?> type)
    {
        return type.isInstance(object);
    }


}

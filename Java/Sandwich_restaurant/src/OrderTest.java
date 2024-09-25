import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Before;
import org.junit.Test;

public class OrderTest {

    private Bread bread;
    private Vegetables tomato;
    private Cheese cheese;
    private Sauce mayo;
    private ArrayList<Product> products;
    private Order order;

    @Before
    public void setUp() {
        bread = new Bread("White");
        tomato = new Vegetables("Tomato");
        cheese = new Cheese("Yellow cheese");
        mayo = new Sauce("Mayonnaise");
        products = new ArrayList<>();
        order = new Order(products, "Nothing");
    }

    @Test
    public void testGetID() {
        assertEquals(0, order.getID());
    }

    @Test
    public void testGetProducts_list() {
        assertEquals(products, order.getProducts_list());
    }

    @Test
    public void testGetRequirements() {
        assertEquals("Nothing", order.getRequirements());
    }

    @Test
    public void testSetID() {
        order.setID(1);
        assertEquals(1, order.getID());
    }

    @Test
    public void testSetProducts_list() {
        ArrayList<Product> newProducts = new ArrayList<>();
        newProducts.add(bread);
        newProducts.add(tomato);
        order.setProducts_list(newProducts);
        assertEquals(newProducts, order.getProducts_list());
    }

    @Test
    public void testSetRequirements() {
        order.setRequirements("bake");
        assertEquals("bake", order.getRequirements());
    }


    @Test
    public void testIsValid() {
        order.getProducts_list().add(new Meat("Chicken"));
        order.getProducts_list().add(new Cheese("Yellow cheese"));
        order.getProducts_list().add(new Vegetables("Lettuce"));
        order.getProducts_list().add(new Vegetables("Tomato"));
        order.getProducts_list().add(new Sauce("Ketchup"));
        assertFalse(order.isValid());
    }
}

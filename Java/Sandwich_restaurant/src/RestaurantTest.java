import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

public class RestaurantTest {

    private ArrayList<Cooker> cookers;
    private ArrayList<Order> pending_orders;
    private Restaurant restaurant;

    @Before
    public void setUp() {
        cookers = new ArrayList<>();
        pending_orders = new ArrayList<>();
        restaurant = new Restaurant(cookers, pending_orders);
    }

    @Test
    public void testAddCook() {
        Cooker cooker = new Cooker("Pesho",null,restaurant);
        restaurant.addCook(cooker);
        assertTrue(restaurant.getCookers().contains(cooker));
    }

    @Test
    public void testRemoveCook() {
        Cooker cooker = new Cooker("Pesho",null,restaurant);
        restaurant.addCook(cooker);
        restaurant.removeCook(cooker);
        assertFalse(restaurant.getCookers().contains(cooker));
    }

    @Test
    public void testAddOrder() {
        ArrayList<Product> products = new ArrayList<>();
        products.add(new Product("Bread"));
        products.add(new Product("Cheese"));
        products.add(new Product("Ham"));
        Order order = new Order(products, "no bake");
        restaurant.addOrder(order);
        assertTrue(restaurant.getPending_orders().contains(order));
    }

    @Test
    public void testFinalizeOrder() throws InterruptedException {
        ArrayList<Product> products = new ArrayList<>();
        products.add(new Product("Bread"));
        products.add(new Product("Cheese"));
        products.add(new Product("Ham"));
        Order order = new Order(products, "no bake");
        restaurant.addCook(new Cooker("Pesho",null,restaurant));
        restaurant.addOrder(order);
        restaurant.start_working();
        restaurant.finalizeOrder(order);

        assertFalse(restaurant.getPending_orders().contains(order));

    }


    @Test
    public void testStartWorking() {
        ArrayList<Product> products = new ArrayList<>();
        products.add(new Product("Bread"));
        products.add(new Product("Cheese"));
        products.add(new Product("Ham"));
        Order order1 = new Order(products, "no bake");

        products.add(new Product("Bread"));
        products.add(new Product("Cheese"));
        products.add(new Product("Beaf"));
        Order order2 = new Order(products, "bake");
        restaurant.addOrder(order1);
        restaurant.addOrder(order2);

        Cooker cooker1 = new Cooker("Pesho",null,restaurant);
        Cooker cooker2 = new Cooker("Gosho",null,restaurant);
        restaurant.addCook(cooker1);
        restaurant.addCook(cooker2);

        restaurant.start_working();

        assertEquals(order1, cooker1.getOrder());
        assertEquals(order2, cooker2.getOrder());
    }

    @Test
    public void testShutdown() {
        Cooker cooker1 = new Cooker("Pesho",null,restaurant);
        Cooker cooker2 = new Cooker("Gosho",null,restaurant);
        restaurant.addCook(cooker1);
        restaurant.addCook(cooker2);

        restaurant.shutdown();

        assertTrue(cooker1.getCooker().isInterrupted());
        //assertTrue(cooker1.getBakery().getBakery().isInterrupted());
        assertTrue(cooker2.getCooker().isInterrupted());
        assertTrue(cooker2.getBakery().getBakery().isInterrupted());
        assertTrue(restaurant.getCookers().isEmpty());
    }
}
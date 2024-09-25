import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Before;
import org.junit.Test;

public class BakeryTest {

    private Bakery bakery;
    private ArrayList<Order> readyOrders;

    @Before
    public void setUp() throws Exception {
        readyOrders = new ArrayList<>();
        bakery = new Bakery(null);
        bakery.setReady_orders(readyOrders);
    }

    @Test
    public void testGetOrder() {
        assertNull(bakery.getOrder());
    }


    @Test
    public void testGetReady_orders() {
        assertEquals(readyOrders, bakery.getReady_orders());
    }

    @Test
    public void testSetReady_orders() {
        ArrayList<Order> newReadyOrders = new ArrayList<>();
        bakery.setReady_orders(newReadyOrders);
        assertEquals(newReadyOrders, bakery.getReady_orders());
    }

    @Test
    public void testTake_order() throws InterruptedException {
        ArrayList<Product> products = new ArrayList<>();
        products.add(new Bread("Bread"));
        products.add(new Cheese("Cheese"));
        products.add(new Meat("Ham"));
        ArrayList<Order> orders = new ArrayList<>();
        orders.add(new Order(products, "no bake"));


        bakery.take_order(orders.get(0));
        Thread.sleep(3000);
        assertEquals(orders.get(0), readyOrders.get(0));
    }
}
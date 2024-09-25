import org.junit.Test;

import static org.junit.Assert.*;
import java.util.ArrayList;
import java.util.List;

public class CookerTest {

    @Test
    public void testCooker() throws InterruptedException {

        ArrayList<Product> products = new ArrayList<>();
        products.add(new Bread("Bread"));
        products.add(new Cheese("Cheese"));
        ArrayList<Order> orders = new ArrayList<>();
        orders.add(new Order(products, "no bake"));

        ArrayList<Cooker> cookers = new ArrayList<>();
        cookers.add(new Cooker("Bob",orders.get(0), null));


        Restaurant mockRestaurant = new Restaurant(cookers,orders);
        cookers.get(0).restaurant = mockRestaurant;

        assertTrue(cookers.get(0).getCooker().isAlive());


        ArrayList<Product> newProducts = new ArrayList<>();
        newProducts.add(new Bread("Bread"));
        newProducts.add(new Cheese("Cheese"));
        newProducts.add(new Meat("Ham"));
        Order newOrder = new Order(newProducts, "bake");
        cookers.get(0).take_order(newOrder);


        assertEquals(cookers.get(0).getOrder(),newOrder);

    }
}
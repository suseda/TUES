import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class BasketTestSame {

    @Test
    void add() {
        Product p1 = new Product("Hlqb",1);
        Product p2 = new Product("Hlqb",2);

        List<Product> products = new ArrayList<>();
        products.add(p1);
        products.add(p2);


        Basket b = new Basket(products);
        assertEquals();
    }
}
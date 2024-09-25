import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Product p1 = new Product("Salam",1);
        Product p2 = new Product("Hlqb",2);
        Product p3 = new Product("Kashkaval",3);
        Product p4 = new Product("Sirene",1);

        List<Product> products = new ArrayList<>();
        products.add(p1);
        products.add(p2);
        products.add(p3);
        products.add(p4);

        Basket b = new Basket(products);
        
    }
}
import java.util.List;

public class Basket
{
    private List<Product> basket;

    public Basket(List<Product> basket) {
        this.basket = basket;
    }

    public List<Product> getBasket() {
        return basket;
    }

    public void setBasket(List<Product> basket) {
        this.basket = basket;
    }

    void add(Product p)
    {
        boolean productExist = false;
        for(int i = 0; i < basket.size();i++)
        {
            if(basket.get(i).getName() == p.name)
            {
                double a = basket.get(i).getQuantity();
                basket.get(i).setQuantity(a+p.quantity);
                productExist = true;
                break;
            }
        }

        if(!productExist)
            basket.add(p);
    }

}

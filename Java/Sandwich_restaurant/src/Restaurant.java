import java.util.ArrayList;

public class Restaurant
{
    private ArrayList<Cooker> cookers;
    private ArrayList<Order> pending_orders;

    public Restaurant(ArrayList<Cooker> cookers, ArrayList<Order> pending_orders) {
        this.cookers = cookers;
        this.pending_orders = pending_orders;
    }

    public ArrayList<Cooker> getCookers() {
        return cookers;
    }

    public ArrayList<Order> getPending_orders() {
        return pending_orders;
    }

    public void setCookers(ArrayList<Cooker> cookers) {
        this.cookers = cookers;
    }

    public void setPending_orders(ArrayList<Order> pending_orders) {
        this.pending_orders = pending_orders;
    }

    void addCook(Cooker cook)
    {
        getCookers().add(cook);
    }

    void removeCook(Cooker cook)
    {
        cook.getCooker().interrupt();
        cook.getBakery().getBakery().interrupt();
        getCookers().remove(cook);
    }

    void addOrder(Order order)
    {
        getPending_orders().add(order);
    }


    void finalizeOrder(Order order)
    {
        System.out.println("Order " + order.getID() + " is ready!");
    }//, който извежда съобщение за завършената поръчка. Веднъж завършена поръчката не трябва да се достъпва и обработва от никой обект и никоя нишка. Хвърля изключение ако в ресторанта все още не е подадена поръчка със същия номер

    void start_working()
    {
            for(int i = 0,j = 0; getPending_orders().size() != 0 &&  getCookers().size() > j; i++,j++)
            {
                    if (getCookers().get(j).getOrder() == null && getPending_orders().size() > 0)
                    {
                        getCookers().get(j).take_order(getPending_orders().get(0));
                        getPending_orders().remove(0);
                    }
            }

    }

    void shutdown()
    {
        while(getCookers().size() != 0)
        {
            getCookers().get(0).getCooker().interrupt();
            getCookers().get(0).getBakery().getBakery().interrupt();
            getCookers().remove(0);
        }
    }//, който изчаква всички готвачи да завършат поръчките си и спира всички нишки за да може програмата да се затвори
}

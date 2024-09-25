public class Cooker implements Runnable
{
    private String name;
    private Order order;
    private Thread cooker;
    private Bakery bakery;
    public Restaurant restaurant;

    public Cooker(String name, Order order,Restaurant restaurant) {
        this.name = name;
        this.order = order;
        cooker = new Thread(this);
        cooker.start();
        this.bakery = new Bakery(null);
        this.restaurant = restaurant;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Order getOrder() {
        return order;
    }

    public void setOrder(Order order) {
        this.order = order;
    }

    public Thread getCooker() {
        return cooker;
    }

    public Bakery getBakery() {
        return bakery;
    }

    void log(String msg)
    {
        System.out.println("[ Cooker " + getName() + " ] " + msg + "\n");
    }

    @Override
    public void run()
    {
        try {
            while (true) {
                if (this.order == null)
                    synchronized (this) {
                        log( " is waiting for order");
                        this.wait();
                    }
                log(" is cooking");
                log(" is preparing bread");
                Thread.sleep(1500);

                for(int i = 1; i < order.getProducts_list().size();i++)
                {
                    log( " is adding " + order.getProducts_list().get(i).getName());
                    Thread.sleep(1200);
                }

                if(order.getRequirements() != "no bake")
                    bakery.take_order(order);
                else
                    restaurant.finalizeOrder(order);

                if(bakery.getReady_orders().size() != 0)
                {
                    restaurant.finalizeOrder(bakery.getReady_orders().get(0));
                    bakery.getReady_orders().remove(0);
                }


                order = null;
            }
        } catch(InterruptedException ex) {
            log(" is exiting");
        }
    }

    public void take_order(Order order) {
        synchronized (this) {
            this.order=order;
            log(" taking the order");
            this.notify();
        }
    }
}

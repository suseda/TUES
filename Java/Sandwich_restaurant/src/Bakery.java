import java.util.ArrayList;

public class Bakery implements Runnable
{
    private Order order;
    private ArrayList<Order> ready_orders = new ArrayList<>();
    private Thread bakery;

    public Bakery(Order order) {
        this.order = order;
        bakery = new Thread(this);
        bakery.start();
    }

    public Order getOrder() {
        return order;
    }

    public void setOrder(Order order) {
        this.order = order;
    }

    public Thread getBakery() {
        return bakery;
    }

    public ArrayList<Order> getReady_orders() {
        return ready_orders;
    }

    public void setReady_orders(ArrayList<Order> ready_orders) {
        this.ready_orders = ready_orders;
    }

    @Override
    public void run()
    {
        try {
            while (true) {
                if (this.order == null)
                    synchronized (this)
                    {
                        System.out.println("Bakery is waiting for order");
                        this.wait();
                    }

                Thread.sleep(2500);
                System.out.println("Order " + order.getID() + " is baked");
                ready_orders.add(order);

                order = null;
            }
        } catch(InterruptedException ex) {
            System.out.println("Interrupt");
        }
    }

    public void take_order(Order order) {
        synchronized (this) {
            this.order=order;
            this.notify();
        }
    }
}

import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static int ID = 0;
    public static void main(String[] args)
    {
        ArrayList<Cooker> cookers = new ArrayList<>();
        ArrayList<Order> orders = new ArrayList<>();
        Restaurant restaurant = new Restaurant(cookers,orders);

        /*restaurant.addCook(new Cooker("Pesho",null));
        restaurant.addCook(new Cooker("Tosho",null));
        restaurant.addCook(new Cooker("Gosho",null));

        ArrayList<Product> products = new ArrayList<>();
        products.add(new Bread("Bread"));
        products.add(new Meat("Ham"));
        products.add(new Souse("Ketchup"));
        products.add(new Cheese("Yellow cheese"));
        products.add(new Vegetables("Tomato"));

        restaurant.addOrder(new Order(products,""));
        restaurant.addOrder(new Order(products,""));
        restaurant.addOrder(new Order(products,"no bake"));
        restaurant.addOrder(new Order(products,""));

        restaurant.start_working();

        restaurant.addOrder(new Order(products,""));*/

        Scanner input = new Scanner(System.in);
        int choice;

        do {
            restaurant.start_working();
            System.out.println("Restaurant menu");
            System.out.println("1. Add cooker");
            System.out.println("2. Remove cooker");
            System.out.println("3. Make new order");
            System.out.println("4. Quit");
            System.out.print("Enter your choice: ");
            choice = input.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter cooker name: ");
                    String name = input.next();
                    restaurant.addCook(new Cooker(name,null,restaurant));
                    break;
                case 2:
                    System.out.print("Enter cooker name that you want to remove: ");
                    String name_to_remove = input.next();
                    for (int i = 0; i < restaurant.getCookers().size(); i++) {
                        if (name_to_remove.equals(restaurant.getCookers().get(i).getName()))
                        {
                            restaurant.removeCook(restaurant.getCookers().get(i));
                            break;
                        }
                    }
                    break;
                case 3:
                    int order_choice = 0;
                    do {
                        restaurant.start_working();
                        System.out.println("1. Chose from ready recipes");
                        System.out.println("2. Make your own sandwich");
                        System.out.print("Enter your choice: ");
                        order_choice = input.nextInt();
                        switch (order_choice) {
                            case 1:
                                int ready_orders = 0;
                                do {
                                    System.out.println("1. ClassicHam");
                                    System.out.println("2. LongBurger");
                                    System.out.println("3. VeggieDelight");
                                    System.out.print("Enter your choice: ");
                                    ready_orders = input.nextInt();
                                    switch (ready_orders) {
                                        case 1:
                                            System.out.println("Chose bread: ");
                                            restaurant.getPending_orders().add(Order.ClassicHam(new Bread(input.next())));
                                            break;
                                        case 2:
                                            System.out.println("Chose bread: ");
                                            restaurant.getPending_orders().add(Order.LongBurger(new Bread(input.next())));
                                            break;
                                        case 3:
                                            System.out.println("Chose bread: ");
                                            restaurant.getPending_orders().add(Order.VeggieDelight(new Bread(input.next())));
                                            break;
                                        default:
                                            System.out.println("Invalid order chose again.");
                                    }
                                } while (ready_orders != 1 && ready_orders != 2 && ready_orders != 3);
                                break;
                            case 2:
                                ArrayList<Product> order_products = new ArrayList<>();
                                System.out.println("Chose bread: ");
                                order_products.add(new Bread(input.next()));

                                System.out.println("Chose cheese: ");
                                order_products.add(new Cheese(input.next()));

                                System.out.println("Do you want meat?");
                                System.out.println("1. Yes");
                                System.out.println("2. No");
                                System.out.print("Enter your choice: ");
                                int meat_ch = input.nextInt();

                                if (meat_ch == 1) {
                                    System.out.println("Chose meat: ");
                                    order_products.add(new Meat(input.next()));
                                }

                                for (int i = 0; i < 3; i++) {
                                    System.out.println("Do you want vegetables?");
                                    System.out.println("1. Yes");
                                    System.out.println("2. No");
                                    System.out.print("Enter your choice: ");
                                    int veg_ch = input.nextInt();

                                    if (veg_ch == 2)
                                        break;

                                    System.out.println("Chose vegetable: ");
                                    order_products.add(new Vegetables(input.next()));
                                }

                                for (int i = 0; i < 3; i++) {
                                    System.out.println("Do you want sauce?");
                                    System.out.println("1. Yes");
                                    System.out.println("2. No");
                                    System.out.print("Enter your choice: ");
                                    int souse_ch = input.nextInt();

                                    if (souse_ch == 2)
                                        break;

                                    System.out.println("Chose souse: ");
                                    order_products.add(new Sauce(input.next()));

                                }

                                System.out.println("Do you want your sandwich to be baked?");
                                System.out.println("1. Yes");
                                System.out.println("2. No");
                                System.out.print("Enter your choice: ");
                                int want_bake = input.nextInt();

                                if (want_bake == 1)
                                    restaurant.getPending_orders().add(new Order(order_products,"bake"));
                                else
                                    restaurant.getPending_orders().add(new Order(order_products,"no bake"));

                                break;
                        }
                    } while (order_choice != 1 && order_choice != 2);
                    break;
                case 4:
                    System.out.println("Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
            }

            System.out.println();
            restaurant.start_working();
        } while (choice != 4);

        restaurant.shutdown();
    }
}
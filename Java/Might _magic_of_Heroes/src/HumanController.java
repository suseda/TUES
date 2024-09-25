import java.util.ArrayList;
import java.util.Scanner;

public class HumanController extends PlayerController
{


    public HumanController(Map map, ArrayList<Player> players)
    {
        super(map, players);
    }

    public void startTurn(Player activePlayer)
    {
       run(activePlayer);
    }

    public void run(Player activePlayer)
    {
        Scanner input = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Choices:");
            System.out.println("1. End turn");
            System.out.println("2. Select hero");
            System.out.println("3. Move hero");
            System.out.println("4. View hero");
            System.out.println("5. View cell");
            System.out.println("6. View self");
            System.out.println("7. View player");
            System.out.println("8. If this cell is town you can buy army");
            System.out.print("Enter your choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Bye");
                    break;
                case 2:
                    System.out.println("Select index of the hero");
                    int hero_index = input.nextInt();
                    activePlayer.setActiveHero(activePlayer.getHeroes().get(hero_index));
                    break;
                case 3:
                    System.out.println("Select x");
                    int x_hero = input.nextInt();
                    System.out.println("Select y");
                    int y_hero = input.nextInt();
                    activePlayer.getActiveHero().moveTo(gameMap.getCell(x_hero,y_hero),gameMap, activePlayer);
                    break;
                case 4:
                    System.out.println(activePlayer.getActiveHero().toString());
                    break;
                case 5:
                    System.out.println("Select x");
                    int x_cell = input.nextInt();
                    System.out.println("Select y");
                    int y_cell = input.nextInt();
                    System.out.println(gameMap.getCell(x_cell,y_cell).toString());
                    break;
                case 6:
                    System.out.println(activePlayer.toString());
                    System.out.println("");
                    for(int i = 0; activePlayer.getHeroes().size() > i; i++)
                        System.out.println(activePlayer.getHeroes().get(i).specialToString());
                    break;
                case 7:
                    System.out.println("Select index of player");
                    int player_index = input.nextInt();
                    System.out.println(players.get(player_index).toString());
                    break;
                case 8:
                    System.out.println("Select quantity of army that you want to buy");
                    int quantity = input.nextInt();
                    if(gameMap.getCell(activePlayer.getActiveHero().getPos().x, activePlayer.getActiveHero().getPos().y).getType() instanceof Town)
                        ((Town) gameMap.getCell(activePlayer.getActiveHero().getPos().x, activePlayer.getActiveHero().getPos().y).getType()).doSomething(activePlayer,quantity);
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }while(choice != 1);
    }

}

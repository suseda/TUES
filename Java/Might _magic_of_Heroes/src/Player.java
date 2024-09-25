import java.util.ArrayList;

public class Player
{
    private String name;
    private PlayerType type;
    private ArrayList<Hero> heroes = new ArrayList<>();
    private Hero activeHero;
    private int money;

    public Player(String name, PlayerType type) {
        this.name = name;
        this.type = type;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setType(PlayerType type) {
        this.type = type;
    }

    public void setHeroes(ArrayList<Hero> heroes) {
        this.heroes = heroes;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public String getName() {
        return name;
    }

    public PlayerType getType() {
        return type;
    }

    public ArrayList<Hero> getHeroes() {
        return heroes;
    }

    public int getMoney() {
        return money;
    }

    public Hero getActiveHero() {
        return activeHero;
    }

    public void setActiveHero(Hero activeHero) {
        this.activeHero = activeHero;
    }

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name + '\'' +
                ", type=" + type +
                ", money=" + money +
                '}';
    }


    public enum PlayerType {
        COMPUTER,
        HUMAN
    }
}

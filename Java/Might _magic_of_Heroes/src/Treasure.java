import java.util.ArrayList;

public class Treasure extends CellType
{

    public void doSomething(Player activePlayer)
    {
        ArrayList<Hero> heroes = activePlayer.getHeroes();
        for (Hero hero: heroes) {
            hero.setLevel(hero.getLevel() + 1);
        }
    }
}

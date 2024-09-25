import java.util.Random;

public class Army extends CellType
{
    private Hero hero_on_this_cell;
    private Player CellOwner;

    public Army(Hero player_on_this_cell, Player owner)
    {
        this.hero_on_this_cell = player_on_this_cell;
        this.CellOwner = owner;
    }

    public Hero getHero_on_this_cell() {
        return hero_on_this_cell;
    }

    public void setPlayer_army_on_this_cell(Hero hero_on_this_cell) {
        this.hero_on_this_cell = hero_on_this_cell;
    }

    public Player getCellOwner() {
        return CellOwner;
    }

    public void setCellOwner(Player cellOwner) {
        CellOwner = cellOwner;
    }

    public void doSomething(Player activePlayer)
    {
        if(!(activePlayer.getHeroes().contains(this.hero_on_this_cell)))
            war(activePlayer,this.hero_on_this_cell);

    }

    public void war(Player activePlayer, Hero enemy)
    {
        boolean active_player_attack = true;

        if(activePlayer.getHeroes().size() > 0) {
            Hero hero1 = activePlayer.getHeroes().get(0);

            Random random = new Random();

            while (enemy.getArmies_power() >= 0 && hero1.getArmies_power() >= 0)
            {
                if (active_player_attack) {
                    double maxValue = 5 * (hero1.getArmies_power() / enemy.getArmies_power()) - 5;
                    double C = maxValue * random.nextDouble();
                    enemy.setArmies_power(enemy.getArmies_power() - C);
                    if (enemy.getArmies_power() <= 0) {
                        System.out.println(enemy.getName() + " is dead");
                        CellOwner.getHeroes().remove(enemy);
                        hero_on_this_cell = hero1;
                        CellOwner = activePlayer;
                    }
                    active_player_attack = false;
                } else {
                    double maxValue = 5 * (enemy.getArmies_power() / hero1.getArmies_power()) - 5;
                    double C = maxValue * random.nextDouble();
                    hero1.setArmies_power(hero1.getArmies_power() - C);
                    if (hero1.getArmies_power() <= 0) {
                        System.out.println(activePlayer.getHeroes().get(activePlayer.getHeroes().indexOf(hero1)) + " is dead");
                        activePlayer.getHeroes().remove(hero1);
                    }
                    active_player_attack = true;
                }

            }
        }


    }
}

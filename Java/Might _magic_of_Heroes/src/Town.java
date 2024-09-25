public class Town extends CellType
{
    public Town() {}

    public void doSomething(Player player, int quantity)
    {
        int cost = quantity * 10;
        if (player.getMoney() >= cost)
        {
            player.getActiveHero().setArmies_power(player.getActiveHero().getArmies_power() + quantity);
            player.setMoney(player.getMoney() - cost);
        }
        else
            System.out.println("Not enough money to increase army power.");

    }

    @Override
    public void doSomething(Player activePlayer)
    {

    }
}

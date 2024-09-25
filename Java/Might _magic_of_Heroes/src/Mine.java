public class Mine extends CellType
{
    private Player owner;

    public Mine(Player owner) {
        this.owner = owner;
    }

    public Player getOwner() {
        return owner;
    }

    public void setOwner(Player owner) {
        this.owner = owner;
    }

    public void doSomething(Player activePlayer)
    {
        setOwner(activePlayer);
        activePlayer.setMoney(activePlayer.getMoney() + 1000);
    }
}

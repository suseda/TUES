import java.util.ArrayList;

public class Player
{
    int HP, STR, CHA, GOLD;
    ArrayList<String> items;

    public Player(int HP, int STR, int CHA, int GOLD, ArrayList<String> items)
    {
        this.HP = HP;
        this.STR = STR;
        this.CHA = CHA;
        this.GOLD = GOLD;
        this.items = items;
    }
}

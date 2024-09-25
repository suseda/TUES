import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class Tournament
{
    ArrayList<Player> players;

    public Tournament(ArrayList<Player> players)
    {
        this.players = players;
    }

    void distribute()
    {
        int last = players.size() - 1;
        for(int i = 1; i < players.size()/2;i++)
        {
            Collections.swap(players,i,last);
            last--;
        }
    }

    void print()
    {
        for(int i = 0; i < players.size();i++)
            System.out.println(players.get(i).getName());
    }
}

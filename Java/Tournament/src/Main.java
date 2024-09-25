import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args)
    {
        ArrayList<Player> players = new ArrayList<>();

        Player p1 = new Player(1,"Andrew");
        Player p2 = new Player(3,"Robert");
        Player p3 = new Player(4,"Kevin");
        Player p4 = new Player(2,"Lisa");

        players.add(p1);
        players.add(p2);
        players.add(p3);
        players.add(p4);

        Collections.sort(players);

        Tournament t = new Tournament(players);
        t.distribute();
        t.print();
    }
}
import java.util.ArrayList;

public class Main
{
    public static void main(String[] args)
    {
        Map gameMap = new Map(3,3);

        GameEndingCondition lambda_end_game = (Game game) -> {
            if(game.getPlayers().size() == 1)
                return true;

            for (Player p : game.getPlayers())
            {
                if(p.getMoney() >= 100000)
                    return true;
            }

            for(Player p : game.getPlayers())
            {
                for (Hero h : p.getHeroes()) {
                    if(h.getLevel() >= 30)
                        return true;
                }
            }

            return false;
        };

        Game game = new Game(gameMap,lambda_end_game);

        Player p1 = new Player("Killer", Player.PlayerType.HUMAN);
        ArrayList<Hero> heros1 = new ArrayList<>();
        Position start_pos = new Position(0,0);
        heros1.add(new Hero("Hero1",3,10,3,start_pos,new Cell(new Empty(),start_pos)));
        heros1.add(new Hero("Hero2",2,8,2,start_pos,new Cell(new Empty(),start_pos)));
        p1.setHeroes(heros1);

        Player p2 = new Player("Murder", Player.PlayerType.HUMAN);
        ArrayList<Hero> heros2 = new ArrayList<>();
        Position other_pos = new Position(1,1);
        heros2.add(new Hero("Hero1",3,8,3,start_pos,new Cell(new Empty(),other_pos)));
        heros2.add(new Hero("Hero2",2,5,2,start_pos,new Cell(new Empty(),other_pos)));
        p2.setHeroes(heros2);


        Player p3 = new Player("Godly", Player.PlayerType.HUMAN);

        ArrayList<Player> players = new ArrayList<>();

        players.add(p1);
        players.add(p2);
        players.add(p3);

        game.setPlayers(players);
        HumanController humanController = new HumanController(gameMap,players);
        game.setController(humanController);

        game.startGame();



    }
}
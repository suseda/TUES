import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class GameTest {

    private Map map;
    private GameEndingCondition gameEndingCondition;
    private Game game;

    @BeforeEach
    public void setUp() {
        map = new Map(5, 5);

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

        game = new Game(map, lambda_end_game);
    }

    /*@Test
    void startGame()
    {
        ArrayList<Player> players = new ArrayList<>();
        players.add(new Player("P1", Player.PlayerType.HUMAN));
        game.setPlayers(players);
        PlayerCondition p_c = new PlayerCondition(30,100000);
        Assertions.assertTrue(p_c.isGameEnded(game));

    }*/

    @Test
    void nextTurn()
    {
        ArrayList<Player> players = new ArrayList<>();
        players.add(new Player("P1", Player.PlayerType.HUMAN));
        players.add(new Player("P2", Player.PlayerType.HUMAN));
        players.add(new Player("P3", Player.PlayerType.HUMAN));
        game.setPlayers(players);

        game.setActivePlayer(players.get(0));

        game.nextTurn();
        Assertions.assertEquals(players.get(1), game.getActivePlayer());

        game.nextTurn();
        Assertions.assertEquals(players.get(2), game.getActivePlayer());

        game.nextTurn();
        Assertions.assertEquals(players.get(0), game.getActivePlayer());
    }
}
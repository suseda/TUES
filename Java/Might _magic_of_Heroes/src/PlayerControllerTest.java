import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class PlayerControllerTest {

    private PlayerController playerController;
    private Map gameMap;
    private ArrayList<Player> players;

    @BeforeEach
    public void setup() {
        gameMap = new Map(4,4);
        players = new ArrayList<>();
        playerController = new PlayerController(gameMap, players) {
            @Override
            public void startTurn(Player activePlayer) {}
        };
    }

    @Test
    void findPathTo()throws Exception
    {
        Hero hero = new Hero("Hero1", 1, 5.0, 2, new Position(0, 0), new Cell(new Empty(),new Position(0,0)));
        gameMap.setCell(0,0,new Empty());
        gameMap.setCell(1,0,new Empty());
        gameMap.setCell(2,0,new Empty());

        ArrayList<Cell> expectedPath = new ArrayList<>();
        expectedPath.add(gameMap.getCell(0, 0));
        expectedPath.add(gameMap.getCell(1, 0));
        expectedPath.add(gameMap.getCell(2, 0));

        ArrayList<Cell> path = playerController.findPathTo(hero, 2, 0);

        Assertions.assertEquals(expectedPath, path);

    }

    /*@Test
    void moveHero()throws Exception {
        Player activePlayer = new Player("P1", Player.PlayerType.HUMAN);
        Hero hero = new Hero("Hero1", 1, 5.0, 2, new Position(0, 0), new Cell(new Empty(), new Position(0, 0)));

        activePlayer.getHeroes().add(hero);
        players.add(activePlayer);

        gameMap.setCell(0, 0, new Empty());
        gameMap.setCell(1, 0, new Empty());
        gameMap.setCell(2, 0, new Empty());

        PlayerController playerController = new HumanController(gameMap, players);

        playerController.moveHero(hero, 2, 0);

        Assertions.assertEquals(gameMap.getCell(2, 0), hero.getCurrCell());

    }*/
}
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HeroTest {

    private Hero hero;

    @BeforeEach
    public void setUp() {
        Cell currCell = new Cell(new Empty(), new Position(0, 0));
        hero = new Hero("Hero", 1, 10, 2, new Position(0, 0), currCell);
    }

    @Test
    void compareTo()
    {
        Cell cell = new Cell(new Empty(),new Position(0,0));
        Hero hero1 = new Hero("Hero1", 2, 10.0, 2, new Position(0, 0), cell);
        Hero hero2 = new Hero("Hero2", 1, 5.0, 2, new Position(0, 0), cell);

        int result = hero1.compareTo(hero2);

        Assertions.assertTrue(result > 0);
    }

    @Test
    void compareArmies()
    {
        Cell cell = new Cell(new Empty(),new Position(0,0));
        Hero hero1 = new Hero("Hero1", 1, 5.0, 2, new Position(0, 0), cell);
        Hero hero2 = new Hero("Hero2", 2, 10.0, 2, new Position(0, 0), cell);

        int result = hero1.compareArmies(hero2);

        Assertions.assertEquals(0, result);
    }

    @Test
    void moveTo()
    {
        Map map = new Map(3, 3);
        Cell targetCell = new Cell(new Empty(), new Position(2, 2));
        map.setCell(0, 1, new Empty());
        map.setCell(1, 1, new Empty());
        map.setCell(2, 1, new Empty());
        map.setCell(1, 0, new Empty());
        map.setCell(1, 2, new Empty());
        map.setCell(2, 2, new Empty());

        hero.setCurrCell(map.getCell(0, 0));

        hero.moveTo(targetCell, map, new Player("P1", Player.PlayerType.HUMAN));

        Assertions.assertEquals(targetCell, hero.getCurrCell());
    }
}
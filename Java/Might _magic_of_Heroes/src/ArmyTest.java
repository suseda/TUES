import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ArmyTest {

    @Test
    void doSomething()
    {
        Player activePlayer = new Player("Active Player", Player.PlayerType.HUMAN);
        Hero heroOnThisCell = new Hero("Hero1", 1, 5.0, 2, new Position(0, 0), new Cell(new Army(null, null), new Position(0, 0)));
        Army army = new Army(heroOnThisCell, activePlayer);

        activePlayer.getHeroes().add(heroOnThisCell);
        activePlayer.getHeroes().add(new Hero("Hero2", 2, 6.0, 3, new Position(1, 1), new Cell(new Empty(), new Position(1, 1))));

        army.doSomething(activePlayer);

        Assertions.assertEquals(heroOnThisCell, army.getHero_on_this_cell());
        Assertions.assertEquals(activePlayer, army.getCellOwner());
    }

    /*@Test
    void war()
    {
        Player activePlayer = new Player("Active Player", Player.PlayerType.HUMAN);
        Player cellOwner = new Player("Cell Owner", Player.PlayerType.HUMAN);
        Cell army_cell = new Cell(new Army(null, null),new Position(0,0));
        Hero heroOnThisCell = new Hero("Hero1", 1, 10.0, 2, army_cell.getPos(),army_cell);
        Army army = new Army(heroOnThisCell, cellOwner);
        army_cell.setType(new Army(army.getHero_on_this_cell(),army.getCellOwner()));

        activePlayer.getHeroes().add(new Hero("Hero2", 2, 5.0, 3, army_cell.getPos(), army_cell));

        army.war(activePlayer, activePlayer.getHeroes().get(0));

        Assertions.assertTrue(heroOnThisCell.getArmies_power() > 0);
        Assertions.assertFalse(activePlayer.getHeroes().contains(activePlayer.getHeroes().get(0)));
    }*/
}
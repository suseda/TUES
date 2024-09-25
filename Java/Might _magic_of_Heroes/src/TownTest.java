import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TownTest {

    @Test
    void doSomething()
    {
        Player p = new Player("P1", Player.PlayerType.HUMAN);
        p.setMoney(2000);
        Town town = new Town();
        Cell town_cell = new Cell(new Town(),new Position(0,0));
        Hero h = new Hero("Hero1",3,10,3,new Position(0,0),town_cell);
        p.getHeroes().add(h);
        p.setActiveHero(h);
        town.doSomething(p,100);
        Assertions.assertEquals(1000,p.getMoney());
    }
}
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MineTest {

    @Test
    void doSomething()
    {
        Player p = new Player("P1", Player.PlayerType.HUMAN);
        p.setMoney(1000);
        p.getHeroes().add(new Hero("Hero1",3,10,3,new Position(0,0),new Cell(new Mine(p),new Position(0,0))));
        p.getHeroes().get(0).getCurrCell().getType().doSomething(p);
        Assertions.assertEquals(2000,p.getMoney());
    }
}
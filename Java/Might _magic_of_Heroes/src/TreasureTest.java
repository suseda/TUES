import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import javax.print.attribute.standard.JobHoldUntil;
import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class TreasureTest {

    @Test
    void doSomething()
    {
        Player p = new Player("P1", Player.PlayerType.HUMAN);
        p.getHeroes().add(new Hero("Hero1",3,10,3,new Position(0,0),new Cell(new Treasure(),new Position(0,0))));
        p.getHeroes().get(0).getCurrCell().getType().doSomething(p);
        Assertions.assertEquals(4,p.getHeroes().get(0).getLevel());
    }
}
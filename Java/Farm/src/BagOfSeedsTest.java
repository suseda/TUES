import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BagOfSeedsTest {

    @Test
    void use() throws Exception {
        BagOfSeeds bag = new BagOfSeeds("Apple",4,"tree");
        Farm farm = new Farm();
        Vector2 pos = new Vector2(1,1);
        farm.field[1][1] = new Cell(1);
        //Vector2 left = pos.left;
        bag.use_bag(farm,pos,bag.getName(),3);

        assertEquals(3,bag.getCount());

    }
}
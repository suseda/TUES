import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ToolTest {

     @Test
     void use() throws Exception {
        Farm farm = new Farm();
        Vector2 position = new Vector2(5,5);
        Item hoe = new Tool("Hoe");
        Seeding seeding = new FarmTree("Apple",0,0,false,3,"tree");
        farm.getCell(position).applyTool(hoe);
        farm.getCell(position).setSeeding(seeding);



        assertEquals(4,farm.getCell(position).getCondition());
    }

    @Test
    void testUse() {
    }
}
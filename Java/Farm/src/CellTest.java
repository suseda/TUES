import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CellTest {

    @Test
    void getCondition() throws Exception {
        Cell cell = new Cell(1);

        assertEquals(1,cell.getCondition());
    }

    @Test
    void setCondition() throws Exception {
        Cell cell = new Cell(1);
        cell.setCondition(3);

        assertEquals(3,cell.getCondition());
    }

    @Test
    void getSeeding() throws Exception {
        Cell cell = new Cell(1);
        Seeding seeding = new FarmTree("Apple",0,3,false,4,"tree");
        Item hoe = new Tool("Hoe");
        cell.applyTool(hoe);
        cell.setSeeding(seeding);

        assertEquals(seeding,cell.getSeeding());
    }

    @Test
    void setSeeding() throws Exception {
        Cell cell = new Cell(1);
        Item hoe = new Tool("Hoe");
        cell.applyTool(hoe);
        Seeding seeding1 = new FarmTree("Apple",0,3,false,5,"tree");
        cell.setSeeding(seeding1);

        Seeding seeding2 = new FarmTree("Pear",0,3,false,2,"tree");
        cell.setSeeding(seeding2);


        assertEquals(seeding2,cell.getSeeding());
    }

    @Test
    void applyTool() throws Exception {
        Item hoe = new Tool("Hoe");
        Item hand = new Tool("Hand");
        Cell cell = new Cell(1);

        cell.applyTool(hoe);
        assertEquals(3,cell.getCondition());
        Seeding seeding = new FarmCrop("Grain",false,2,"crop");

        cell.setSeeding(seeding);

        assertEquals(4,cell.getCondition());

        cell.applyTool(hand);

        assertEquals(1,cell.getCondition());
    }
}
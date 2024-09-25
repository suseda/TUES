import static org.junit.jupiter.api.Assertions.*;

class FarmTest {

    @org.junit.jupiter.api.Test
    void getCell() throws Exception {
        Farm farm = new Farm();
        Vector2 position = new Vector2(1,1);
        //Vector2 invalid = new Vector2(11,11);
        assertEquals(farm.field[1][1],farm.getCell(position));
        //assertEquals(farm.getCell(invalid), "Invalid cell");
    }

    @org.junit.jupiter.api.Test
    void isEmpty() throws Exception {
        Farm farm = new Farm();
        Vector2 position = new Vector2(1,1);
        farm.field[1][1] = new Cell(1);
        assertTrue(farm.isEmpty(position));
    }
}
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class MapTest {

    private Map map = new Map(4,4);

    @Test
    public void testGetMap() {
        Cell[][] grid = map.getMap();
        Assertions.assertEquals(4, grid.length);
        Assertions.assertEquals(4, grid[0].length);
    }

    @Test
    public void testSetCell() {
        Wall wall = new Wall();
        map.setCell(2, 2, wall);
        Cell cell = map.getCell(2, 2);
        Assertions.assertEquals(wall, cell.getType());
    }

    @Test
    public void testGetCell() {
        Cell cell = map.getCell(3, 2);
        Treasure tr = new Treasure();
        cell.setType(tr);
        Assertions.assertEquals(tr, cell.getType());
        Assertions.assertEquals(3, cell.getPos().x);
        Assertions.assertEquals(2, cell.getPos().y);
    }

    @Test
    public void testFindShortestPath() {
        Cell startCell = map.getCell(1, 1);
        Cell targetCell = map.getCell(3, 2);

        ArrayList<Cell> path = map.findShortestPath(startCell, targetCell);

        Assertions.assertFalse(path.isEmpty());
        Assertions.assertEquals(startCell, path.get(0));
        Assertions.assertEquals(targetCell, path.get(path.size() - 1));
    }
}
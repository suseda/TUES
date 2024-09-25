import java.util.*;

public class Map {
    private Cell[][] map;

    public Map(int rows, int cols) {
        this.map = new Cell[rows][];
        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0) {
                this.map[i] = new Cell[cols];
            } else {
                this.map[i] = new Cell[cols - 1];
            }
        }
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                this.map[i][j] = new Cell(new Empty(), new Position(i, j));
            }
        }
    }

    public Cell[][] getMap() {
        return map;
    }

    void setCell(int x, int y, CellType cellType) {
        try {
            if (x >= 0 && x < this.map.length && y >= 0 && y < this.map[0].length)
                getCell(x, y).setType(cellType);
            else
                throw new Exception();
        } catch (Exception e) {
            System.out.println("This cell doesn't exist");
        }
    }

    Cell getCell(int x, int y) {
        try {
            if (x >= 0 && x < this.map.length && y >= 0 && y < map[0].length)
                return this.map[x][y];
            else
                throw new Exception();
        } catch (Exception e) {
            System.out.println("This cell doesn't exist");
        }

        return null;
    }

    public ArrayList<Cell> findShortestPath(Cell startCell, Cell targetCell) {
        LinkedList<Cell> queue = new LinkedList<>();
        HashMap<Cell, Cell> parentMap = new HashMap<>();
        HashSet<Cell> visited = new HashSet<>();

        queue.offer(startCell);
        visited.add(startCell);

        while (!queue.isEmpty()) {
            Cell currentCell = queue.poll();

            if (currentCell == targetCell)
                break;

            List<Cell> neighbors = getAdjacentCells(currentCell);

            for (Cell neighbor : neighbors) {
                if (!visited.contains(neighbor) && neighbor.getType() instanceof Empty) {
                    queue.offer(neighbor);
                    visited.add(neighbor);
                    parentMap.put(neighbor, currentCell);
                }
            }
        }

        ArrayList<Cell> path = new ArrayList<>();
        Cell cell = targetCell;
        while (cell != null) {
            path.add(0, cell);
            cell = parentMap.get(cell);
        }

        return path;
    }

    private boolean isValidCell(int x, int y) {
        return x >= 0 && x < map.length && y >= 0 && y < map[x].length;
    }

    private List<Cell> getAdjacentCells(Cell cell) {
        int x = cell.getPos().x;
        int y = cell.getPos().y;
        List<Cell> neighbors = new ArrayList<>();

        if (x % 2 == 0) {
            addCell(neighbors, x, y - 1);
            addCell(neighbors, x, y + 1);
            addCell(neighbors, x - 1, y - 1);
            addCell(neighbors, x - 1, y);
            addCell(neighbors, x + 1, y - 1);
            addCell(neighbors, x + 1, y);
        } else {
            addCell(neighbors, x, y - 1);
            addCell(neighbors, x, y + 1);
            addCell(neighbors, x - 1, y);
            addCell(neighbors, x - 1, y + 1);
            addCell(neighbors, x + 1, y);
            addCell(neighbors, x + 1, y + 1);
        }

        return neighbors;
    }

    private void addCell(List<Cell> neighbors, int x, int y) {
        if (isValidCell(x, y)) {
            neighbors.add(map[x][y]);
        }
    }
}

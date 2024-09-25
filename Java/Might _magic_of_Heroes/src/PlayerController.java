import java.util.ArrayList;


public abstract class PlayerController implements Runnable {

    protected Player activePlayer;
    protected Map gameMap;
    protected ArrayList<Player> players;

    public PlayerController(Map gameMap, ArrayList<Player> players) {
        this.gameMap = gameMap;
        this.players = players;
    }


    public void run() {

    }



    protected void setActivePlayer(Player player) {
        this.activePlayer = player;
    }




    protected ArrayList<Cell> findPathTo(Hero hero, int x, int y) throws Exception {
        Cell startCell = gameMap.getCell(hero.getPos().x, hero.getPos().y);
        Cell targetCell = gameMap.getCell(x, y);

        if (startCell == null || targetCell == null) {
            throw new Exception("Invalid cell coordinates.");
        }

        ArrayList<Cell> path = gameMap.findShortestPath(startCell, targetCell);

        if (path.isEmpty()) {
            throw new Exception("No path to the target cell.");
        }

        return path;
    }


    protected void moveHero(Hero hero, int x, int y) throws Exception {
        if (!(activePlayer.getHeroes().contains(hero))) {
            throw new Exception("Hero does not belong to the active player.");
        }

        ArrayList<Cell> path = findPathTo(hero, x, y);

        for (Cell cell : path) {
            if (cell.getType() instanceof Empty) {
                hero.moveTo(cell,gameMap,activePlayer);
            } else
            {
                throw new Exception("Cannot traverse through this cell.");
            }

        }
    }

    public abstract void startTurn(Player activePlayer);
}
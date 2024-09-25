import java.util.ArrayList;

public class Game
{
    private ArrayList<Player> players;
    private Player activePlayer;
    private Map map_of_the_game;
    private HumanController controller;
    private GameEndingCondition gameEndingCondition;


    public Game(Map map_of_the_game, GameEndingCondition gameEndingCondition)
    {
        this.map_of_the_game = map_of_the_game;
        this.gameEndingCondition = gameEndingCondition;
    }

    public ArrayList<Player> getPlayers() {
        return players;
    }

    public Player getActivePlayer() {
        return activePlayer;
    }

    public Map getMap_of_the_game() {
        return map_of_the_game;
    }

    public HumanController getController() {
        return controller;
    }

    public void setPlayers(ArrayList<Player> players) {
        this.players = players;
    }

    public void setActivePlayer(Player activePlayer) {
        this.activePlayer = activePlayer;
    }

    public void setMap_of_the_game(Map map_of_the_game) {
        this.map_of_the_game = map_of_the_game;
    }

    public void setController(HumanController controller) {
        this.controller = controller;
    }

    public void setPlayer(Player player) {
        this.players.add(player);
    }

    public void startGame() {
        if (players == null || players.isEmpty()) {
            throw new IllegalStateException("No players have been added.");
        }
        setActivePlayer(players.get(0));
        while (!gameEndingCondition.isGameEnded(this)) {
            controller.startTurn(activePlayer);
            if (gameEndingCondition.isGameEnded(this))
                break;

            nextTurn();
        }

    }

    public void nextTurn()
    {
        if(players.indexOf(activePlayer) == players.size() - 1)
            activePlayer = players.get(0);
        else
        {
            int activePlayerIndex = players.indexOf(activePlayer);
            activePlayer = players.get(activePlayerIndex + 1);
        }
    }

}


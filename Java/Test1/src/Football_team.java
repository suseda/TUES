import java.util.List;

public class Football_team extends Team {
    //private Vector<String> positions;
    private class PlayerTuple {
        public Football_player player;
        public String position;

        public PlayerTuple(Football_player player, String position) {
            this.player = player;
            this.position = position;
        }
    }

    private List<PlayerTuple> players;

    @Override
    protected void addPlayer(Player p) {
        //players.add(p);
    }

    public void addPlayer(Football_player p, String position) {
        players.add(new PlayerTuple(p, position));
    }
}

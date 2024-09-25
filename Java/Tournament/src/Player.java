public class Player implements Comparable<Player>
{
    private int rank;
    private String name;

    public Player(int rank, String name) {
        this.rank = rank;
        this.name = name;
    }

    public int getRank() {
        return rank;
    }

    public void setRank(int rank) {
        this.rank = rank;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public int compareTo(Player player) {
        return Integer.compare(getRank(),player.getRank());
    }
}

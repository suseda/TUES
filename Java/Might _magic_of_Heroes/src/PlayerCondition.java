public class PlayerCondition implements GameEndingCondition
{
    private int level;
    private int max_money;

    public PlayerCondition(int level,int max_money) {
            this.level = level;
            this.max_money = max_money;
    }

    @Override
    public boolean isGameEnded(Game game) {
        for (Player player : game.getPlayers()) {
            for (Hero hero : player.getHeroes()) {
                if (hero.getLevel() >= level || player.getMoney() >= 100000) {
                       return true;
                }
            }
        }

        if(game.getPlayers().size() == 1)
            return true;
        return false;
    }

}
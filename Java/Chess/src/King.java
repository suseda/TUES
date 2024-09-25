public class King extends Figure
{
    public King(Figure[][] game, String position, String player, String sign)
    {
        super(game,position, player,sign);
    }

    boolean isCheck()
    {
        return false;
    }

    boolean isMate()
    {
        return false;
    }
}

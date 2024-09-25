public class Figure
{
    Figure[][] game;
    String position,player;
    String sign;

    protected static class Invalidmove extends Exception
    {
        public Invalidmove() {}
    }
    public Figure(Figure[][] game, String position, String player, String sign)
    {
        this.game = game;
        this.position = position;
        this.player = player;
        this.sign = sign;
    }

    void move(String pos) throws Invalidmove
    {
            if(canMove(pos) == false)
            {
                throw new Invalidmove();
            }
            else
            {
                int col1 = position.charAt(0) - 'A';
                int row1 = ((int) position.charAt(1));


                int col2 = pos.charAt(0) - 'A';
                int row2 = ((int) pos.charAt(1));

                String figure_sign = game[row1][col1].sign;
                String figure_pos = game[row1][col1].position;
                game[row1][col1].sign = "-";

                game[row2][col2].sign = figure_sign;
                game[row2][col2].sign = figure_pos;
            }
    }

    boolean canMove(String pos)
    {
        switch(sign)
        {
            case "P":

        }
        return true;
    }

}

public class Chess
{
    Figure[][] board;
    String player = null;


    public Chess() {
        this.board = board;
        this.player = "white";
    }

    Figure getAt(String pos)
    {
        int col = pos.charAt(0) - 'A';
        int row = ((int) pos.charAt(1));

        return board[row][col];
    }

    void moveFigure(String pos1, String pos2)
    {
        int col1 = pos1.charAt(0) - 'A';
        int row1 = ((int) pos1.charAt(1));


        int col2 = pos2.charAt(0) - 'A';
        int row2 = ((int) pos2.charAt(1));

        if(board[row1][col1].canMove(pos2))
        {
            String figure_pos = board[row1][col1].position;
            board[row1][col1].position = "-";
            board[row2][col2].position = figure_pos;
            if(player == "white")
                player = "black";
            else
                player = "white";
        }


    }

    void checkForWinner()
    {

    }

    void print_board()
    {
        System.out.println("  A B C D E F G H");
        for(int i = 0; i < 8;i++)
        {
            System.out.println(i+1);
            for (int j = 0; j < 8;j++)
            {
                System.out.println(" " + board[i][j]);
            }
        }
    }
}

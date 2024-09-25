public class Main
{
    public static void main(String[] args)
    {
        Chess chess = new Chess();
        Figure pawn = new Pawn(chess.board, "A2","white","P");
        Figure knight = new Knight(chess.board, "B1","white","K");
        Figure rook = new Rook(chess.board, "A1","white","R");
        Figure bishop = new Bishop(chess.board, "C1","white","B");



    }
}
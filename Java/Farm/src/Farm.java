public class Farm
{
    Cell[][] field = new Cell[10][10];

    public Farm() throws Exception {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                field[i][j] = new Cell(1);
            }
        }
    }

    Cell getCell(Vector2 position) throws Exception
    {
        try
        {
            if(position.getX() > 10 || position.getX() < 0 || position.getY() > 10 || position.getY() < 0)
                throw new Exception("Invalid cell");
        }catch (Exception e)
        {
            throw new Exception("Invalid cell");
        }
        return field[position.getX()][position.getY()];
    }

    boolean isEmpty(Vector2 position)
    {
        if (field[position.getX()][position.getY()].getSeeding() == null)
            return true;
        return false;
    }
}

import java.util.Random;

public class GameEntity
{
    private Position pos;
    private String name;

    static int ID = 0;

    public GameEntity(Position pos, String name) throws Exception {
        this.pos = pos;
        try {
            this.name = name + String.valueOf(ID+1);
            ID = ID+1;
        }catch (Exception e)
        {
            throw new Exception("This name exist");
        }
    }



    public GameEntity()
    {
        this.pos = new Position(0,0);
        this.name = "Name";
    }

    public Position getPos() {
        return pos;
    }

    public String getName() {
        return name;
    }

    public void setPos(Position pos) {
        this.pos = pos;
    }

    public void setName(String name) {
        this.name = name;
    }
}

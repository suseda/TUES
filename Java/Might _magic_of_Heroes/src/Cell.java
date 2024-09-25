import java.util.ArrayList;

public class Cell
{
    private CellType type;
    private Position pos;

    public Cell(CellType type, Position pos)
    {
        this.type = type;
        this.pos = pos;
    }

    public CellType getType() {
        return type;
    }

    public void setType(CellType type) {
        this.type = type;
    }

    public Position getPos() {
        return pos;
    }

    public void setPos(Position pos) {
        this.pos = pos;
    }

    @Override
    public String toString() {
        return "Cell{" +
                "type=" + type +
                ", pos=" + "Position{" +
                "x=" + pos.x +
                ", y=" + pos.y +
                '}' +
                '}';
    }

    void step_on_this_cell(Player activePlayer)
    {
        if(this.type instanceof Treasure)
        {
            type.doSomething(activePlayer);
            setType(new Empty());
        }
        else if(this.type instanceof Mine)
        {
            type.doSomething(activePlayer);
        }
        else if(this.type instanceof Army)
        {
            type.doSomething(activePlayer);
        }
    }
}

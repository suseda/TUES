import java.util.ArrayList;

public class Hero implements Comparable<Hero>
{
    private String name;
    private int level;
    private double armies_power;
    private int move_len;
    private Cell currCell;

    private Position pos;

    public Hero(String name, int level, double armies_power, int move_len, Position pos, Cell currCell) {
        this.name = name;
        this.level = level;
        this.armies_power = armies_power;
        this.move_len = move_len;
        this.pos = pos;
        this.currCell = currCell;
    }

    public String getName() {
        return name;
    }

    public int getLevel() {
        return level;
    }

    public double getArmies_power() {
        return armies_power;
    }

    public int getMove_len() {
        return move_len;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public void setArmies_power(double armies_power) {
        this.armies_power = armies_power;
    }

    public void setMove_len(int move_len) {
        this.move_len = move_len;
    }

    public Position getPos() {
        return pos;
    }

    public Cell getCurrCell() {
        return currCell;
    }

    public void setCurrCell(Cell currCell) {
        this.currCell = currCell;
    }

    public void setPos(Position pos) {
        this.pos = pos;
    }

    @Override
    public String toString() {
        return "Hero{" +
                "name='" + name + '\'' +
                ", level=" + level +
                ", armies_power=" + armies_power +
                ", move_len=" + move_len +
                ", pos=" + "Position{" +
                "x=" + pos.x +
                ", y=" + pos.y +
                '}' +
                '}';
    }

    public String specialToString()
    {
        return "Hero{" +
                "name='" + name + '\'' +
                ", level=" + level +
                ", armies_power=" + armies_power + '}';
    }

    @Override
    public int compareTo(Hero hero)
    {
        return compareArmies(hero);
    }

    int compareArmies(Hero enemy)
    {
        double power1 = this.armies_power*Math.pow(1.1,this.level);
        double power2 = enemy.getArmies_power()*Math.pow(1.1, enemy.getLevel());

        if (power1 > power2)
            return 1;
        else
            return 0;
    }

    public void moveTo(Cell target, Map map,Player activePlayer)
    {
        int max_move = move_len;

        if (!(target.getType() instanceof Wall)) {
            ArrayList<Cell> shortestPath = map.findShortestPath(currCell, target);

            for (Cell cell : shortestPath) {
                setCurrCell(cell);
                max_move--;
                if (cell == target)
                {
                    cell.step_on_this_cell(activePlayer);
                    return;
                }

                if(max_move <= 0)
                {
                    System.out.println("There are only enough moves for" + currCell.getPos().toString());
                    return;
                }

            }
        } else {
            throw new RuntimeException("Cannot move to the target cell.");
        }
    }


}

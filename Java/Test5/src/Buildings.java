public class Buildings extends GameEntity
{
    String building_type;
    Position pos;

    public Buildings(Position pos, String building_type) throws Exception {
        super(pos, building_type);
        this.building_type = building_type;
    }
}

public class Resource extends GameEntity
{
    String type;
    int max_workers;

    public Resource(Position pos, String type, int max_workers) throws Exception {
        super(pos, type);
        this.type = type;
        this.max_workers = max_workers;
    }


}

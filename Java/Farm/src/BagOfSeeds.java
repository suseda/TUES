public class BagOfSeeds extends Item implements IUsableItem
{

    private int count;
    private String type;


    public BagOfSeeds(String name,int count, String type) throws  Exception
    {
        super(name);
        this.count = count;
        try
        {
            if(type != "tree" && type != "crop")
                throw new Exception("type must be tree or seed");
            this.type = type;
        }catch(Exception e) {
            throw new Exception(e);
        }

    }

    public int getCount() {
        return count;
    }

    public String getType() {
        return type;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public void setType(String type) {
        this.type = type;
    }

    void use_bag(Farm farm, Vector2 position, String name, int age_to_grow) throws Exception
    {
        if (!farm.isEmpty(position))
            throw new Exception("This cell isnt empty");

        if (type == "tree") {
            farm.getCell(position).setSeeding(new FarmTree(name, 0, age_to_grow, false,6,"tree"));
            setCount(getCount()-1);
        }

        if (type == "crop")
        {
            if(farm.getCell(position).getCondition() == 3) {
                farm.getCell(position).setSeeding(new FarmCrop(name, false,3,"crop"));
                setCount(getCount() - 1);
            }
        }


    }

    @Override
    void use(Farm farm, Vector2 position)
    {
        Vector2 direction = Vector2.up;
        int powerLevel = 1;
    }

    @Override
    void use(Farm farm, Vector2 position, Vector2 direction, int powerLevel) {

    }


    @Override
    public void applyItem(Farm farm, Vector2 position, String name, int age_to_grow) throws Exception {
        use_bag(farm,position,name,age_to_grow);
    }

}

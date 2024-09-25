public class Seeding extends BagOfSeeds
{

    private Boolean is_grown;


    public Seeding(String name, Boolean is_grown,int cnt, String type) throws Exception {
        super(name,cnt,type);
        this.is_grown = is_grown;
    }



    public Boolean getIs_grown() {
        return is_grown;
    }


    public void setIs_grown(Boolean is_grown) {
        this.is_grown = is_grown;
    }


    void applyTool(Item tool)
    {
        System.out.println("Apply the tool on cell with seeding not in the seeding because it is not planted!");
    }

}

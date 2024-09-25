public class Cell
{
    private int condition;
    private Seeding seeding;

    public Cell(int condition) throws Exception
    {
        try
        {
            if(condition != 1 && condition != 2 && condition != 3 && condition != 4 )
                throw new Exception("Invalid condition");

        }catch(Exception e)
        {
            throw new Exception("Field exception");
        }
        this.condition = condition;
        seeding = null;
    }

    public int getCondition() {
        return condition;
    }

    public void setCondition(int condition) {
        this.condition = condition;
    }

    public Seeding getSeeding() {
        return seeding;
    }

    public void setSeeding(Seeding seeding) {
        if(this.condition == 3)
        {
            this.seeding = seeding;
            this.condition = 4;
        }

        if(this.condition == 4)
            this.seeding = seeding;
    }

    void applyTool(Item tool) throws Exception
    {
        switch(this.condition)
        {
            case 1:
                if(tool.getName() == "Hoe")
                    this.condition = 3;
                break;
            case 2:
            case 3:
                System.out.println("This cell is dug up you need to plant it.");
                break;
            case 4:
                if(seeding.getType() == "crop")
                {
                    if(tool.getName() == "Hand")
                    {
                        this.condition = 3;
                        System.out.println("We take production of crop");
                        this.seeding = null;
                    }

                    if(tool.getName() == "Axe" || tool.getName() == "Hoe")
                    {
                        this.condition = 1;
                        this.seeding = null;
                        System.out.println("Production was destroyed");
                    }
                }
                else
                {
                    if(tool.getName() == "Axe")
                    {
                        this.condition = 1;
                        this.seeding = null;
                        System.out.println("Production was destroyed");
                    }

                    if(tool.getName() == "Hand")
                    {
                        if(seeding.getIs_grown())
                        {
                            System.out.println("We take production of tree");
                            ((FarmTree)seeding).setAge(0);
                            seeding.setIs_grown(false);
                        }
                        else
                            System.out.println("The production isnt grown");
                    }
                }

        }
    }

}

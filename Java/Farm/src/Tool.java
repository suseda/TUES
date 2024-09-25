public class Tool extends Item implements IUsableItem
{
    public Tool(String name) {
        super(name);
    }



    void applyTool(Item tool)
    {
        System.out.println("Apply tool on cell");
    }

    @Override
    void use(Farm farm, Vector2 position) throws Exception {
        Vector2 direction = Vector2.up;
        int powerLevel = 1;

        farm.getCell(position).applyTool(this);
    }

    @Override
    void use(Farm farm, Vector2 position, Vector2 direction, int powerLevel) throws Exception {
        if(powerLevel == 1)
            farm.getCell(position).applyTool(this);

        if(powerLevel == 2)
        {
            farm.getCell(position).applyTool(this);

            if(direction == Vector2.left)
            {
                position.setY(position.getY()-1);
                farm.getCell(position).applyTool(this);
                position.setY(position.getY()-1);
                farm.getCell(position).applyTool(this);
            }

            if(direction == Vector2.right)
            {
                position.setY(position.getY()+1);
                farm.getCell(position).applyTool(this);
                position.setY(position.getY()+1);
                farm.getCell(position).applyTool(this);
            }

            if(direction == Vector2.up)
            {
                position.setX(position.getX()+1);
                farm.getCell(position).applyTool(this);
                position.setX(position.getX()+1);
                farm.getCell(position).applyTool(this);
            }

            if(direction == Vector2.down)
            {
                position.setX(position.getX()-1);
                farm.getCell(position).applyTool(this);
                position.setX(position.getX()-1);
                farm.getCell(position).applyTool(this);
            }
        }

        if(powerLevel == 3)
        {

            if(direction == Vector2.left)
            {
                position.setX(position.getX()-1);
                position.setY(position.getY()-2);

                toolUse3x3(farm,position);
            }

            if(direction == Vector2.right)
            {
                position.setX(position.getX()-1);

                toolUse3x3(farm,position);
            }

            if(direction == Vector2.up)
            {
                position.setX(position.getX()-2);
                position.setY(position.getY()-1);

                toolUse3x3(farm,position);
            }

            if(direction == Vector2.down)
            {
                position.setY(position.getY()-1);

                toolUse3x3(farm,position);
            }
        }
    }

    @Override
    public void applyItem(Farm farm, Vector2 position, String name, int age_to_grow)
    {

    }

    void toolUse3x3(Farm farm,Vector2 position) throws Exception {
        for(int i = position.getX(); i < position.getX()+3; i++)
        {
            for(int j = position.getY(); j < position.getY()+3; j++)
            {
                Vector2 new_pos = new Vector2(i,j);
                farm.getCell(new_pos).applyTool(this);
            }
        }
    }


}

import java.util.ArrayList;
import java.util.Collections;
import java.util.Objects;

public class Inventory
{
    ArrayList<Item> positions = new ArrayList<Item>();

    public Inventory(){};

    void addItem(Item item) throws Exception
    {
        try
        {
            if(positions.size() > 10)
                throw new Exception("Inventory is full");

            if(item instanceof Tool)
            {
                for (Item position : positions) {
                    if (item.getName() == position.getName())
                        throw new Exception("This item exist");
                }
                positions.add(item);
            }

            if(item instanceof BagOfSeeds)
            {
                for (Item position : positions) {
                    if (item.getName() == position.getName()) {
                        ((BagOfSeeds) position).setCount(((BagOfSeeds) position).getCount() + ((BagOfSeeds) item).getCount());
                    }
                }
                positions.add(item);
            }



        }catch (Exception e)
        {
            throw new Exception(e);
        }
    }

    Item getItem(int index) throws Exception
    {
        try
        {
            if(index > 10 || index < 0)
                throw new Exception("Size must be between 0 and 10!");

            if (positions.get(index) == null)
                throw new Exception("This position is empty!");
        }catch (Exception e)
        {
            throw new Exception(e);
        }
        return (Item) positions.get(index);
    }
}

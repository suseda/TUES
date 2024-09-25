import java.util.ArrayList;

public class Worker extends GameEntity implements Runnable
{
    private int speed;
    private String resource_type;
    private Resource curr_res;
    private Buildings curr_building;
    private ArrayList<Buildings> buildings = new ArrayList<>();
    private ArrayList<Resource> resources = new ArrayList<>();

    public int getSpeed() {
        return speed;
    }

    public String getResource_type() {
        return resource_type;
    }

    public Resource getCurr_res() {
        return curr_res;
    }

    public ArrayList<Buildings> getBuildings() {
        return buildings;
    }

    public ArrayList<Resource> getResources() {
        return resources;
    }

    public Buildings getCurr_building() {
        return curr_building;
    }

    public void setCurr_building(Buildings curr_building) {
        this.curr_building = curr_building;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public void setResource_type(String resource_type) {
        this.resource_type = resource_type;
    }

    public void setCurr_res(Resource curr_res) {
        this.curr_res = curr_res;
    }

    public void setBuildings(ArrayList<Buildings> buildings) {
        this.buildings = buildings;
    }

    public void setResources(ArrayList<Resource> resources) {
        this.resources = resources;
    }

    public Worker(Position pos, int speed, String resource_type, ArrayList<Buildings> buildings, ArrayList<Resource> resources) throws Exception {
        super(pos, "Worker");
        this.speed = speed;
        this.resource_type = resource_type;
        this.buildings = buildings;
        this.resources = resources;
        this.curr_res = null;
        this.curr_building = null;
    }

    @Override
    public void run()
    {
        System.out.println("Worker start working");

        try {
            while (true) {
                if (this.curr_res == null)
                    synchronized (this) {
                        System.out.println(getName() + " is waiting for resource");
                        this.wait();
                    }
                System.out.println(getName() + " start diging");
                Thread.sleep(1000);

                if (this.curr_building == null)
                    synchronized (this) {
                        System.out.println(getName() + " is waiting for building");
                        this.wait();
                    }


                curr_res = null;
                curr_building = null;
            }
        } catch(InterruptedException ex) {
            System.out.println(getName() + " is exiting");
        }
    }

    public void take_resource(Resource res) {
        synchronized (this) {
            this.curr_res=res;
            System.out.println(getName() + " start moving");
            this.notify();
        }
    }

    public void change_pos(int speed, Position direction)
    {
        Position new_pos = this.getPos();
        if(this.getPos().x == direction.x)
        {
            if(this.getPos().y == direction.y)
            {
                new_pos.y = new_pos.y + speed;
            }
            else
            {
                this.setPos(direction);
                this.notify();
            }
        }
        else
        {
            new_pos.x = new_pos.x + speed;
        }
        this.setPos(new_pos);
    }

}

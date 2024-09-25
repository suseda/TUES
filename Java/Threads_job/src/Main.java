import java.util.ArrayList;

public class Main 
{

    public static void main(String[] args) throws Exception {
        ArrayList<Integer> Jobs = new ArrayList<Integer>();
        Jobs.add(1);
        Jobs.add(2);
        Jobs.add(3);
        Jobs.add(4);
        Jobs.add(5);

        Distribute d = new Distribute(Jobs.size());

        ArrayList<Integer> res = d.work(Jobs);

        for (Integer element : res)
        {
            System.out.println(element);
        }
    }
}
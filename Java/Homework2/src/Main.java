import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        QuadTree tree = new QuadTree(10,10,-10,-10);


        try {
            FileInputStream fis = new FileInputStream("figures");

            Scanner s = new Scanner(fis);
            int s_cnt = 0,r_cnt = 0, c_cnt = 0, t_cnt = 0;
            while(s.hasNext())
            {
                String str = s.next();

                switch(str)
                {
                    case "square":
                        s_cnt++;
                        tree.insert(new Square(str+s_cnt,s.nextDouble(),s.nextDouble(), s.nextInt()));
                        break;
                    case "rectangle":
                        r_cnt++;
                        tree.insert(new Rectangle(str+r_cnt,s.nextDouble(),s.nextDouble(),s.nextInt(),s.nextInt()));
                        break;
                    case "circle":
                        c_cnt++;
                        tree.insert(new Circle(str+c_cnt,s.nextDouble(),s.nextDouble(),s.nextInt()));
                        break;
                    case "trapezoid":
                        t_cnt++;
                        tree.insert(new Trapezoid(str+t_cnt,s.nextDouble(),s.nextDouble(),s.nextInt(),s.nextInt(),s.nextInt()));
                        break;
                }
            }

            fis.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }



        ArrayList<Pair> p = tree.Overlaps();
        System.out.println("Overlaps:");
        for(int i = 0; i < p.size();i++)
        {
            System.out.println(p.get(i).f1.name + "(" + p.get(i).f1.center.x + "," + p.get(i).f1.center.y + ")" + " - " + p.get(i).f2.name + "(" + p.get(i).f2.center.x + "," + p.get(i).f2.center.y + ")" );
        }
    }
}
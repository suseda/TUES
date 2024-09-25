import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        try
        {
            FileInputStream in = new FileInputStream("Input");
            Scanner s = new Scanner(in);
            ArrayList<Point> points = new ArrayList<Point>();
            ArrayList<Triangle> triangles = new ArrayList<Triangle>();

            while(s.hasNext())
            {
                int number_of_points = 3;
                while(number_of_points != 0)
                {
                    Point p = new Point(s.nextInt(), s.nextInt());
                    points.add(p);
                    number_of_points--;
                }

                Triangle t = new Triangle(points);
                triangles.add(t);
                points.clear();
            }

            FileOutputStream out = new FileOutputStream("Output");
            PrintStream ps = new PrintStream(out);

            for(int i = 0; i < triangles.size(); i++)
            {
                //ps.print("Area: " + triangles.get(i).area() + " Perimeter: " + triangles.get(i).perimeter());
                ps.write((int) triangles.get(i).area());
                ps.print(" ");
            }

        }catch (IOException e)
        {
           e.printStackTrace();
        }catch (RuntimeException e)
        {
            e.printStackTrace();
        }



    }
}
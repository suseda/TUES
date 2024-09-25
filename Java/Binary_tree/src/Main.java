import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        try {

            FileOutputStream fos = new FileOutputStream("tree_file.txt");
            PrintStream ps = new PrintStream(fos);
            Integer [] arr = new Integer [] {8, 4, 10, 12, 9};

            for (int i:arr) {
                ps.println(i);
            }

            fos.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }


        try
        {
            FileInputStream f = new FileInputStream("tree_file.txt");
            Scanner s = new Scanner(f);
            Node root = new Node(s.nextInt());
            Tree t = new Tree(root);

            while(s.hasNext())
                t.add(s.nextInt());

            t.print_tree(root);

            f.close();

        }catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        /*Node root = new Node(8);
        Tree t = new Tree(root);
        t.add(4);
        t.add(10);
        t.add(12);
        t.add(9);
        t.print_tree(root);*/
    }
}
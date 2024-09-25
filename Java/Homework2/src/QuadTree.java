import java.awt.*;
import java.util.ArrayList;

public class QuadTree
{
    Region area;
    ArrayList<Figure> figures = new ArrayList<Figure>();
    ArrayList<QuadTree> nodes = new ArrayList<QuadTree>();

    public QuadTree(double x1,double y1,double x2,double y2)
    {
        this.area = new Region(x1,y1,x2,y2);
    }

    public int check(ArrayList<QuadTree> nodes, Figure f)
    {
        if(nodes.get(0).area.CenterInRegion(f.center))
            return 0;

        if(nodes.get(1).area.CenterInRegion(f.center))
            return 1;

        if(nodes.get(2).area.CenterInRegion(f.center))
            return 2;

        if(nodes.get(3).area.CenterInRegion(f.center))
            return 3;
        return 0;
    }



    public void insert(Figure f)
    {
        if(nodes.size() != 0)
        {
            for(int i = 0; i < 4; i++)
            {
                if(nodes.get(i).area.CenterInRegion(f.center))
                {
                    nodes.get(i).insert(f);
                    return;
                }
            }
        }

        figures.add(f);

        if(figures.size() > 10)
        {
            double quadrantWidth = (area.x2 - area.x1) / 2;
            double quadrantHeight = (area.y2 - area.y1) / 2;

            nodes.add(new QuadTree(area.x1, area.y1, area.x1 + quadrantWidth, area.y1 + quadrantHeight));
            nodes.add(new QuadTree(area.x1, area.y1 + quadrantHeight, area.x1 + quadrantWidth, area.y2));
            nodes.add(new QuadTree(area.x1 + quadrantWidth, area.y1 + quadrantHeight, area.x2, area.y2));
            nodes.add(new QuadTree(area.x1 + quadrantWidth, area.y1, area.x2, area.y1 + quadrantHeight));


            for(int j = 0; j < figures.size();j++)
            {
                int index_to_place = check(nodes,figures.get(j));
                nodes.get(index_to_place).figures.add(figures.get(j));
                System.out.println(nodes.get(index_to_place).figures.size());
            }

        }
    }


    public void print()
    {

        for(int i = 0; i < nodes.size(); i++)
        {
            System.out.println("Node" + i + ": ");
            System.out.println(nodes.get(i).figures.size());
            for(int j = 0; j < nodes.get(i).figures.size(); j++)
            {
                System.out.println("In");
                nodes.get(i).figures.get(j).toString();
            }
        }

    }


    public void findOverlaps(Figure f1, Figure f2,ArrayList<Pair> pair_list)
    {
        char f1_type = f1.name.charAt(0);
        char f2_type = f2.name.charAt(0);

        switch(f1_type)
        {
            case 's':
                Square s = (Square) f1;
                switch (f2_type)
                {
                    case 's':
                        if(s.OverlapSquare((Square) f2) || f2.OverlapSquare(s))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'r':
                        if(s.OverlapRectangle((Rectangle) f2) || f2.OverlapSquare(s))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'c':
                        if(s.OverlapCircle((Circle) f2) || f2.OverlapSquare(s))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 't':
                        if(s.OverlapTrapezoid((Trapezoid) f2) || f2.OverlapSquare(s))
                            pair_list.add(new Pair(f1,f2));
                        break;
                }
                break;
            case 'r':
                Rectangle r = (Rectangle) f1;
                switch (f2_type)
                {
                    case 's':
                        if(r.OverlapSquare((Square) f2) || f2.OverlapRectangle(r))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'r':
                        if(r.OverlapRectangle((Rectangle) f2) || f2.OverlapRectangle(r))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'c':
                        if(r.OverlapCircle((Circle) f2) || f2.OverlapRectangle(r))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 't':
                        if(r.OverlapTrapezoid((Trapezoid) f2) || f2.OverlapRectangle(r))
                            pair_list.add(new Pair(f1,f2));
                        break;
                }
                break;
            case 'c':
                Circle c = (Circle) f1;
                switch (f2_type)
                {
                    case 's':
                        if(c.OverlapSquare((Square) f2) || f2.OverlapCircle(c))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'r':
                        if(c.OverlapRectangle((Rectangle) f2) || f2.OverlapCircle(c))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'c':
                        if(c.OverlapCircle((Circle) f2) || f2.OverlapCircle(c))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 't':
                        if(c.OverlapTrapezoid((Trapezoid) f2) || f2.OverlapCircle(c))
                            pair_list.add(new Pair(f1,f2));
                        break;
                }
                break;
            case 't':
                Trapezoid t = (Trapezoid) f1;
                switch(f2_type)
                {
                    case 's':
                        if(t.OverlapSquare((Square) f2) || f2.OverlapTrapezoid(t))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'r':
                        if(t.OverlapRectangle((Rectangle) f2) || f2.OverlapTrapezoid(t))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 'c':
                        if(t.OverlapCircle((Circle) f2) || f2.OverlapTrapezoid(t))
                            pair_list.add(new Pair(f1,f2));
                        break;
                    case 't':
                        if(t.OverlapTrapezoid((Trapezoid) f2) || f2.OverlapTrapezoid(t))
                            pair_list.add(new Pair(f1,f2));
                        break;
                }
                break;
        }
    }


    ArrayList<Pair> Overlaps()
    {
        ArrayList<Pair> pair_list = new ArrayList<Pair>();
        if(nodes.size() == 0)
        {
            for(int i = 0; i < figures.size(); i++)
            {
                for(int j = i+1; j < figures.size(); j++)
                {
                    Figure f1 = figures.get(i);
                    Figure f2 = figures.get(j);

                    findOverlaps(f1,f2,pair_list);
                }
            }
        }
        else
        {
            for(int i = 0; i < nodes.size();i++)
            {
                for(int j = 0; j < nodes.get(i).figures.size(); j++)
                {
                    for (int k = j + 1; k < nodes.get(i).figures.size(); k++)
                    {
                        Figure f1 = nodes.get(i).figures.get(j);
                        Figure f2 = nodes.get(i).figures.get(k);

                        findOverlaps(f1,f2,pair_list);
                    }
                }
            }
        }
        return pair_list;
    }

}

public class Main
{
    public static void print_shape(Shape s)
    {
        System.out.println("---------");
        System.out.println("| " + s.left_up + " | " + s.right_up + " |");
        System.out.println("---------");
        System.out.println("| " + s.left_down + " | " + s.right_down + " |");
        System.out.println("---------");
    }
    public static void main(String[] args)
    {
        System.out.println("Shape:");
        Shape s = new Shape('r','r','b', 'g');
        print_shape(s);
        System.out.println("==========================");

        System.out.println("Blue mine:");
        Mine blue_mine = new Mine('b', '0', '0', '1', '1');
        Shape blue_mine_shape1 = blue_mine.pull();
        Shape blue_mine_shape2 = blue_mine.pull();
        print_shape(blue_mine_shape1);
        print_shape(blue_mine_shape2);
        System.out.println("==========================");

        System.out.println("Yellow mine:");
        Mine yellow_mine = new Mine('y', '0', '0', '0', '1');
        Shape yellow_mine_shape1 = yellow_mine.pull();
        print_shape(yellow_mine_shape1);
        System.out.println("==========================");

        System.out.println("Rotate shape right :");
        Rotate_machine r_machine = new Rotate_machine('r');
        r_machine.push(s);
        s = r_machine.pull();
        print_shape(s);
        System.out.println("==========================");

        System.out.println("Rotate shape left :");
        Rotate_machine l_machine = new Rotate_machine('l');
        l_machine.push(s);
        s = l_machine.pull();
        print_shape(s);
        System.out.println("==========================");

        System.out.println("Split shape vertical:");
        Split_machine ver_machine = new Split_machine('v');
        ver_machine.push(s);
        print_shape(s);
        Shape splited_ver1 = ver_machine.pull();
        Shape splited_ver2 = ver_machine.pull();
        print_shape(splited_ver1);
        print_shape(splited_ver2);
        System.out.println("==========================");

        System.out.println("Split shape horizontal:");
        Split_machine hor_machine = new Split_machine('h');
        hor_machine.push(s);
        print_shape(s);
        Shape splited_hor1 = hor_machine.pull();
        Shape splited_hor2 = hor_machine.pull();
        print_shape(splited_hor1);
        print_shape(splited_hor2);
        System.out.println("==========================");

        System.out.println("Join shape:");
        Join_machine j_machine = new Join_machine();
        print_shape(blue_mine_shape1);
        print_shape(yellow_mine_shape1);
        j_machine.push(blue_mine_shape1);
        j_machine.push(yellow_mine_shape1);
        s = j_machine.pull();
        print_shape(s);
        System.out.println("==========================");
    }
}
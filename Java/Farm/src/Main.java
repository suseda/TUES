public class Main
{
    public static void print_farm(Farm farm) throws Exception {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                Vector2 v = new Vector2(i,j);
                if(farm.getCell(v).getCondition() == 1)
                    System.out.print("| X "); // Не е обработена
                else
                    if(farm.getCell(v).getCondition() == 3)
                        System.out.print("| o "); // Обработена е но не е засадена
                    else
                        System.out.print("| O "); // Засадена
            }
            System.out.println("");
        }
        System.out.println("---------------------------------------");
    }


    public static void main(String[] args) throws Exception {
        Player player = new Player("Kaloyan");
        Farm farm = new Farm();

        Item hoe = new Tool("Hoe");
        Item axe = new Tool("Axe");
        Item hand = new Tool("Hand");

        Item bag_of_apples = new BagOfSeeds("Apple",4,"tree");
        Item bag_of_grain = new BagOfSeeds("Grain",8,"crop");

        player.inventory.addItem(hoe);
        player.inventory.addItem(axe);
        player.inventory.addItem(hand);
        player.inventory.addItem(bag_of_apples);
        player.inventory.addItem(bag_of_grain);

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                farm.field[i][j] = new Cell(1);
            }
        }



        hoe.use(farm,new Vector2(5,5),Vector2.left,3); //Using Hoe
        farm.field[5][5].applyTool(player.inventory.getItem(0));
        ((BagOfSeeds) bag_of_grain).use_bag(farm,new Vector2(5,5), bag_of_grain.getName(), 3);
        print_farm(farm);

        farm.field[4][4].applyTool(player.inventory.getItem(0));
        ((BagOfSeeds) bag_of_grain).use_bag(farm,new Vector2(4,4), bag_of_grain.getName(), 3);
        print_farm(farm);

        hoe.use(farm,new Vector2(8,1),Vector2.right,2); //Using Hoe
        farm.field[8][1].applyTool(player.inventory.getItem(0));
        ((BagOfSeeds) bag_of_apples).use_bag(farm,new Vector2(8,1), bag_of_grain.getName(), 3);
        print_farm(farm);


        hoe.use(farm,new Vector2(1,7)); //Using Hoe
        farm.field[1][7].applyTool(player.inventory.getItem(0));
        ((BagOfSeeds) bag_of_apples).use_bag(farm,new Vector2(1,7), bag_of_grain.getName(), 3);
        print_farm(farm);

        axe.use(farm,new Vector2(1,7));
        farm.field[1][7].applyTool(player.inventory.getItem(1)); //Using Axe
        print_farm(farm);

        Seeding tree = new FarmTree("Pear", 2 ,3,false,4,"tree");

        hoe.use(farm,new Vector2(2,2)); //Using Hoe
        farm.field[2][2].applyTool(player.inventory.getItem(0));
        farm.field[2][2].setSeeding(tree);
        farm.field[2][2].applyTool(player.inventory.getItem(2)); // Using Hand
        ((FarmTree)farm.field[2][2].getSeeding()).processNextDay();
        farm.field[2][2].applyTool(player.inventory.getItem(2)); // Using Hand
        print_farm(farm);


        Seeding crop = new FarmCrop("Grain",true,4,"crop");

        hoe.use(farm,new Vector2(0,7)); //Using Hoe
        farm.field[0][7].applyTool(player.inventory.getItem(0));
        farm.field[0][7].setSeeding(crop);
        farm.field[0][7].applyTool(player.inventory.getItem(2)); // Using Hand
        print_farm(farm);
    }
}
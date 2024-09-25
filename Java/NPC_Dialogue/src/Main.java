import java.util.ArrayList;

public class Main {
    public static void main(String[] args)
    {
        ArrayList<String> items = new ArrayList<>();
        items.add("mech");
        items.add("bozdugan");
        items.add("luk i streli");
        items.add("kopie");
        Player p = new Player(30,20,15,100,items);

        //Answer 1
        String[] answers1 = {"Give me armor.","Give me the best armor."};
        DialogueStep answer1 = new DialogueStep(1,"I have some armors!",answers1,null);

        //Answer 2
        String[] answers2 = {"Thanks."};
        DialogueStep answer2 = new DialogueStep(2,"That is your prise!",answers2,null);

        //Answer 3
        DialogueStep answer3_1 = new DialogueStep(1,"You look awesome! I will give you my daughter.",answers2,null);
        String[] answers3_2 = {"I will kill you."};
        DialogueStep answer3_2 = new DialogueStep(1,"Haha you are such a loser!",answers3_2,null);
        DialogueStep[] answers_for_3 = { answer3_1, answer3_2};

        String[] answers3 = {"To marry your daughter.","To end your tyranny."};
        DialogueStep answer3 = new DialogueStep(3,"I am the king! What do you want?",answers3,answers_for_3);

        String[] answers_root = {"I want to buy armor.","I have slain the dragon", "I want to speak with the king."};
        DialogueStep[] steps_root = { answer1, answer2, answer3 };
        DialogueStep root = new DialogueStep(1,"Hello! How can I help you?",answers_root,steps_root);

        DialogueStep[] steps = { answer1, answer2, answer3};

        IOptional method1 = (player) -> {
            if(player.CHA > 5)
                 return true;
            return false;
        };

        IReward method2 = (player) -> {
            if(player.STR > 5)
                System.out.println("You get reward!");
            System.out.println("You didnt get reward!");
        };

        IRequirement method3 = (player) -> {
            if(player.HP > 5)
                System.out.println("You must give me your mech!");
            System.out.println("You must give me your eyes!");
        };

        DialogueTree tree = new DialogueTree(root,steps_root);

        tree.playGame(p);
    }
}
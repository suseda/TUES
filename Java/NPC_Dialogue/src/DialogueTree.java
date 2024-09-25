import java.util.ArrayList;
import java.util.Scanner;

public class DialogueTree
{
    DialogueStep curr_step;
    DialogueStep[] steps;

    public DialogueTree(DialogueStep curr_step, DialogueStep[] steps) {
        this.curr_step = curr_step;
        this.steps = steps;
    }

    DialogueStep findById(String id)
    {
        int index = Integer.parseInt(id);
        for(int i = 1; i < steps.length;i++)
        {
            if(i == index)
                return steps[i];
        }
        return null;
    }

    void print_answers(String[] answers)
    {
        for(int i = 0; i < answers.length;i++)
        {
            System.out.println(i);
            System.out.println(answers[i]);
        }
    }

    void playGame(Player p)
    {
        while(curr_step != null) {
            System.out.println(curr_step.NPC_words);
            for (int i = 0; i < steps.length; i++) {
                print_answers(steps[i].answers);
            }
            System.out.println("Enter your choice:");
            Scanner in = new Scanner(System.in);
            int num = in.nextInt();
            curr_step = steps[num];
        }
    }

}

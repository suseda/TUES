public class DialogueStep
{
    int id;
    String NPC_words;
    String answers[];
    DialogueStep next_step[];


    public DialogueStep(int id, String NPC_words, String[] answers, DialogueStep[] next_step)
    {
        try {
            this.id = id;
            this.NPC_words = NPC_words;
            this.answers = answers;
            this.next_step = next_step;
            if (answers == null)
                throw new RuntimeException();
            if (NPC_words == null)
                throw new RuntimeException();
        } catch (Exception e)
        {
            if (answers == null)
                System.out.println("Answers is null!");
            if (NPC_words == null)
                System.out.println("NPC text is empty!");
        }
    }


}

public class DialogueOption
{
    String text;
    DialogueStep next;

    public DialogueOption(String text, DialogueStep next) {
        this.text = text;
        this.next = next;
    }
}

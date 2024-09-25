public class MagicCard extends Cards
{
    IMagicEffect magic;


    public MagicCard(String name, String text, Player player,IMagicEffect magic)
    {
        super(name, text, player);
        this.magic = magic;
    }

    void apply(MonsterCard monster)
    {

    }
}

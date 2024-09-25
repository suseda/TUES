import java.util.ArrayList;

public class Player
{
    int health;
    ArrayList<MonsterCard> monsters;
    ArrayList<MagicCard> magic;
    ArrayList<MonsterCard> monsters_deck;
    ArrayList<MagicCard> magic_deck;
    ArrayList<MonsterCard> field;

    public Player(int health)
    {
        this.health = health;
    }

    public void Player_cards(ArrayList<MonsterCard> monsters, ArrayList<MagicCard> magic, ArrayList<MonsterCard> monsters_deck, ArrayList<MagicCard> magic_deck, ArrayList<MonsterCard> field)
    {
        this.monsters = monsters;
        this.magic = magic;
        this.monsters_deck = monsters_deck;
        this.magic_deck = magic_deck;
        this.field = field;
    }
    void drawMonster()
    {
        try {
            if (monsters.size() < 5) {
                monsters.add(monsters_deck.get(0));
                monsters_deck.remove(0);
            }
            else
                throw new RuntimeException();
        }catch(RuntimeException e)
        {
            System.out.println("You already have 5 monsters!");
        }

    }

    void drawSpell()
    {
        try {
            if (magic.size() < 5)
            {
                magic.add(magic_deck.get(0));
                magic_deck.remove(0);
            }
            else
                throw new RuntimeException();
        }catch(RuntimeException e)
        {
            System.out.println("You already have 3 spells!");
        }
    }

    void playMonster(MonsterCard m)
    {
        monsters.remove(m);
        field.add(m);
        drawMonster();
    }

    void playSpell(MagicCard magic, MonsterCard monster)
    {
        this.magic.remove(magic);
        magic.apply(monster);
        drawSpell();
    }


}

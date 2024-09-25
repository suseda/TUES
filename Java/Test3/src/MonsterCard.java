import java.util.ArrayList;

public class MonsterCard extends Cards
{
    int power,defense,curr_health,max_health;

    public MonsterCard(String name, String text, Player player,int power,int defense,int curr_health,int max_health)
    {
        super(name, text, player);
        this.power = power;
        this.defense = defense;
        this.curr_health = curr_health;
        this.max_health = max_health;
    }

    void attack(Player player)
    {
        if(player.field.size() == 0)
        {
            player.health -= power;
            if (player.health < 0)
                System.out.println("Player die!");
        }
        else
        {
            int damage = player.field.get(0).defense - power;
            if(damage <= 0)
                player.field.remove(0);
            else
                defense = defense - player.field.get(0).power;

            if(defense <= 0)
                this.player.field.remove(this);


        }
    }

}

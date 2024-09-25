import java.util.ArrayList;

public class Main {
    public static void main(String[] args)
    {
        Player p = new Player(30);
        MonsterCard m1 = new MonsterCard("RA","Cool",p,4000,4000,70,70);
        MonsterCard m2 = new MonsterCard("Exodia","Cool",p,3000,3000,50,80);
        MonsterCard m3 = new MonsterCard("Obelisk","Cool",p,1000,4000,90,90);

        ArrayList<MonsterCard> monsters = new ArrayList<MonsterCard>();
        monsters.add(m1);
        monsters.add(m2);
        monsters.add(m3);


        int power = 80;
        IMagicEffect effect = new IMagicEffect() {
            @Override
            public void magic(Player p, MonsterCard m,int power) {
                m.defense-=power;
            }

        };

    }
}
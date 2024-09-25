import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class Game
{
    ArrayList<Resource> game_resources = new ArrayList<>();
    ArrayList<Buildings> game_buildings = new ArrayList<>();

    int wood_cnt = 0,gold_cnt = 0;
    ArrayList<Worker> game_workers = new ArrayList<>();
    List<Thread> t = new ArrayList<>();

    public Game(ArrayList<Resource> game_resources, ArrayList<Buildings> game_buildings, ArrayList<Worker> game_workers)
    {
        this.game_resources = game_resources;
        this.game_buildings = game_buildings;
        this.game_workers = game_workers;
    }

    void startGame()
    {
        for(int i = 0; i < game_workers.size(); i++) {
            t.add(new Thread(game_workers.get(i)));
            t.get(i).start();
        }

        while (true)
        {
            for(int i = 0; game_resources.size() > 0; i++)
            {
                for (int j = 0; game_workers.size() > j; j++)
                {
                    if (game_workers.get(j).getCurr_res() == null)
                    {
                        game_workers.get(j).take_resource(game_resources.get(0));
                        //for(int k = 0; k < game_buildings.get(0).getPos().y ;k++)
                        game_workers.get(j).change_pos(game_workers.get(j).getSpeed(),game_buildings.get(0).getPos());
                    }
                }
            }
        }
    }//, който стартира всички нишки


    void endGame()
    {
        for(int i = 0; i < game_workers.size(); i++) {
            t.get(i).interrupt();
        }
    }//, който спира всички нишки

}

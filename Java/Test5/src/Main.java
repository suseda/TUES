import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {

        Buildings building1 = new Buildings(new Position(4,4),"wood");
        ArrayList<Buildings> buildings = new ArrayList<>();
        buildings.add(building1);

        Resource res1 = new Resource(new Position(2,2),"wood", 3);
        ArrayList<Resource> resources = new ArrayList<>();
        resources.add(res1);



        Worker w1 = new Worker(new Position(0,0), 2, "wood",buildings,resources);
        Worker w2 = new Worker(new Position(0,0), 2, "gold",buildings,resources);
        Worker w3 = new Worker(new Position(0,0), 2, "wood",buildings,resources);
        ArrayList<Worker> workers = new ArrayList<>();
        workers.add(w1);
        workers.add(w2);
        workers.add(w3);

        Game game = new Game(resources,buildings,workers);

        game.startGame();


    }
}
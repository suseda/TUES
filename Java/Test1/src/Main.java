public class Main {
    public static void main (String[]args){
          //FootballPlayer p = new FootballPlayer("Ivan", 25, "BG", 100, 10, 1, "goalkeeper");
          //System.out.println(p);

        Tennis_team t = new Tennis_team();
        try {
            t.addPlayer(new Tennis_player());
        } catch (IllegalArgumentException ex) {
            System.out.println("Cannot add player");
            ex.printStackTrace();
        } catch (Exception ex) {
            System.out.println("Generic exception");
            ex.printStackTrace();
            throw ex;
        }
    }
}
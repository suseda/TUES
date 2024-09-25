public class Main {
    public static void main(String[] args)
    {
        Pinkponk pinkponk1 = new Pinkponk(true,null);
        Thread racket1 = new Thread(pinkponk1);
        Pinkponk pinkponk2 = new Pinkponk(false,pinkponk1);
        Thread racket2 = new Thread(pinkponk2);
        pinkponk1.obj = pinkponk2 ;



        racket1.start();
        racket2.start();
    }
}
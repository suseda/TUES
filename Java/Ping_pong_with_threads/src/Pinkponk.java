public class Pinkponk implements Runnable
{
    boolean isBallHere;
    Pinkponk obj;

    Object obj2 = Pinkponk.class;

    public Pinkponk(boolean isBallHere, Pinkponk obj) {
        this.isBallHere = isBallHere;
        this.obj = obj;
    }

    @Override
    public void run()
    {
        while(true)
        {
            if(isBallHere)
            {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                System.out.println("Ball is passed " + Thread.currentThread().getName());

                synchronized (obj2)
                {
                    isBallHere = false;
                    obj2.notify();

                }

            }
            else
            {

                try
                {
                    synchronized (obj2)
                    {
                        obj2.wait();
                        System.out.println("Ball is received " + Thread.currentThread().getName());
                        isBallHere = true;
                    }
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }

            }
        }
    }
}

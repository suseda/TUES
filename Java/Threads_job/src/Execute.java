import java.util.concurrent.Callable;

public class Execute implements Callable
{
    Thread tr = new Thread();
    Integer num;

    public Execute(Integer num)
    {
        this.num = num;
    }

    @Override
    public Integer call() throws Exception
    {
        int res = 0;
        try
        {
            res = num * num;
            Thread.sleep(2000);
        }catch (Exception e)
        {
            throw new Exception("Exception");
        }

        return res;
    }


}

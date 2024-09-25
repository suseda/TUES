import java.util.ArrayList;

public class Distribute
{
    int tr_cnt;

    public Distribute(int tr_cnt)
    {
        this.tr_cnt = tr_cnt;
    }

    public ArrayList<Integer> work(ArrayList<Integer> jobs) throws Exception {
        ArrayList<Integer> res = jobs;
        ArrayList<Execute> ex = new ArrayList<>();

        for ( int i = 0 ; i < jobs.size() ; i++ )
        {
            ex.add(new Execute(jobs.get(i)));
        }

        for ( int i = 0 ; i < jobs.size() ; i++ )
        {
            res.add(ex.get(i).call());
        }

        return res;
    }
}

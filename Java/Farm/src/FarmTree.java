public class FarmTree extends Seeding
{
    private int age, days_to_grow;
    public FarmTree(String name, int age, int days_to_grow, Boolean is_grown,int cnt, String type) throws Exception {
        super(name, is_grown,cnt,type);
        this.days_to_grow = days_to_grow;
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public int getDays_to_grow() {
        return days_to_grow;
    }


    public void setAge(int age) {
        this.age = age;
    }

    public void setDays_to_grow(int days_to_grow) {
        this.days_to_grow = days_to_grow;
    }


    void processNextDay()
    {
        setAge(getAge()+1);
        System.out.println("One day is gone");
        if(getAge() == 3)
            setIs_grown(true);

    }
}

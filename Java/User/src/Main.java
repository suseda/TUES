import java.util.Arrays;

public class Main
{
    public static void main(String[] args)
    {
        String[] actions = {"action1","action2","action3"};
        Module[] module = {new Module(actions),new Module(actions),new Module(actions)};
        Role[] roles = { new Role(module), new Role(module), new Role(module)};
        User Kaloyan = new User("Kaloyan","kaloyan.ya.sotirov.2019@elsys-bg.org",roles);
        System.out.println(Arrays.toString(Kaloyan.GetActions()));
    }
}
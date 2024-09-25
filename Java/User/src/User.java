import java.util.Arrays;
import java.util.Objects;

public class User
{
    String name, email;
    Role []roles;

    User(String new_name,String new_email,Role []new_r)
    {
        this.name=new_name;
        this.email=new_email;
        this.roles=new_r;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public Role[] getR() {
        return roles;
    }

    public void setR(Role[] r) {
        this.roles = r;
    }

    String []GetActions()
    {
        String []actions = new String[1];
        int cnt=0;
        for(int i=0;i<this.roles.length;i++)
        {
            for(int j=0;j<this.roles[i].getModules().length;j++)
            {
                for(int l=0;l<this.roles[i].getModules()[j].getActions().length;l++)
                {
                    actions[cnt++] = this.roles[i].getModules()[j].getActions()[l];
                    actions = Arrays.copyOf(actions,actions.length+1);
                }
            }
        }
        return actions;
    }

}

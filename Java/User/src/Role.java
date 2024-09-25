public class Role
{
    private Module []modules;

    public Role(Module []new_modules)
    {
        this.modules=new_modules;
    }

    public Module[] getModules() {
        return modules;
    }

    public void setModules(Module[] modules) {
        this.modules = modules;
    }
}

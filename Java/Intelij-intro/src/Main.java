import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello");
        System.out.println(Test.var1);
        Test.baz();
        Test.baz();
        Test.var1++;
        //(new Test()).foo().bar();

        //Stream.of(1,2,3).map(v->v+1).count();
    }
}

class Test{
    public static int counter = 0;
    public static int var1 = 5;

    public static void baz() {
        System.out.println("Test.baz");
    }

    private int var2;

    public void setVar2(int var2) {
        this.var2 = var2;
    }

    public int getVar2() {
        return var2;
    }

    public Test(int var2) {
        this.var2 = var2;
    }

    public Test() {
        counter++;
    }

    public Test foo() {
        System.out.println("Test.foo");
        return this;
    }

    public void bar() {
        System.out.println("Test.bar");
    }

    public class InnerClass{

    }
}
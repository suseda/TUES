import java.io.OutputStreamWriter;

public class Person
{
    private String name, surname;
    private char sex;

    public Person(String name, String surname, char sex) {
        this.name = name;
        this.surname = surname;
        this.sex = sex;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public char getSex() {
        return sex;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setSex(char sex) {
        this.sex = sex;
    }

}

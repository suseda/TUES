import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.lang.String;

public class Student extends Person implements Comparable<Student> //implements Entity
{
    private static int new_id = 0;
    private int number_in_class, ID;
    private List<Subject> marks;
    private SchoolClass school_class;
    private School school;

    public Student(String name, String surname, char sex, int number_in_class, SchoolClass school_class, School school) {
        super(name, surname, sex);
        this.number_in_class = number_in_class;
        this.ID = this.getID();
        this.marks = new ArrayList<>();
        this.school_class = school_class;
        this.school = school;
    }

    public int getNumber_in_class() {
        return number_in_class;
    }

    public int getID() {
        return ++new_id;
    }

    public List<Subject> getMarks() {
        return marks;
    }

    public SchoolClass getSchool_class() {
        return school_class;
    }

    public School getSchool() {
        return school;
    }


    public void setNumber_in_class(int number_in_class) {
        this.number_in_class = number_in_class;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setMarks(List<Subject> marks) {
        this.marks = marks;
    }

    public void setSchool_class(SchoolClass school_class) {
        this.school_class = school_class;
    }

    public void setSchool(School school) {
        this.school = school;
    }

    void addMark(String subject, float mark)
    {
        for (int i = 0; i < marks.size(); i++)
        {
            if(marks.get(i).getName() == subject)
            {
                marks.get(i).getMarks().add(mark);
                return;
            }
        }
        Subject new_subject = new Subject(subject);
        new_subject.getMarks().add(mark);
        marks.add(new_subject);
    }

    List<Float> getMarks(String subject)
    {
        for (int i = 0; i < marks.size();i++)
        {
            if(marks.get(i).getName() == subject)
                return marks.get(i).getMarks();
        }
        return new ArrayList<Float>();
    }

    @Override
    public int compareTo(Student student) {
        return Integer.compare(getNumber_in_class(), student.getNumber_in_class());
    }


    void dump(OutputStreamWriter osw) throws IOException {
        try {
            osw.write(getName());
            osw.write(",");
            osw.write(getSurname());
            osw.write(",");
            osw.write(getSex());
            osw.write(",");
            osw.write(getID());
            osw.write(",");
            osw.write(getNumber_in_class());
            osw.write(",");
            osw.write(getClass().getName());

            for (int i = 0; i < marks.size();i++)
            {
                osw.write(marks.get(i).getName());
                osw.write(",");
                for (int j = 0; j < marks.get(i).getMarks().size();j++)
                {
                    osw.write(String.valueOf(marks.get(i).getMarks().get(j)));
                    osw.write(",");
                }
            }
        } catch (IOException e)
        {
            throw new RuntimeException(e);
        }
        //<име>, <фамилия>, <пол>, <уникален номер>, <номер в клас>, <име на класа>, <предмет 1>, <оценка 1>, ..., <оценка N>, <предмет 2>, <оценка 1>, ... <оценка N>, ...
    }

    float getAverage(String subject)
    {
        for(int i = 0; i < marks.size(); i++)
        {
            if(marks.get(i).getName() == subject)
            {
                float avg = 0;
                for (int j = 0; j < marks.get(i).getMarks().size(); j++)
                {
                    avg+=marks.get(i).getMarks().get(j);
                }
                return avg/marks.get(i).getMarks().size();
            }
        }
        return 2;
    }

    float getAverage()
    {
        float avg = 0;
        int cnt = 0;
        for (int i = 0; i < marks.size(); i++)
        {
            for (int j = 0; j < marks.get(i).getMarks().size(); j++)
            {
                avg+=marks.get(i).getMarks().get(j);
                cnt++;
            }
        }

        if(marks.size() == 0)
            return 2;
        else
            return avg/cnt;
    }

    boolean have_this_subject(String subject)
    {
        for (int i = 0; i < marks.size(); i++)
        {
            if(marks.get(i).getName() == subject)
                return true;
        }
        return false;
    }
}

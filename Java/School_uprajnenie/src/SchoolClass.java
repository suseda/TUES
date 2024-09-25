import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.stream.Collectors;

public class SchoolClass
{
    private int number;
    private Vector<Student> students;
    private String name;

    School school;

    public SchoolClass(String name) {
        this.name = name;
        this.students = new Vector<>();

    }

    public int getNumber() {
        return number;
    }

    public String getName() {
        return name;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public void setStudents(Vector<Student> students) {
        this.students = students;
    }

    public void setName(String name) {
        this.name = name;
    }

    void addStudent(Student student)
    {
        students.add(student);
    }

    Vector<Student> getStudents()
    {
        Vector<Student> list_of_students = students;
        Collections.sort(list_of_students);
        return list_of_students;
    }

    void dump(OutputStreamWriter osw) throws IOException {
       try {
           osw.write(getName());
           osw.write(",");
           osw.write(getNumber());
           osw.write(",");
           osw.write(school.getName());
           osw.write(",");
           osw.write(students.size());

           for (int i = 0; i < students.size(); i ++)
           {
               osw.write('\n');
               students.get(i).dump(osw);
           }

       } catch (IOException e) {
           throw new RuntimeException(e);
       }
        //<име>, <уникален номер>, <име на училището>, <брой ученици>
        //<ученик 1>
        //<ученик 2>
    }


    Student findById(int id)
    {
        for (int i = 0; i < students.size();i++)
        {
            if(students.get(i).getID() == id)
                return students.get(i);
        }
        return null;
    }//, който намира и връща ученика с подадения уникален номер. Ако няма такъв ученик се връща NULL

    float getAverage(String subject)
    {
        float avg = 0;
        int cnt = 0;
        for (Student student : students) {
            avg += student.getAverage(subject);
            cnt++;
        }
        return avg/cnt;
    }//, който връща средната оценка от всички ученици по подадения предмет


    float getAverage()
    {
        float avg = 0;
        int cnt = 0;
        for (Student student : students) {
            avg += student.getAverage();
            cnt++;
        }
        return avg/cnt;
    }//, който връща средната оценка от всички ученици


    ArrayList<Student> getUnmarked(String subject)
    {
        ArrayList<Student> unmarked_students = new ArrayList<Student>();

        for (Student student : students) {
            if (student.have_this_subject(subject) == false)
                unmarked_students.add(student);
        }
        return unmarked_students;
    }//, който връща всички ученици, които нямат оценки по подадения предмет


    ArrayList<Student> getTopStudents()
    {
        /*Vector<Student> list_of_students = students;
        Collections.sort(list_of_students,Comparator.comparing(Student::getAverage));
        ArrayList<Student> top_five = new ArrayList<>();
        for (int i = 0; i < 5; i++)
            top_five.add(list_of_students.get(i));
        return top_five;*/
        Vector<Student> list_of_students = students;
        ArrayList<Student> top_five =  new ArrayList(list_of_students.stream()
                .sorted(Comparator.comparing(Student::getAverage))
                .limit(5)
                .collect(Collectors.toList()));
        return top_five;

    }//, който връща 5-те ученика с най-висока средна оценка, подредени по имена

    ArrayList<Student> getAceStudents()
    {
        //ArrayList<Student> ace_students = new ArrayList<>();
        Vector<Student> list_of_students = students;

        /*for (int i = 0; i < list_of_students.size(); i++)
        {
            if(list_of_students.get(i).getAverage() < 5)
                break;
            ace_students.add(list_of_students.get(i));
        }*/

        ArrayList<Student> ace_students = new ArrayList( list_of_students.stream()
                .sorted(Comparator.comparing(Student::getAverage))
                .filter(student -> student.getAverage() > 5F)
                .collect(Collectors.toList()));


        return ace_students;
    }//, който връща всички ученици със средна оценка над 5.00, подредени по средна оценка

}

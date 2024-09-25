import java.io.IOException;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class School
{
    private String name;
    private Vector<SchoolClass> classes;
    private Vector<String> subjects;

    public School(String name) {
        this.name = name;
        this.classes = new Vector<SchoolClass>();
        this.subjects = new Vector<String>();
    }

    public String getName() {
        return name;
    }

    public Vector<SchoolClass> getClasses() {
        return classes;
    }

    public Vector<String> getSubjects() {
        return subjects;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setClasses(Vector<SchoolClass> classes) {
        this.classes = classes;
    }

    public void setSubjects(Vector<String> subjects) {
        this.subjects = subjects;
    }

    void createClasses(String namePrefix, Vector<Person> students, int classLimit)
    {
        int class_number = students.size() / classLimit;

        for(int i = 0; i < class_number; i++)
        {
            char letter = (char)(65 + i);
            String class_name = namePrefix + "_" + letter;
            classes.add(new SchoolClass(class_name));
        }

        int which_class_to_add = 0;
        for (int j = 0; j < students.size(); j++)
        {
            if(which_class_to_add >= class_number)
                which_class_to_add = 0;

            classes.get(which_class_to_add).addStudent(new Student(students.get(j).getName(),students.get(j).getSurname(),students.get(j).getSex(),classes.get(which_class_to_add).getStudents().size(),classes.get(which_class_to_add),this));
        }
    }

    SchoolClass getClassByName(String name) throws Exception
    {
        for(int i = 0; i < classes.size();i++)
        {
            if(classes.get(i).getClass().getName() == name)
                return classes.get(i);
        }

        throw new Exception("This class doesnt exist.");
    }


    void dump(OutputStreamWriter osw)
    {
        try
        {
            osw.write(getName());
            osw.write(",");
            osw.write(subjects.size());
            osw.write(",");
            osw.write(classes.size());
            osw.write('\n');

            for (int i = 0; i < subjects.size(); i++)
            {
                osw.write(subjects.get(i));
                osw.write(",");
            }

            for (int j = 0; j < classes.size();j++)
            {
                osw.write('\n');
                classes.get(j).dump(osw);
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        //<име>, <брой предмети>, <брой класове>
        //<предмет 1>, ... <предмет N>
        //<клас 1>
        //<клас 2>
    }

    boolean allowsSubject(String subject)
    {
        for(int i = 0; i < subjects.size(); i++)
        {
            if(subjects.get(i) == subject)
                return true;
        }
        return false;
    }//, който връща true ако подаденото име се съдържа в списъка от предмети

    Student findStudentById(int id) throws Exception
    {
        for(int i = 0; i < classes.size();i++)
        {
            for (int j = 0; j < classes.get(i).getStudents().size(); j++)
            {
                if (classes.get(i).getStudents().get(j).getID() == id)
                    return classes.get(i).getStudents().get(j);
            }
        }

        throw new Exception("This student doesnt exist.");
    }//, който намира в цялото училище ученик с подадения уникален номер и го връща. Хвърля изключение ако такъв ученик не съществува

    ArrayList<Student> getUnmarked(String subject)
    {
        ArrayList<Student> unmarked_students = new ArrayList<Student>();
        for (int i = 0; i < classes.size(); i++)
        {
            unmarked_students.addAll(classes.get(i).getUnmarked(subject));
        }
        return unmarked_students;
    }//, който връща всички ученици, които нямат оценки по подадения предмет

    static Student findStudentById(ArrayList<SchoolClass> classes, int id) throws Exception
    {
        for (int i = 0; i < classes.size(); i++)
        {
            for (int j = 0; j < classes.get(i).getStudents().size(); j++)
            {
                if(classes.get(i).getStudents().get(j).getID() == id)
                    return classes.get(i).getStudents().get(j);
            }
        }
        throw new Exception("This student doesnt exist.");
    }

    static ArrayList<Student> getUnmarked(ArrayList<SchoolClass> classes, String subject)
    {
        ArrayList<Student> unmarked_students = new ArrayList<>();
        for (int i = 0; i < classes.size(); i++)
        {
            unmarked_students.addAll(classes.get(i).getUnmarked(subject));
        }
        return unmarked_students;
    }//, които работят аналогично на нестатичните си варианти, с разликата, че като аргумент приемат списък от класове, в които да търсят

    ArrayList<Student> getTopStudents(int count)
    {
        Vector<Student> list_of_students = new Vector<>();

        for(int j = 0; j < classes.size(); j++)
        {
            list_of_students.addAll(classes.get(j).getStudents());
        }

        /*Collections.sort(list_of_students,Comparator.comparing(Student::getAverage));
        ArrayList<Student> top_students = new ArrayList<>();
        for (int i = 0; i < count; i++)
            top_students.add(list_of_students.get(i));*/

        ArrayList<Student> top_students =  new ArrayList(list_of_students.stream()
                .sorted(Comparator.comparing(Student::getAverage))
                .limit(count)
                .collect(Collectors.toList()));

        return top_students;
    }//, който връща първите count на брой ученика с най-висока средна оценка, подредени по имена

    ArrayList<Student> getAceStudents()
    {
        //ArrayList<Student> ace_students = new ArrayList<>();
        Vector<Student> list_of_students = new Vector<>();

        for(int j = 0; j < classes.size(); j++)
        {
            list_of_students.addAll(classes.get(j).getStudents());
        }

        /*Collections.sort(list_of_students,Comparator.comparing(Student::getAverage));

        for (int i = 0; i < list_of_students.size(); i++)
        {
            if(list_of_students.get(i).getAverage() < 5)
                break;
            ace_students.add(list_of_students.get(i));
        }*/

        ArrayList<Student> ace_students = new ArrayList( list_of_students.stream()
                .sorted(Comparator.comparing(Student::getAverage))
                .filter(student -> student.getAverage() > 5)
                .collect(Collectors.toList()));

        return ace_students;
    }//, който връща всички ученици със средна оценка над 5.00, подредени по средна оценка
}

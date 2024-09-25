import org.junit.jupiter.api.Test;
import java.sql.Array;
import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

class SchoolClassTest {



    @Test
    void getStudents() {
    }


    @Test
    void findById() {
        ArrayList<Student> students = new ArrayList<>();
        School school = new School("TUES");
        SchoolClass schoolclass = new SchoolClass("11V");
        students.add( new Student("Kaloyan","Sotirov",'M',14,schoolclass,school));
        students.add( new Student("Dimitar","Dimitrov",'M',6,schoolclass,school));
        students.add( new Student("Ivayla","Baruh",'F',10,schoolclass,school));

        assertEquals(4,students.get(0).getID());
    }

    @Test
    void getAverage()
    {
        ArrayList<Student> students = new ArrayList<>();
        School school = new School("TUES");
        SchoolClass schoolclass = new SchoolClass("11V");
        Student s1 = new Student("Kaloyan","Sotirov",'M',14,schoolclass,school);
        Student s2 = new Student("Dimitar","Dimitrov",'M',6,schoolclass,school);
        Student s3 =  new Student("Ivayla","Baruh",'F',10,schoolclass,school);
        students.add(s1);
        students.add(s2);
        students.add(s3);
        schoolclass.addStudent(s1);
        schoolclass.addStudent(s2);
        schoolclass.addStudent(s3);
        Subject subject = new Subject("Math");
        students.get(0).getMarks().add(subject);
        students.get(1).getMarks().add(subject);
        students.get(2).getMarks().add(subject);
        List<Float> l = new ArrayList<>();
        l.add(Float.valueOf(5));
        l.add(Float.valueOf(6));

        for (int i = 0; i < students.size(); i++)
        {
            students.get(i).getMarks("Math").addAll(l);
        }

        assertEquals(5.5,schoolclass.getAverage("Math"));

    }

    @Test
    void testGetAverage()
    {
        ArrayList<Student> students = new ArrayList<>();
        School school = new School("TUES");
        SchoolClass schoolclass = new SchoolClass("11V");
        Student s1 = new Student("Kaloyan","Sotirov",'M',14,schoolclass,school);
        Student s2 = new Student("Dimitar","Dimitrov",'M',6,schoolclass,school);
        Student s3 =  new Student("Ivayla","Baruh",'F',10,schoolclass,school);
        students.add(s1);
        students.add(s2);
        students.add(s3);
        schoolclass.addStudent(s1);
        schoolclass.addStudent(s2);
        schoolclass.addStudent(s3);
        Subject subject = new Subject("Math");
        students.get(0).getMarks().add(subject);
        students.get(1).getMarks().add(subject);
        students.get(2).getMarks().add(subject);
        List<Float> l = new ArrayList<>();
        l.add(Float.valueOf(5));
        l.add(Float.valueOf(6));

        for (int i = 0; i < students.size(); i++)
        {
            students.get(i).getMarks("Math").addAll(l);
        }

        assertEquals(5.5,schoolclass.getAverage());
    }

    @Test
    void getUnmarked()
    {
        ArrayList<Student> students = new ArrayList<>();
        School school = new School("TUES");
        SchoolClass schoolclass = new SchoolClass("11V");
        Student s1 = new Student("Kaloyan","Sotirov",'M',14,schoolclass,school);
        Student s2 = new Student("Dimitar","Dimitrov",'M',6,schoolclass,school);
        Student s3 =  new Student("Ivayla","Baruh",'F',10,schoolclass,school);
        students.add(s1);
        students.add(s2);
        students.add(s3);
        schoolclass.addStudent(s1);
        schoolclass.addStudent(s2);
        schoolclass.addStudent(s3);
        Subject subject = new Subject("Math");
        students.get(0).getMarks().add(subject);
        students.get(1).getMarks().add(subject);

        List<Float> l = new ArrayList<>();
        l.add(Float.valueOf(5));
        l.add(Float.valueOf(6));

        for (int i = 0; i < students.size(); i++)
        {
            students.get(i).getMarks("Math").addAll(l);
        }

        ArrayList<Student> unmarked = new ArrayList<>();
        unmarked.add(s2);

        assertTrue(unmarked.contains(s2));

    }

    @Test
    void getTopStudents()
    {
        ArrayList<Student> students = new ArrayList<>();
        School school = new School("TUES");
        SchoolClass schoolclass = new SchoolClass("11V");
        Student s1 = new Student("Kaloyan","Sotirov",'M',14,schoolclass,school);
        Student s2 = new Student("Dimitar","Dimitrov",'M',6,schoolclass,school);
        Student s3 =  new Student("Ivayla","Baruh",'F',10,schoolclass,school);
        students.add(s1);
        students.add(s2);
        students.add(s3);
        schoolclass.addStudent(s1);
        schoolclass.addStudent(s2);
        schoolclass.addStudent(s3);
        Subject subject = new Subject("Math");
        students.get(0).getMarks().add(subject);
        students.get(1).getMarks().add(subject);
        students.get(2).getMarks().add(subject);

        students.get(0).getMarks("Math").add(Float.valueOf(3));
        students.get(1).getMarks("Math").add(Float.valueOf(4));
        students.get(2).getMarks("Math").add(Float.valueOf(6));

        ArrayList<Student> top_five = schoolclass.getTopStudents();

        assertTrue(top_five.contains(s1));
        assertTrue(top_five.contains(s2));
        assertTrue(top_five.contains(s3));


    }

    @Test
    void getAceStudents()
    {
        ArrayList<Student> students = new ArrayList<>();
        School school = new School("TUES");
        SchoolClass schoolclass = new SchoolClass("11V");
        Student s1 = new Student("Kaloyan","Sotirov",'M',14,schoolclass,school);
        Student s2 = new Student("Dimitar","Dimitrov",'M',6,schoolclass,school);
        Student s3 =  new Student("Ivayla","Baruh",'F',10,schoolclass,school);
        students.add(s1);
        students.add(s2);
        students.add(s3);
        schoolclass.addStudent(s1);
        schoolclass.addStudent(s2);
        schoolclass.addStudent(s3);
        Subject subject = new Subject("Math");
        students.get(0).getMarks().add(subject);
        students.get(1).getMarks().add(subject);
        students.get(2).getMarks().add(subject);

        students.get(0).getMarks("Math").add(Float.valueOf(3));
        students.get(1).getMarks("Math").add(Float.valueOf(4));
        students.get(2).getMarks("Math").add(Float.valueOf(6));

        ArrayList<Student> ace_students = schoolclass.getAceStudents();

        assertFalse(ace_students.contains(s1));
        assertFalse(ace_students.contains(s2));
        assertTrue(ace_students.contains(s3));
    }
}
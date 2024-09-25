import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class Subject
{
    private String name;
    private List<Float> marks;

    public Subject(String name) {
        this.name = name;
        this.marks = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public List<Float> getMarks() {
        return marks;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setMarks(List<Float> marks) {
        this.marks = marks;
    }

}




import java.io.PrintStream;

public class Student {
    private String name;
    private int age;
    private String course;

    public Student(String name, int age, String course) {
        this.name = name;
        this.age = age;
        this.course = course;
    }

    public void displayStudentDetails(PrintStream printStream) {
        printStream.println("Student Name: " + name);
        printStream.println("Age: " + age);
        printStream.println("Course: " + course);
    }

    public static void main(String[] args) {
        Student student = new Student("Sahil", 46, "Computer Engg");
        PrintStream console = System.out;
        student.displayStudentDetails(console);
    }
}

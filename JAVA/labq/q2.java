import java.io.*;
import java.util.*;

class Student {
    private String name;
    private int semesterHours;
    private double totalQualityPoints;

    public Student(String name, int semesterHours, double totalQualityPoints) {
        this.name = name;
        this.semesterHours = semesterHours;
        this.totalQualityPoints = totalQualityPoints;
    }

    public String toString() {
        return name + " " + semesterHours + " " + totalQualityPoints;
    }

    double calculateGPA() {
        return totalQualityPoints / semesterHours;
    }

    boolean isWarning() {
        return (calculateGPA() < 1.5 && semesterHours < 30) || (calculateGPA() < 1.75 && semesterHours < 60) || (calculateGPA() < 2.0);
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter the number of students: ");
            int numStudents = scanner.nextInt();

            Student students[] = new Student[numStudents];
            FileWriter writer = new FileWriter("students.txt");

            // Populate the array of students with user input and write to the file
            for (int i = 0; i < numStudents; i++) {
                System.out.println("Enter details for Student " + (i + 1));
                System.out.print("Name: ");
                String name = scanner.next();
                System.out.print("Semester Hours Earned: ");
                int semesterHours = scanner.nextInt();
                System.out.print("Total Quality Points Earned: ");
                double totalQualityPoints = scanner.nextDouble();

                students[i] = new Student(name, semesterHours, totalQualityPoints);
                writer.write(students[i].toString() + "\n");
            }

            writer.close(); // Close the FileWriter

            // Read from the file and display
            FileReader f = new FileReader("students.txt");
            BufferedReader br = new BufferedReader(f);
            String s;
            System.out.println("Student Information:");
            while ((s = br.readLine()) != null) {
                System.out.println(s);
            }

            // Display warnings
            FileWriter f3=new FileWriter("new.txt");
            System.out.println("\nAcademic Warnings:");
            for (int i = 0; i < numStudents; i++) {
                if (students[i].isWarning()) {
                    f3.write(students[i].toString());
                }
            }
            f3.close();
            f.close();
            scanner.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

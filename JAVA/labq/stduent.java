import java.io.*;
import java.util.*;
public class Main {
    public static void main(String args[]) throws IOException {
        int i = 0;
        String str1, str2, str3, str4, arr[] = new String[4];
        
        
        FileWriter wr = new FileWriter("test.txt");
        str1 = "Smith 27 83.7";
        str2 = "Jones 21 28.35";
        str3 = "Walker 96 182.4";
        str4 = "Doe 60 150";
        
        FileWriter w = new FileWriter("text.txt");
        w.write(str1 + "\n");
        w.write(str2 + "\n");
        w.write(str3 + "\n");
        w.write(str4 + "\n");
        w.close();
    FileReader r = new FileReader("text.txt");
        Scanner scanner = new Scanner(r);

        while (scanner.hasNext()) {
            String name = scanner.next();
            int semhrs = scanner.nextInt();
            double quality = scanner.nextDouble();
            double gpa = quality / semhrs;
            if ((gpa < 1.5 && semhrs < 30) || (gpa < 1.75 && semhrs < 60) || (gpa < 2)) {
                arr[i] = name;
                i++;
            }
        }

        for (int j = 0; j < i; j++) {
            wr.write(arr[j] + "\t");
        }

        wr.close();

        // Use a new FileReader to print the content of the file
        FileReader printReader = new FileReader("test.txt");
        int c;
        while ((c = printReader.read()) != -1) {
            System.out.print((char) c);
        }

        printReader.close();
    }
}
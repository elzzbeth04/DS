import java.io.*;
import java.util.*;

class Main {

    public static boolean palindrome(int num) {
        int n = num;
        int r;
        int sum = 0;
        while (n != 0) {
            r = n % 10;
            sum = (sum * 10) + r;
            n = n / 10;
        }
        return num == sum;
    }

    public static void writeTo(int num) throws IOException {
        FileWriter r = new FileWriter("Pali.txt", true); // true for append mode
        r.write(Integer.toString(num) + "\n"); // Write the number followed by a newline
        r.close();
    }

    public static void main(String args[]) {
        int num;
        Scanner sc = new Scanner(System.in);
        System.out.println("Input:");
        String s = sc.nextLine();
        StringTokenizer st = new StringTokenizer(s);
        try {
            while (st.hasMoreTokens()) {
                num = Integer.parseInt(st.nextToken());
                if (palindrome(num))
                    writeTo(num); // Write the palindrome number to the file
            }
        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file: " + e.getMessage());
            e.printStackTrace();
        }
    }
}

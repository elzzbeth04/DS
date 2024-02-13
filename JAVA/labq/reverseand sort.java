import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Check if a file name is provided as a command line argument
        if (args.length != 1) {
            System.out.println("Usage: java SortWords <filename>");
            return;
        }

        String fileName = args[0];

        try {
            // Read a line of words using StringTokenizer
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter a line of words:");
            String inputLine = reader.readLine();

            // Tokenize the input line
            StringTokenizer tokenizer = new StringTokenizer(inputLine);

            // Sort words directly without using TreeSet
            String[] words = new String[tokenizer.countTokens()];
            int i = 0;
            while (tokenizer.hasMoreTokens()) {
                words[i] = tokenizer.nextToken();
                i++;
            }

            // Sort the array of words using bubble sort (you can use other sorting algorithms)
            sortWords(words);

            // Write sorted words to the file
            FileWriter fileWriter = new FileWriter(fileName);
            for (String word : words) {
                fileWriter.write(word + "\n");
            }

            fileWriter.close();

            // Print the number of words in the file
            int wordCount = 0;
            FileReader fr=new FileReader(fileName);
            BufferedReader fileReader = new BufferedReader(fr);
            String line;

            while ((line = fileReader.readLine()) != null) {
                StringTokenizer lineTokenizer = new StringTokenizer(line);
                wordCount += lineTokenizer.countTokens();
            }

            fileReader.close();

            System.out.println("Number of words in " + fileName + " file: " + i);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void sortWords(String[] words) {
        // Sort the array of words using bubble sort (you can use other sorting algorithms)
        int n = words.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (words[j].compareTo(words[j + 1]) > 0) {
                    // Swap words[j] and words[j + 1]
                    String temp = words[j];
                    words[j] = words[j + 1];
                    words[j + 1] = temp;
                }
            }
        }
    }
}

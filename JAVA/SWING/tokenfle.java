import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.StringTokenizer;

public class SaveDataToFile extends JFrame implements ActionListener {
    private JTextField textField;
    private JButton saveButton;

    public SaveDataToFile() {
        setTitle("Save Data to File");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        textField = new JTextField(20);
        add(textField);

        saveButton = new JButton("Save");
        saveButton.addActionListener(this);
        add(saveButton);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == saveButton) {
            String data = textField.getText();
            writeToFile(data);
            displayFileDetails("inputdata.txt");
        }
    }

    private void writeToFile(String data) {
        try {
            FileWriter writer = new FileWriter("inputdata.txt");
            writer.write(data);
            writer.close();
            System.out.println("Data written to file successfully.");
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    private void displayFileDetails(String filename) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line;
            int wordCount = 0;
            while ((line = reader.readLine()) != null) {
                StringTokenizer tokenizer = new StringTokenizer(line);
                wordCount += tokenizer.countTokens();
            }
            reader.close();
            System.out.println("Number of words in the file: " + wordCount);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SaveDataToFile::new);
    }
}

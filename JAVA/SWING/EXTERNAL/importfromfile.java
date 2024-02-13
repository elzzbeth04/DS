import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class StudentMarksGUI extends JFrame implements ActionListener {
    private JTextField rollNoField;
    private JTextField nameField;
    private JTextField mark1Field;
    private JTextField mark2Field;
    private JTextField mark3Field;
    private JButton importButton;
    private JButton calculateButton;
    private JTextField totalMarksField;

    public StudentMarksGUI() {
        setTitle("Student Marks");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(7, 2));

        JLabel rollNoLabel = new JLabel("Roll No:");
        add(rollNoLabel);
        rollNoField = new JTextField(20);
        add(rollNoField);

        JLabel nameLabel = new JLabel("Name:");
        add(nameLabel);
        nameField = new JTextField(20);
        add(nameField);

        JLabel mark1Label = new JLabel("Mark 1:");
        add(mark1Label);
        mark1Field = new JTextField(20);
        add(mark1Field);

        JLabel mark2Label = new JLabel("Mark 2:");
        add(mark2Label);
        mark2Field = new JTextField(20);
        add(mark2Field);

        JLabel mark3Label = new JLabel("Mark 3:");
        add(mark3Label);
        mark3Field = new JTextField(20);
        add(mark3Field);

        importButton = new JButton("Import data");
        importButton.addActionListener(this);
        add(importButton);

        calculateButton = new JButton("Calculate");
        calculateButton.addActionListener(this);
        add(calculateButton);

        totalMarksField = new JTextField(20);
        totalMarksField.setEditable(false);
        add(totalMarksField);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == importButton) {
            importDataFromFile();
        } else if (e.getSource() == calculateButton) {
            calculateTotalMarks();
        }
    }

    private void importDataFromFile() {
        try {
            FileReader  fr =new FileReader("student_details.txt");
            BufferedReader reader = new BufferedReader(fr);
            rollNoField.setText(reader.readLine());
            nameField.setText(reader.readLine());
            mark1Field.setText(reader.readLine());
            mark2Field.setText(reader.readLine());
            mark3Field.setText(reader.readLine());
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error importing data from file", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void calculateTotalMarks() {
        try {
            String mark1Text = mark1Field.getText().trim();
            String mark2Text = mark2Field.getText().trim();
            String mark3Text = mark3Field.getText().trim();
    
            if (mark1Text.isEmpty() || mark2Text.isEmpty() || mark3Text.isEmpty()) {
                JOptionPane.showMessageDialog(this, "Please enter all marks", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
    
            int mark1 = Integer.parseInt(mark1Text);
            int mark2 = Integer.parseInt(mark2Text);
            int mark3 = Integer.parseInt(mark3Text);
    
            int totalMarks = mark1 + mark2 + mark3;
            totalMarksField.setText(String.valueOf(totalMarks));
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid marks entered", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(StudentMarksGUI::new);
    }
}
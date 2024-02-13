import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class EmployeeDetailsGUI extends JFrame implements ActionListener {
    private JTextField empIDField;
    private JTextField nameField;
    private JTextField basicPayField;
    private JTextField daField;
    private JTextField hraField;
    private JButton saveButton;
    private JButton totalButton;
    private JTextField totalSalaryField;

    public EmployeeDetailsGUI() {
        setTitle("Employee Details");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(7, 2));

        JLabel empIDLabel = new JLabel("EmpID:");
        add(empIDLabel);
        empIDField = new JTextField(20);
        add(empIDField);

        JLabel nameLabel = new JLabel("Name:");
        add(nameLabel);
        nameField = new JTextField(20);
        add(nameField);

        JLabel basicPayLabel = new JLabel("Basic Pay:");
        add(basicPayLabel);
        basicPayField = new JTextField(20);
        add(basicPayField);

        JLabel daLabel = new JLabel("DA:");
        add(daLabel);
        daField = new JTextField(20);
        add(daField);

        JLabel hraLabel = new JLabel("HRA:");
        add(hraLabel);
        hraField = new JTextField(20);
        add(hraField);

        saveButton = new JButton("Save");
        saveButton.addActionListener(this);
        add(saveButton);

        totalButton = new JButton("Total");
        totalButton.addActionListener(this);
        add(totalButton);

        totalSalaryField = new JTextField(20);
        totalSalaryField.setEditable(false);
        add(totalSalaryField);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == saveButton) {
            String empID = empIDField.getText();
            String name = nameField.getText();
            String basicPayText = basicPayField.getText();
            String daText = daField.getText();
            String hraText = hraField.getText();

            try {
                double basicPay = Double.parseDouble(basicPayText);
                double da = Double.parseDouble(daText);
                double hra = Double.parseDouble(hraText);

                writeToFile(empID, name, basicPay, da, hra);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Invalid input entered", "Error", JOptionPane.ERROR_MESSAGE);
            }
        } else if (e.getSource() == totalButton) {
            try {
                double basicPay = Double.parseDouble(basicPayField.getText());
                double da = Double.parseDouble(daField.getText());
                double hra = Double.parseDouble(hraField.getText());

                double totalSalary = basicPay + da + hra;
                totalSalaryField.setText(String.valueOf(totalSalary));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Invalid input entered", "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void writeToFile(String empID, String name, double basicPay, double da, double hra) {
        try {
            FileWriter writer = new FileWriter("employee_details.txt", true);
            BufferedWriter bufferedWriter = new BufferedWriter(writer);
            bufferedWriter.write(empID + " " + name + " " + basicPay + " " + da + " " + hra + "\n");
            bufferedWriter.close();
            JOptionPane.showMessageDialog(this, "Employee details saved successfully", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error saving employee details", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(EmployeeDetailsGUI::new);
    }
}

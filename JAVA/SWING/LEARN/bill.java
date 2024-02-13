import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class ElectricityBillGenerator extends JFrame implements ActionListener {
    private JTextField unitsField;
    private JLabel unitsLabel, amountLabel;
    private JButton calculateButton;

    public ElectricityBillGenerator() {
        setTitle("Electricity Bill Generator");
        setSize(300, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(3, 2));

        unitsLabel = new JLabel("Units Consumed:");
        unitsField = new JTextField(10);
        amountLabel = new JLabel("Amount Charged:");
        calculateButton = new JButton("Calculate");

        add(unitsLabel);
        add(unitsField);
        add(amountLabel);
        add(new JLabel()); // Placeholder for amount display
        add(new JLabel()); // Placeholder for alignment
        add(calculateButton);

        calculateButton.addActionListener(this);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        try {
            double units = Double.parseDouble(unitsField.getText());
            double amountCharged = calculateAmountCharged(units);
            amountLabel.setText("Amount Charged: $" + String.format("%.2f", amountCharged));

            // Write details to a file
            writeToFile(units, amountCharged);
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter a valid number for units consumed.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private double calculateAmountCharged(double units) {
        // Assuming a simple tariff of $0.10 per unit
        return units * 0.10;
    }

    private void writeToFile(double units, double amountCharged) {
        try (FileWriter writer = new FileWriter("ElectricityBill.txt")) {
            writer.write("Electricity Bill\n");
            writer.write("Units Consumed: " + units + "\n");
            writer.write("Amount Charged: $" + String.format("%.2f", amountCharged) + "\n");
            writer.write("Thank you for using our service!\n");
            writer.flush();
            JOptionPane.showMessageDialog(this, "Electricity bill generated successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Failed to write bill details to file.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new ElectricityBillGenerator();
            }
        });
    }
}
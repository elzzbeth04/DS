import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class BankTransactionGUI extends JFrame implements ActionListener {
    private JTextField accountNumberField;
    private JTextField accountHolderNameField;
    private JTextField amountField;
    private JButton withdrawButton;

    public BankTransactionGUI() {
        setTitle("Bank Transaction");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(4, 2));

        JLabel accountNumberLabel = new JLabel("Account Number:");
        add(accountNumberLabel);
        accountNumberField = new JTextField(20);
        add(accountNumberField);

        JLabel accountHolderNameLabel = new JLabel("Account Holder Name:");
        add(accountHolderNameLabel);
        accountHolderNameField = new JTextField(20);
        add(accountHolderNameField);

        JLabel amountLabel = new JLabel("Amount to Withdraw:");
        add(amountLabel);
        amountField = new JTextField(20);
        add(amountField);

        withdrawButton = new JButton("Withdraw");
        withdrawButton.addActionListener(this);
        add(withdrawButton);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == withdrawButton) {
            String accountNumber = accountNumberField.getText();
            String accountHolderName = accountHolderNameField.getText();
            String amountText = amountField.getText();

            try {
                double amount = Double.parseDouble(amountText);

                String result;
                if (amount > 25000) {
                    result = "The limit exceeded";
                } else {
                    result = "The transaction success";
                }

                writeToFile(accountNumber, accountHolderName, amount, result);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Invalid amount entered", "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void writeToFile(String accountNumber, String accountHolderName, double amount, String result) {
        try {
            FileWriter writer = new FileWriter("bankdetails.txt", true); // Append mode
            BufferedWriter bufferedWriter = new BufferedWriter(writer);
            bufferedWriter.write("Account Number: " + accountNumber + "\n");
            bufferedWriter.write("Account Holder Name: " + accountHolderName + "\n");
            bufferedWriter.write("Amount Withdrawn: " + amount + "\n");
            bufferedWriter.write("Result: " + result + "\n\n");
            bufferedWriter.close();
            JOptionPane.showMessageDialog(this, "Transaction details saved successfully", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error saving transaction details", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(BankTransactionGUI::new);
    }
}

import javax.swing.*;
import java.awt.event.*;

public class SwingDivision extends JFrame implements ActionListener {
    JTextField num1, num2, resultField, remarksField;
    JButton divideButton;

    public SwingDivision() {
        setTitle("Division Calculator");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);

        JLabel num1Label = new JLabel("Number 1:");
        num1Label.setBounds(20, 20, 80, 25);
        add(num1Label);

        num1 = new JTextField(10);
        num1.setBounds(100, 20, 160, 25);
        add(num1);

        JLabel num2Label = new JLabel("Number 2:");
        num2Label.setBounds(20, 50, 80, 25);
        add(num2Label);

        num2 = new JTextField(10);
        num2.setBounds(100, 50, 160, 25);
        add(num2);

        divideButton = new JButton("Divide");
        divideButton.setBounds(100, 80, 80, 25);
        add(divideButton);
        divideButton.addActionListener(this);

        JLabel resultLabel = new JLabel("Result:");
        resultLabel.setBounds(20, 110, 80, 25);
        add(resultLabel);

        resultField = new JTextField(10);
        resultField.setBounds(100, 110, 160, 25);
        resultField.setEditable(false);
        add(resultField);

        JLabel remarksLabel = new JLabel("Remarks:");
        remarksLabel.setBounds(20, 140, 80, 25);
        add(remarksLabel);

        remarksField = new JTextField(10);
        remarksField.setBounds(100, 140, 160, 25);
        remarksField.setEditable(false);
        add(remarksField);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        try {
            int number1 = Integer.parseInt(num1.getText());
            int number2 = Integer.parseInt(num2.getText());

            if (number2 == 0) {
                throw new ArithmeticException("Cannot divide by zero!");
            }

            int result = number1 / number2;
            resultField.setText(String.valueOf(result));
            remarksField.setText("");
        } catch (NumberFormatException ex) {
            remarksField.setText("NumberFormatException: Please enter integers only");
        } catch (ArithmeticException ex) {
            remarksField.setText("ArithmeticException: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SwingDivision::new);
    }
}

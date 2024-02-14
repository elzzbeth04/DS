import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

abstract class Compartment {
    abstract void notice();
}

class FirstClass extends Compartment {
    private int firstClassTicketCount;

    public FirstClass(int firstClassTicketCount) {
        this.firstClassTicketCount = firstClassTicketCount;
    }

    public void bookTicket() {
        if (firstClassTicketCount > 0) {
            firstClassTicketCount--;
            System.out.println("First class ticket booked successfully.");
        } else {
            System.out.println("No more first class tickets available.");
        }
    }

    public int getFirstClassTicketCount() {
        return firstClassTicketCount;
    }

    void notice() {
        System.out.println("First class: " + firstClassTicketCount + " seats available.");
    }
}

class General extends Compartment {
    private int generalTicketCount;

    public General(int generalTicketCount) {
        this.generalTicketCount = generalTicketCount;
    }

    public void bookTicket() {
        if (generalTicketCount > 0) {
            generalTicketCount--;
            System.out.println("General class ticket booked successfully.");
        } else {
            System.out.println("No more general class tickets available.");
        }
    }

    public int getGeneralTicketCount() {
        return generalTicketCount;
    }

    void notice() {
        System.out.println("General class: " + generalTicketCount + " seats available.");
    }
}

public class RailwayCompartmentGUI extends JFrame implements ActionListener {
    private FirstClass firstClassCompartment;
    private General generalCompartment;
    private JTextField nameField;
    private JTextField ageField;
    private JButton bookFirstClassButton;
    private JButton bookGeneralButton;
    private JLabel firstClassLabel;
    private JLabel generalLabel;

    public RailwayCompartmentGUI() {
        setTitle("Railway Compartment Booking");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2));

        firstClassCompartment = new FirstClass(10); // Initial count of first class tickets
        generalCompartment = new General(50); // Initial count of general class tickets

        JLabel nameLabel = new JLabel("Name:");
        add(nameLabel);
        nameField = new JTextField(20);
        add(nameField);

        JLabel ageLabel = new JLabel("Age:");
        add(ageLabel);
        ageField = new JTextField(20);
        add(ageField);

        bookFirstClassButton = new JButton("Book First Class Ticket");
        bookFirstClassButton.addActionListener(this);
        add(bookFirstClassButton);

        bookGeneralButton = new JButton("Book General Ticket");
        bookGeneralButton.addActionListener(this);
        add(bookGeneralButton);

        firstClassLabel = new JLabel("First class: " + firstClassCompartment.getFirstClassTicketCount() + " seats available.");
        add(firstClassLabel);

        generalLabel = new JLabel("General class: " + generalCompartment.getGeneralTicketCount() + " seats available.");
        add(generalLabel);

        pack();
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == bookFirstClassButton) {
            firstClassCompartment.bookTicket();
            firstClassLabel.setText("First class: " + firstClassCompartment.getFirstClassTicketCount() + " seats available.");
        } else if (e.getSource() == bookGeneralButton) {
            generalCompartment.bookTicket();
            generalLabel.setText("General class: " + generalCompartment.getGeneralTicketCount() + " seats available.");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(RailwayCompartmentGUI::new);
    }
}

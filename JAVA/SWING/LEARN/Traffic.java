import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Traffic extends JFrame implements ActionListener {
    String msg = "";
    JLabel jl;
    JTextField t;
    JRadioButton r1, r2, r3;
    JTextArea j;
    ButtonGroup bg;
    Container c;

    Traffic() {
        setLayout(new FlowLayout());
        t = new JTextField(10);
        c = getContentPane();
        jl = new JLabel("Traffic Light");
        r1 = new JRadioButton("RED");
        r2 = new JRadioButton("YELLOW");
        r3 = new JRadioButton("GREEN");
        bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        bg.add(r3);
        c.add(jl);
        c.add(t);
        c.add(r1);
        c.add(r2);
        c.add(r3);
        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);
        setSize(400, 500);
        setVisible(true);
        c.setBackground(Color.pink);
    }

    public void actionPerformed(ActionEvent ae) {
        msg = ae.getActionCommand();
        if (msg.equals("RED")) {
            c.setBackground(Color.RED);
            t.setText(msg + " TURN ON");
        } else if (msg.equals("GREEN")) {
            c.setBackground(Color.GREEN);
            t.setText(msg + " TURN ON");
        } else if (msg.equals("YELLOW")) {
            c.setBackground(Color.YELLOW);
            t.setText(msg + " TURN ON");
        }
    }

    public static void main(String args[]) {
        Traffic f = new Traffic();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

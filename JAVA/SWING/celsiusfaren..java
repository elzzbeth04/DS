import java.awt.event.*;
import javax.swing.*;
import java.awt.*;
class temp extends JFrame implements ActionListener
{
JTextField t1,t2;
JLabel l1,l2;
JButton b;
temp()
{
setTitle("TEMP");
setSize(500,600);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new FlowLayout());
        l1=new JLabel("CELSIUS");
        t1=new JTextField(10);
         l2=new JLabel("FAREN");
        t2=new JTextField(10);
        b= new JButton("CONVERT");
        add(l1);
        add(t1);
    add(l2); 
    add(t2);
    add(b);
b.addActionListener(this);
setVisible(true);
}
public void actionPerformed(ActionEvent ae)
{
String s=t1.getText();
int num=Integer.parseInt(s);
float f=((num*9)/5)+32;
t2.setText(Float.toString(f));
}
public static void main(String[] args) {
new temp();

}
}
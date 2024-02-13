import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Global {
    public static Integer n;
}

class City extends JFrame implements ActionListener {
    JTextField j;
    JButton p;

    City() {
        j = new JTextField(10);
        p = new JButton("PRINT");
        add(j);
        add(p);
        setSize(300, 100);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        p.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae) {
        String s = j.getText();
        Global.n = Integer.parseInt(s);
        ThreadA a = new ThreadA();
        ThreadB b = new ThreadB();
        a.start();
        b.start();
    }
}

class ThreadA extends Thread {
    public void run() {
        try {
            synchronized (Global.n) {
                for (int i = 0; i < Global.n; i++) {
                    System.out.println("Thrikkakara");
                    Thread.sleep(1000);
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class ThreadB extends Thread {
    public void run() {
        try {
            synchronized (Global.n) {
                for (int i = 0; i < Global.n; i++) {
                    System.out.println("Kochi");
                    Thread.sleep(1000);
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) {
      {
        //SwingUtilities.invokeLater(new Runnable() 
          
                new City();
            
        
    }
}
}

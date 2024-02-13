class EvenNumberGenerator extends Thread {
    public void run() {
        synchronized (Main.class) {
            for (int i = 2; i <= 100; i += 2) {
                System.out.println("Even: " + i);
                try {
                    Thread.sleep(100); // Sleep for a short duration to simulate processing
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

class OddNumberGenerator extends Thread {
    public void run() {
        synchronized (Main.class) {
            for (int i = 1; i <= 100; i += 2) {
                System.out.println("Odd: " + i);
                try {
                    Thread.sleep(100); // Sleep for a short duration to simulate processing
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        EvenNumberGenerator evenThread = new EvenNumberGenerator();
        OddNumberGenerator oddThread = new OddNumberGenerator();

        evenThread.start();
        oddThread.start();
    }
}
\
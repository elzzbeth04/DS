import java.util.Random;
class RandomNumberThread extends Thread {
public void run() {
Random random = new Random();
for (int i = 0; i < 10; i++) {
int randomInteger = random.nextInt(100);
System.out.println("Random Integer generated : " + randomInteger);
if((randomInteger%2) == 0) {
EvenThread sThread = new EvenThread(randomInteger);
sThread.start();
}
else {
OddThread cThread = new OddThread(randomInteger);
cThread.start();
}
try {
Thread.sleep(1000);
}
catch (InterruptedException ex) {
System.out.println(ex);
}
}
}
}
class EvenThread extends Thread {
int number;
EvenThread(int randomNumbern) {
number = randomNumbern;
}
public void run() {
for(int i=2;i<number;i=i+2)
System.out.println(i+" ");
}

}
class OddThread extends Thread {
int number;
OddThread(int randomNumber) {
number = randomNumber;
}
public void run() {
for(int i=1;i<number;i=i+2)
System.out.println(i+" ");
}
}
public class Main {
public static void main(String args[]) {
RandomNumberThread rnThread = new RandomNumberThread();
rnThread.start();
}
}
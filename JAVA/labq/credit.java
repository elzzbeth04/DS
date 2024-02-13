import java.io.*;
import java.util.*;
interface employee{
    void calcsal(int sal);
}
class junior implements employee{
    Scanner sc = new Scanner(System.in);
    public void calcsal(int sal){
        System.out.println("Salary: "+(30*sal));
    }
    void credit(int c) throws IOException{
        try{
            System.out.println("Enter the amount to be withdrawn:");
            int with = sc.nextInt();
            if(with>c){
                throw new IOException("withdraw is not possible");
            }
            else{
                System.out.println("withdraw is possible");
            }
        }catch(IOException e){
             System.out.println(e);
        }
    }
}
class senior implements employee{
    Scanner sc = new Scanner(System.in);
    public void calcsal(int sal){
        System.out.println("Salary: "+(31*sal));
    }
    void credit(int c) throws IOException{
        try{
            System.out.println("Enter the amount to be withdrawn:");
            int with = sc.nextInt();
            if(with>c){
                throw new IOException("withdraw is not possible");
            }
            else{
                System.out.println("withdraw is possible");
            }
        }catch(IOException e){
             System.out.println(e);
        }
    }
}
class main{
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the salary of senior:");
        int sal = sc.nextInt();
        System.out.println("Enter the credit limit of senior:");
        int c1 = sc.nextInt();
        System.out.println("Enter the salary of junior:");
        int sal2 = sc.nextInt();
        System.out.println("Enter the credit limit of junior:");
        int c2 = sc.nextInt();
        junior j = new junior();
        senior s = new senior();
        s.calcsal(sal);
        s.credit(c1);
        j.calcsal(sal2);
        j.credit(c2);
        
    }
}
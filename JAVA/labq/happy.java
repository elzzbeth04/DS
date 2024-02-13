class InternetUsers {
    static int count = 0;
    static int happyCustomers;
    final static int MAXTIME = 2; // in hours
    String loginName;

    static {
        System.out.println("Let's start browsing!");
        System.out.println("Maximum allotted time for browsing: " + MAXTIME + " hours");
        happyCustomers = count;
    }

    InternetUsers(String loginName) {
        this.loginName = loginName;
        count++;
    }

    static void show() {
        System.out.println("Number of Internet Users: " + count);
        System.out.println("Number of Happy Customers: " + happyCustomers);
    }

    void compute() {
        if (Math.random() > 0.5) { // Assume 50% probability for a happy customer
            happyCustomers++;
            System.out.println(loginName + " is a happy customer!");
        }
    }
}

public class CollegeInternet {
    public static void main(String[] args) {
        InternetUsers user1 = new InternetUsers("Alice");
        InternetUsers user2 = new InternetUsers("Bob");
        InternetUsers user3 = new InternetUsers("Charlie");

        InternetUsers.show();

        user1.compute();
        user2.compute();
        user3.compute();

        InternetUsers.show();
    }
}

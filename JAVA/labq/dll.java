import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
    }
}

class DLL {
    Node head, tail = null;

    void addNode(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
            head.prev = null;
            tail.next = null;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
            tail.next = null;
        }
    }

    void deleteNode(int data) {
        Node curr = head;
        while (curr != null) {
            if (curr.data == data) {
                if (curr == head) {
                    curr = curr.next;
                    curr.prev = null;
                    head = curr;
                    System.out.println("Deleted");
                    break;
                } else if (curr == tail) {
                    curr = curr.prev;
                    curr.next = null;
                    tail = curr;
                    System.out.println("Deleted");
                    break;
                } else {
                    Node currPrev = curr.prev;
                    curr = curr.next;
                    currPrev.next = curr;
                    curr.prev = currPrev;
                    System.out.println("Deleted");
                    break;
                }
            }
            curr = curr.next;
        }
    }

    void display() {
        Node curr = head;
        while (curr != null) {
            System.out.println(curr.data + "  ");
            curr = curr.next;
        }
    }
}

class TestDLL {
    public static void main(String args[]) {
        DLL newDLL = new DLL();
        Scanner scanner = new Scanner(System.in);
        int choice, data;

        char ch;
        do {
            System.out.println("\n1. Add Node");
            System.out.println("2. Delete Node");
            System.out.println("3. Display DLL");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter data for new node: ");
                    data = scanner.nextInt();
                    newDLL.addNode(data);
                    break;
                case 2:
                    System.out.print("Enter data to delete: ");
                    data = scanner.nextInt();
                    newDLL.deleteNode(data);
                    break;
                case 3:
                    newDLL.display();
                    break;
                case 4:
                    System.out.println("Exiting the program.");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please choose again.");
            }
            System.out.print("Do you want to continue (y/n): ");
            ch = scanner.next().charAt(0);
        } while (ch == 'y');
    }
}
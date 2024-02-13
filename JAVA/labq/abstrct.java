import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

abstract class Vehicle {
    int wheels;
    int year;

    abstract double calcFuelUsage();

    void display() {
        System.out.println("Vehicle Type: " + this.getClass().getSimpleName());
        System.out.println("Number of Wheels: " + wheels);
        System.out.println("Manufacturing Year: " + year);
    }
}

class Car extends Vehicle {
    final int maxSpeed;
    final double mileage;

    Car(int wheels, int year, int maxSpeed, double mileage) {
        this.wheels = wheels;
        this.year = year;
        this.maxSpeed = maxSpeed;
        this.mileage = mileage;
    }

    @Override
    double calcFuelUsage() {
        // Assuming a simple linear relationship between speed and fuel usage
        return 1000 / mileage + (maxSpeed / 100.0);
    }
}

class Motorcycle extends Vehicle {
    final int maxSpeed;
    final double mileage;

    Motorcycle(int wheels, int year, int maxSpeed, double mileage) {
        this.wheels = wheels;
        this.year = year;
        this.maxSpeed = maxSpeed;
        this.mileage = mileage;
    }

    @Override
    double calcFuelUsage() {
        // Assuming a simple linear relationship between speed and fuel usage
        return 1000 / mileage + (maxSpeed / 100.0);
    }
}

public class Main {
    public static void main(String[] args) {
        FileWriter writer=null;
        if (args.length == 0) {
            System.out.println("Please provide a file name as a command line argument.");
            return;
        }

        try {
             writer=new FileWriter(args[0]);
            Car car = new Car(4, 2022, 200, 15);
            Motorcycle motorcycle = new Motorcycle(2, 2022, 150, 25);

            writer.write("Fuel Consumption in 1000 km:");
           // writer.newLine();
            writer.write("Car: " + car.calcFuelUsage());
          //  writer.newLine();
            writer.write("Motorcycle: " + motorcycle.calcFuelUsage());
          //  writer.newLine();

            writer.write("Distance Travelled in 90 minutes:");
        //    writer.newLine();
            writer.write("Car: " + car.calcFuelUsage() * 90);
        //    writer.newLine();
            writer.write("Motorcycle: " + motorcycle.calcFuelUsage() * 90);

            System.out.println("Output written to " + args[0]);
             writer.close();
        } 
       
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}

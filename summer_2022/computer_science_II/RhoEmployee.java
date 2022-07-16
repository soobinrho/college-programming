// COSC 211
// Soobin Rho
// July 18, 2022
import java.util.Scanner;

public class RhoEmployee {
    /*
     * A class for a hardware store's invoices.
    */

    // Initialize instance variables.
    String firstName;
    String lastName;
    double monthlySalary;

    public RhoEmployee(String firstName,
                       String lastName,
                       double monthlySalary) {

        this.firstName = firstName;
        this.lastName = lastName;

        // Check if monthlySalary is valid.
        if (monthlySalary > 0) {
            this.monthlySalary = monthlySalary;
        }

        // If monthlySalary is not positive, leave it as a null.
        else {
            System.out.println("Invalid monthly salary.");
        }

    }

    // ----------------------------------
    // firstName getter and setter
    // ----------------------------------
    public String getFirstname() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    // ----------------------------------
    // lastName getter and setter
    // ----------------------------------
    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    // ----------------------------------
    // monthlySalary getter and setter
    // ----------------------------------
    public double getMonthlySalary() {
        return monthlySalary;
    }

    public void setMonthlySalary(double monthlySalary) {

        // Check if monthlySalary is valid.
        if (monthlySalary > 0) {
            this.monthlySalary = monthlySalary;
        }

        // If monthlySalary is not positive, leave it as a null.
        else {
            System.out.println("Invalid monthly salary.");
        }

    }

    // ----------------------------------
    // Additional Instance Methods
    // ----------------------------------
    public double getYearlySalary() {
        double yearlySalary = monthlySalary * 12;
        return yearlySalary;
    }

    public String toString() {
        double yearlySalary = getYearlySalary();
        String output = String.format(
            "First name: %s%n" +
            "Last name: %s%n" +
            "Monthly salary: $%,.0f%n" +
            "Yearly salary: $%,.0f%n",
            firstName,
            lastName,
            monthlySalary,
            yearlySalary
        );
        return output;
    }

}


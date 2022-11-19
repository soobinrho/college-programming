// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.Scanner;

public class CommissionEmployee extends Employee {
    /*
     * Exercise 9.14
     * A child class of Employee.
    */
    private double grossSales;
    private double commissionRate;

    // ----------------------------
    // Constructor
    // ----------------------------
    public CommissionEmployee(
        String firstName,
        String lastName,
        String socialSecurityNumber,
        double grossSales,
        double commissionRate
    ) {

        // Call the super class's constructor.
        super(
            firstName,
            lastName,
            socialSecurityNumber
        );

        // Validate.
        if (grossSales < 0.0) {
            throw new IllegalArgumentException("Invalid grossSales.");
        }
        if (commissionRate <= 0.0 || commissionRate >= 1.0) {
            throw new IllegalArgumentException("Invalid commissionRate.");
        }

        this.grossSales = grossSales;
        this.commissionRate = commissionRate;

    }

    // ----------------------------
    // toString Method
    // ----------------------------
    public String toString() {
        String output = String.format(
            "%s%n%s: %.2f%n%s: %.2f",
            super.toString(),
            "gross sales", grossSales,
            "commission rate", commissionRate
        );
        return output;
    }

    // ----------------------------
    // Getters and Setters
    // ----------------------------
    public double getGrossSales() {return grossSales;}
    public double getCommissionRate() {return commissionRate;}

    public void setGrossSales(double grossSales) {
        this.grossSales = grossSales;
    }

    public void setCommissionRate(double commissionRate) {
        this.commissionRate = commissionRate;
    }

    // ----------------------------
    // Getters and Setters
    // ----------------------------
    public double earnings() {
        double total = grossSales * commissionRate;
        return total;
    }

}


// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.Scanner;

public class BasePlusCommissionEmployee {
    /*
     * Exercise 9.3
     * A class that uses composition
     * instead of inheritance.
    */
    private CommissionEmployee employee;
    private double baseSalary;

    // ----------------------------
    // Constructor
    // ----------------------------
    public BasePlusCommissionEmployee(
        String firstName,
        String lastName,
        String socialSecurityNumber,
        double grossSales,
        double commissionRate,
        double baseSalary
    ) {
        this.employee = new CommissionEmployee(
            firstName,
            lastName,
            socialSecurityNumber,
            grossSales,
            commissionRate
        );
        this.baseSalary = baseSalary;
    }

    // ----------------------------
    // toString Method
    // ----------------------------
    public String toString() {
        String output = String.format(
            "base-salaried %s%n%s: %.2f",
            employee.toString(),
            "base salary",
            getBaseSalary()
        );
        return output;
    }

    // ----------------------------
    // Wrappers
    // ----------------------------
    public String getFirstName() {return employee.getFirstName();}
    public String getLastName() {return employee.getLastName();}
    public String getSocialSecurityNumber() {return employee.getSocialSecurityNumber();}
    public Double getGrossSales() {return employee.getGrossSales();}
    public Double getCommissionRate() {return employee.getCommissionRate();}

    // ----------------------------
    // Getter and Setter
    // ----------------------------
    public double getBaseSalary() {return baseSalary;}

    public void setBaseSalary(double baseSalary) {
        if (baseSalary < 0.0) {
            throw new IllegalArgumentException("Invalid baseSalary.");
        }
        this.baseSalary = baseSalary;
    }

    // ----------------------------
    // Additional Method
    // ----------------------------
    public double earnings() {
        double total = getBaseSalary() + employee.earnings();
        return total;
    }

}


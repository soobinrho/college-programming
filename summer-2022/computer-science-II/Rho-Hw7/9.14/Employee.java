// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.Scanner;

public class Employee {
    /*
     * Exercise 9.14
     * A super class.
    */
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;

    // ----------------------------
    // Constructor
    // ----------------------------
    public Employee(
        String firstName,
        String lastName,
        String socialSecurityNumber
    ) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.socialSecurityNumber = socialSecurityNumber;
    }

    // ----------------------------
    // toString Method
    // ----------------------------
    public String toString() {
        String output = String.format(
            "%s: %s %s%n%s: %s",
            "commission employee", firstName, lastName,
            "social security number", socialSecurityNumber
        );
        return output;
    }

    // ----------------------------
    // Getters
    // ----------------------------
    public String getFirstName() {return firstName;}
    public String getLastName() {return lastName;}
    public String getSocialSecurityNumber() {return socialSecurityNumber;}

}


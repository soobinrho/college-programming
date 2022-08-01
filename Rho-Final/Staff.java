// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class Staff extends Employee {
    /*
     * The class Staff is not used by the main program,
     * but provides setters and getters for
     * student employee information.
     *
     * This class is a child class of Employee,
     * but at the same time, uses composition
     * to use attributes of the class Student.
    */

    //------------------------------------
    // Instance Variables
    //------------------------------------
    private String title;        // Job title
                                 // e.g. "Adjunct Professor"

    private String dept;         // Department
                                 // e.g. "MAGI"

    private boolean fullTime;    // Whether or not full-time
                                 // e.g. true

    private double payRate;      // Hourly rate of pay
                                 // e.g. 15.9

    private Student student;     // Student information
                                 // e.g. new Student()

    //------------------------------------
    // Constructors
    //------------------------------------
    public Staff() {
        this(
            "Default",
            "Staff",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 1, 1),
            100001,
            new Date(2021, 1, 1),
            "Stew Staff",
            "MAGI",
            true,
            15.0
        );
    }

    // Constructor for regular staff that are
    // not student employees.
    public Staff(

        // From super class
        String firstName,
        String lastName,
        String address,
        int ssNum,
        Date birthDate,
        int iD,
        Date startDate,

        // Solely this class
        String title,
        String dept,
        boolean fullTime,
        double payRate

    ) {

        // Call the super class's constructor.
        super(
            firstName,
            lastName,
            address,
            ssNum,
            birthDate,
            iD,
            startDate
        );

        // Construct the instance variables.
        this.title = title;
        this.dept = dept;
        this.fullTime = fullTime;

        // Throw error if payRate is negative.
        if (payRate < 0) {
            throw new IllegalArgumentException("Invalid payRate.");
        }
        this.payRate = payRate;

    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setTitle(String title) {this.title = title;}
    public String getTitle() {return title;}

    public void setDept(String dept) {this.dept = dept;}
    public String getDept() {return dept;}

    public void setFullTime(boolean fullTime) {this.fullTime = fullTime;}
    public boolean getFullTime() {return fullTime;}

    public void setPayRate(double payRate) {

        // Throw error if payRate is negative.
        if (payRate < 0) {
            throw new IllegalArgumentException("Invalid payRate.");
        }
        this.payRate = payRate;

    }
    public double getPayRate() {return payRate;}

    //-------------------------------------
    // toString Method
    //-------------------------------------
    public String toString() {
        String output = String.format(
            "%s | %s | %s | %s | %.2f",
            super.toString(),
            title,
            dept,
            Boolean.toString(fullTime),
            payRate
        );
        return output;
    }

}

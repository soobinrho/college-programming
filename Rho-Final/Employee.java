// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class Employee extends Person {
    /*
     * The class Employee is used as a parent class
     * for the class Faculty and the class Staff,
     * which are then used by
     * the main program CourseListingSystem.
    */

    //------------------------------------
    // Instance Variables
    //------------------------------------
    private int ID;            // Employee ID
                               // e.g. 100234

    private Date startDate;    // Date of employment
                               // e.g. new Date(2002, 7, 25)

    //------------------------------------
    // Constructors
    //------------------------------------
    public Employee() {
        this(
            "Default",
            "Employee",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 1, 1),
            100001,
            new Date(2021, 1, 1)
        );
    }

    public Employee(

        // From super class
        String firstName,
        String lastName,
        String address,
        int ssNum,
        Date birthDate,

        // Solely this class
        int ID,
        Date startDate

    ) {

        // Call the super class's constructor.
        super(
            firstName,
            lastName,
            address,
            ssNum,
            birthDate
        );

        // Construct the instance variables.
        this.ID = ID;
        this.startDate = startDate;

    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setID(int ID) {this.ID = ID;}
    public int getID() {return ID;}

    public void setStartDate(Date startDate) {this.startDate = startDate;}
    public Date getStartDate() {return startDate;}

    //-------------------------------------
    // toString Method
    //-------------------------------------
    public String toString() {
        String output = String.format(
            "%s | %d | %d %d %d",
            super.toString(),
            ID,
            startDate.getYear(),
            startDate.getMonth(),
            startDate.getDate()
        );
        return output;
    }

}

// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class Student extends Person {
    /*
     * The class Student is used by CourseListingSystem.java
     * to provide getters and setters to student information.
    */

    //------------------------------------
    // Instance Variables
    //------------------------------------
    private int ID;                 // Student ID
                                    // e.g. 698635

    private Date startDate;         // Date of the first date at uni
                                    // e.g. new Date(2017, 8, 25)

    private Date expGradDate;       // Expected graduation date
                                    // e.g. new Date(2025, 5, 17)

    private int crTaken;            // Number of credits attempted
                                    // e.g. 36

    private int crPassed;           // Number of credits passed
                                    // e.g. 36

    private int currCr;             // Number of credits taken now
                                    // e.g. 12

    private String[] courseList;    // List of courses
                                    // e.g. new String[] {"COSC 211"}

    //------------------------------------
    // Constructors
    //------------------------------------
    public Student() {
        this(
            "Default",
            "Person",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 8, 22),
            698635,
            new Date(2017, 8, 25),
            new Date(2025, 5, 17)
        );
    }

    public Student(

        // From super class
        String firstName,
        String lastName,
        String address,
        int ssNum,
        Date birthDate,

        // Solely this class
        int ID,
        Date startDate,
        Date expGradDate

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
        this.expGradDate = expGradDate;

    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setID(int ID) {this.ID = ID;}
    public int getID() {return ID;}

    public void setStartDate(Date startDate) {this.startDate = startDate;}
    public Date getStartDate() {return startDate;}

    public void setExpGradDate(Date expGradDate) {this.expGradDate = expGradDate;}
    public Date getExpGradDate() {return expGradDate;}

    public void setCrTaken(int crTaken) {this.crTaken = crTaken;}
    public int getCrTaken() {return crTaken;}

    public void setCrPassed(int crPassed) {this.crPassed = crPassed;}
    public int getCrPassed() {return crPassed;}

    public void setCurrCr(int currCr) {this.currCr = currCr;}
    public int getCurrCr() {return currCr;}

    //-------------------------------------
    // addCourse & delCourse
    //-------------------------------------
    public void addCourse(Course course) {
        ;
    }

    public void delCourse(Course course) {
        ;
    }

    //-------------------------------------
    // A method for getting the course list
    //-------------------------------------
    public String courseList() {
        String list = "";
        return list;
    }

    //-------------------------------------
    // toString Method
    //-------------------------------------
    public String toString() {
        String output = String.format(
            "%s | %d | %d %d %d | %d %d %d | %d | %d | %d",
            super.toString(),
            ID,
            startDate.getYear(),
            startDate.getMonth(),
            startDate.getDate(),
            expGradDate.getYear(),
            expGradDate.getMonth(),
            expGradDate.getDate(),
            crTaken,
            crPassed,
            currCr
        );
        return output;
    }

}

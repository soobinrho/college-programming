// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class Faculty extends Employee {
    /*
     * The class Faculty is used by CourseListingSystem.java
     * to provide getters and setters to faculty information.
    */

    //------------------------------------
    // Instance Variables
    //------------------------------------
    private String title;           // Job title
                                    // e.g. "Adjunct Professor"

    private String dept;            // Department
                                    // e.g. "MAGI"

    private int salary;             // Annual salary
                                    // e.g. 1000000

    private String[] courseList;    // List of courses
                                    // e.g. new String[] {"MAGI 301"}

    //------------------------------------
    // Constructors
    //------------------------------------
    public Faculty() {
        this(
            "Default",
            "Faculty",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 1, 1),
            100001,
            new Date(2021, 1, 1),
            "Adjunct Professor",
            "COSC",
            100000
        );
    }

    public Faculty(

        // From super class
        String firstName,
        String lastName,
        String address,
        int ssNum,
        Date birthDate,
        int ID,
        Date startDate,

        // Solely this class
        String title,
        String dept,
        int salary

    ) {

        // Call the super class's constructor.
        super(
            firstName,
            lastName,
            address,
            ssNum,
            birthDate,
            ID,
            startDate
        );

        // Construct the instance variables.
        this.title = title;
        this.dept = dept;
        this.salary = salary;

    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setTitle(String title) {this.title = title;}
    public String getTitle() {return title;}

    public void setDept(String dept) {this.dept = dept;}
    public String getDept() {return dept;}

    public void setSalary(int salary) {this.salary = salary;}
    public int getSalary() {return salary;}

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
            "%s | %s | %s | %,d",
            super.toString(),
            title,
            dept,
            salary
        );
        return output;
    }

}

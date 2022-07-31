// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;

public class Course {
    /*
     * The class Course is used by CourseListingSystem.java
     * to provide getters and setters to course information.
    */

    //------------------------------------
    // Instance Variables
    //------------------------------------
    private String title;         // Course title
                                  // e.g. "Computer Science II"

    private String dept;          // Academic department code
                                  // e.g. "COSC"

    private int number;           // Course number
                                  // e.g. 211

    private String section;       // Course section
                                  // e.g. "A"

    private String[] schedule;    // Days/time the course meets
                                  // e.g. new String[] {"MWF 9:00am - 9:50am"}

    //------------------------------------
    // Constructors
    //------------------------------------
    public Course() {
        this(
            "Default Title",
            "COSC",
            101,
            "A",
            new String[] {"MWF 9:00am - 9:50am"}
        );
    }

    public Course(
        String title,
        String dept,
        int number,
        String section,
        String[] schedule
    ) {
        this.title = title;
        this.dept = dept;
        this.number = number;
        this.section = section;
        this.schedule = schedule;
    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setTitle(String title) {this.title = title;}
    public String getTitle() {return title;}

    public void setDept(String dept) {this.dept = dept;}
    public String getDept() {return dept;}

    public void setNumber(int number) {this.number = number;}
    public int getNumber() {return number;}

    public void setSection(String section) {this.section = section;}
    public String getSection() {return section;}

    public void setSchedule(String[] schedule) {this.schedule = schedule;}
    public String[] getSchedule() {return schedule;}

}


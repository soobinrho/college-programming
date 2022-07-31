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

        // Throw error if salary is negative.
        if (salary < 0) {
            throw new IllegalArgumentException("Invalid salary.");
        }
        this.salary = salary;

        // courseList is not to be populated
        // in the constructor; instead, just
        // make it an array with the length of 0.
        courseList = new String[0];

    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setTitle(String title) {this.title = title;}
    public String getTitle() {return title;}

    public void setDept(String dept) {this.dept = dept;}
    public String getDept() {return dept;}


    public void setSalary(int salary) {

        // Throw error if salary is negative.
        if (salary < 0) {
            throw new IllegalArgumentException("Invalid salary.");
        }
        this.salary = salary;

    }
    public int getSalary() {return salary;}

    //-------------------------------------
    // addCourse & delCourse
    //-------------------------------------
    public void addCourse(Course course) {

        // Get the course code
        // e.g. COSC 211
        String courseDept = course.getDept();
        int courseNumber = course.getNumber();
        String courseCode = String.format(
            "%s %d",
            courseDept,
            courseNumber
        );

        // Normally, ArrayLists would be a better
        // choice since ArralyLists are not
        // immutable unlike arrays.
        // However, I use array here just as a practice.

        // Uncomment to debug.
        //System.out.printf(
        //    "%nDEBUG START | courseList %s %n",
        //    listOfCourses()
        //);

        // What I'm doing here is to make a new
        // array with just one size bigger.
        String[] courseListBackup = courseList;
        courseList = new String[courseListBackup.length + 1];

        for (int index = 0; index < courseListBackup.length; index++) {

            // Assign original values back to the new array.
            courseList[index] = courseListBackup[index];

            // Uncomment to debug.
            //System.out.printf(
            //    "    index: %d | target: %s | courseList: %s%n",
            //    index,
            //    courseCode,
            //    listOfCourses()
            //);

        }

        // Assign the new course code into the new array.
        courseList[courseListBackup.length] = courseCode;

        // Uncomment to debug.
        //System.out.printf(
        //    "DEBUG END | courseList %s %n",
        //    listOfCourses()
        //);

    }

    public void delCourse(Course course) {

        // Get the course code
        // e.g. COSC 211
        String courseDept = course.getDept();
        int courseNumber = course.getNumber();
        String courseCode = String.format(
            "%s %d",
            courseDept,
            courseNumber
        );

        // Uncomment to debug.
        //System.out.printf(
        //    "%nDEBUG START | courseList %s %n",
        //    listOfCourses()
        //);

        // Make a new array with just one size smaller.
        String[] courseListBackup = courseList;
        courseList = new String[courseListBackup.length - 1];

        // Assign original values back to the new array,
        // except nfor the course being deleted.
        int count = 0;
        int index = 0;
        while (count < courseListBackup.length) {

            // Assign original values to the new array.
            if (!courseListBackup[count].equals(courseCode)) {
                courseList[index] = courseListBackup[count];
                count++;
                index++;
            }

            // If the loop encounters the course being deleted,
            // then don't assign the value to the new array.
            else {count++;}

            // Uncomment to debug.
            //System.out.printf(
            //    "    count: %d | index: %d | target: %s | courseList: %s%n",
            //    count,
            //    index,
            //    courseCode,
            //    listOfCourses()
            //);

        }

        // Uncomment to debug.
        //System.out.printf(
        //    "DEBUG END | courseList %s %n",
        //    listOfCourses()
        //);

    }

    //-------------------------------------
    // A getter method for courseList
    //-------------------------------------
    public String listOfCourses() {
        return String.join(" ", courseList);
    }

    //-------------------------------------
    // toString Method
    //-------------------------------------
    public String toString() {
        String output = String.format(
            "%s | %s | %s | %d",
            super.toString(),
            title,
            dept,
            salary
        );
        return output;
    }

}

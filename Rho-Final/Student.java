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

        // courseList is not to be populated
        // in the constructor; instead, just
        // make it an array with the length of 0.
        courseList = new String[0];

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
        //    getCourseList()
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
            //    getCourseList()
            //);

        }

        // Assign the new course code into the new array.
        courseList[courseListBackup.length] = courseCode;

        // Uncomment to debug.
        //System.out.printf(
        //    "DEBUG END | courseList %s %n",
        //    getCourseList()
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
        //    getCourseList()
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
            //    getCourseList()
            //);

        }

        // Uncomment to debug.
        //System.out.printf(
        //    "DEBUG END | courseList %s %n",
        //    getCourseList()
        //);

    }

    //-------------------------------------
    // A getter method for courseList
    //-------------------------------------
    public String getCourseList() {
        return String.join(" ", courseList);
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

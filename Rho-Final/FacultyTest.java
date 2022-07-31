// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class FacultyTest {
    /*
     * Testing and debugging
     * the class Faculty.
    */
    public static void main(String[] args) {

        // --------------------------------
        // Initialize an instance.
        // --------------------------------
        Faculty exampleFaculty = new Faculty(
            "Bean",
            "Soup",
            "2000 S. Chilli Factory, 57196",
            123456789,
            new Date(1998, 8, 22),
            100234,
            new Date(2002, 7, 25),
            "Adjunct Professor",
            "MAGI",
            1200000
        );

        // --------------------------------
        // Print the initialized instance.
        // --------------------------------
        System.out.println(exampleFaculty);
        System.out.println();

        // --------------------------------
        // Test if setters work properly.
        // --------------------------------
        exampleFaculty.setFirstName("Fried");
        exampleFaculty.setLastName("Chicken");
        exampleFaculty.setAddress("1999 S. Eggs Factory, 57195");
        exampleFaculty.setSSNum(123123123);
        exampleFaculty.setBirthDate(new Date(2022, 7, 31));
        exampleFaculty.setID(432991);
        exampleFaculty.setStartDate(new Date(2022, 7, 31));
        exampleFaculty.setTitle("Associate Professor");
        exampleFaculty.setDept("WIZA");
        exampleFaculty.setSalary(3750000);

        // --------------------------------
        // Print the changed values.
        // --------------------------------
        System.out.println(exampleFaculty);
        System.out.println();

        // ---------------------------------
        // Test if addCourse works properly.
        // ---------------------------------
        Course exampleCourse = new Course(
            "Computer Science II",
            "COSC",
            211,
            "A",
            new String[] {"MWF 9:00am - 9:50am"}
        );

        exampleFaculty.addCourse(exampleCourse);

        // ---------------------------------
        // Print courseList.
        // ---------------------------------
        System.out.printf(
            "courseList: %s%n%n",
            exampleFaculty.listOfCourses()
        );

        // ---------------------------------
        // Test if delCourse works properly.
        // ---------------------------------
        exampleFaculty.delCourse(exampleCourse);

        // ---------------------------------
        // Print courseList.
        // ---------------------------------
         System.out.printf(
            "courseList: %s%n%n",
            exampleFaculty.listOfCourses()
        );

    }

}


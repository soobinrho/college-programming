// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;

public class CourseTest {
    /*
     * Testing and debugging
     * the class Course.
    */
    public static void main(String[] args) {

        // --------------------------------
        // Initialize an instance.
        // --------------------------------
        Course exampleCourse = new Course(
            "Computer Science II",
            "COSC",
            211,
            "A",
            new String[] {"MWF 9:00am - 9:50am"}
        );

        // --------------------------------
        // Print the initialized instance.
        // --------------------------------
        System.out.println(exampleCourse);
        System.out.println();

        // --------------------------------
        // Test if setters work properly.
        // --------------------------------
        exampleCourse.setTitle("Soup Culinary Enchantment");
        exampleCourse.setDept("MAGI");
        exampleCourse.setNumber(301);
        exampleCourse.setSection("G");
        exampleCourse.setSchedule(new String[] {"TF 11:00am - 2:00pm"});

        // --------------------------------
        // Print the changed values.
        // --------------------------------
        System.out.println(exampleCourse);

    }

}


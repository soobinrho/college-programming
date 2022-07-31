// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner; import java.util.Date;

public class StudentTest {
    /*
     * Testing and debugging
     * the class Student.
    */
    public static void main(String[] args) {

        // --------------------------------
        // Initialize an instance.
        // --------------------------------
        Student exampleStudent = new Student(
            "Soobin",
            "Rho",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 8, 22),
            698635,
            new Date(2017, 8, 25),
            new Date(2025, 5, 17)
        );

        // --------------------------------
        // Print the initialized instance.
        // --------------------------------
        System.out.println(exampleStudent);
        System.out.println();

        // --------------------------------
        // Test if setters work properly.
        // --------------------------------
        exampleStudent.setFirstName("Bean");
        exampleStudent.setLastName("Soup");
        exampleStudent.setAddress("2000 S. Chilli Factory, 57196");
        exampleStudent.setSSNum(123123123);
        exampleStudent.setBirthDate(new Date(2022, 7, 31));
        exampleStudent.setiD(826231);
        exampleStudent.setStartDate(new Date(2022, 8, 1));
        exampleStudent.setExpGradDate(new Date(2026, 5, 17));
        exampleStudent.setCrTaken(4);
        exampleStudent.setCrPassed(4);
        exampleStudent.setCurrCr(12);

        // ---------------------------------
        // Print the changed values.
        // ---------------------------------
        System.out.println(exampleStudent);
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

        exampleStudent.addCourse(exampleCourse);

        // ---------------------------------
        // Print courseList.
        // ---------------------------------
        System.out.printf(
            "courseList: %s%n%n",
            exampleStudent.listOfCourses()
        );

        // ---------------------------------
        // Test if delCourse works properly.
        // ---------------------------------
        exampleStudent.delCourse(exampleCourse);

        // ---------------------------------
        // Print courseList.
        // ---------------------------------
         System.out.printf(
            "courseList: %s%n%n",
            exampleStudent.listOfCourses()
        );

    }

}


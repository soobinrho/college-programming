// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class EmployeeTest {
    /*
     * Testing and debugging
     * the class Employee.
    */
    public static void main(String[] args) {

        // --------------------------------
        // Initialize an instance.
        // --------------------------------
        Employee exampleEmployee = new Employee(
            "Bean",
            "Soup",
            "2000 S. Chilli Factory, 57196",
            123456789,
            new Date(1998, 8, 22),
            100234,
            new Date(2002, 7, 25)
        );

        // --------------------------------
        // Print the initialized instance.
        // --------------------------------
        System.out.println(exampleEmployee);
        System.out.println();

        // --------------------------------
        // Test if setters work properly.
        // --------------------------------
        exampleEmployee.setFirstName("Fried");
        exampleEmployee.setLastName("Chicken");
        exampleEmployee.setAddress("1999 S. Eggs Factory, 57195");
        exampleEmployee.setSSNum(123123123);
        exampleEmployee.setBirthDate(new Date(2022, 7, 31));
        exampleEmployee.setID(432991);
        exampleEmployee.setStartDate(new Date(2022, 7, 31));

        // --------------------------------
        // Print the changed values.
        // --------------------------------
        System.out.println(exampleEmployee);

    }

}


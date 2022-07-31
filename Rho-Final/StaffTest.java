// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class StaffTest {
    /*
     * Testing and debugging
     * the class Staff.
    */
    public static void main(String[] args) {

        // --------------------------------
        // Initialize an instance.
        // --------------------------------
        Staff exampleStaff = new Staff(
            "Bean",
            "Soup",
            "2000 S. Chilli Factory, 57196",
            123456789,
            new Date(1998, 8, 22),
            100234,
            new Date(2002, 7, 25),
            "Stew Staff",
            "MAGI",
            true,
            15.9
        );

        // --------------------------------
        // Print the initialized instance.
        // --------------------------------
        System.out.println(exampleStaff);
        System.out.println();

        // --------------------------------
        // Test if setters work properly.
        // --------------------------------
        exampleStaff.setFirstName("Fried");
        exampleStaff.setLastName("Chicken");
        exampleStaff.setAddress("1999 S. Eggs Factory, 57195");
        exampleStaff.setSSNum(123123123);
        exampleStaff.setBirthDate(new Date(2022, 7, 31));
        exampleStaff.setID(432991);
        exampleStaff.setStartDate(new Date(2022, 7, 31));
        exampleStaff.setTitle("Chicken Staff");
        exampleStaff.setDept("WIZA");
        exampleStaff.setFullTime(false);
        exampleStaff.setPayRate(55.5);

        // --------------------------------
        // Print the changed values.
        // --------------------------------
        System.out.println(exampleStaff);

    }

}


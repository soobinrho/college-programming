// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class PersonTest {
    /*
     * Testing and debugging
     * the class Person.
    */
    public static void main(String[] args) {

        // --------------------------------
        // Initialize an instance.
        // --------------------------------
        Person examplePerson = new Person(
            "Soobin",
            "Rho",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 8, 22)
        );

        // --------------------------------
        // Print the initialized instance.
        // --------------------------------
        System.out.println(examplePerson);
        System.out.println();

        // --------------------------------
        // Test if setters work properly.
        // --------------------------------
        examplePerson.setFirstName("Bean");
        examplePerson.setLastName("Soup");
        examplePerson.setAddress("2000 S. Chilli Factory, 57196");
        examplePerson.setSSNum(123123123);
        examplePerson.setBirthDate(new Date(2022, 7, 31));

        // --------------------------------
        // Print the changed values.
        // --------------------------------
        System.out.println(examplePerson);

    }

}


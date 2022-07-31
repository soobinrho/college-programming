// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.Scanner;
import java.util.Date;

public class Person {
    /*
     * The class Person is used as a parent class
     * for the class Student and the class Employee,
     * which are then used by
     * the main program CourseListingSystem.
    */

    //------------------------------------
    // Instance Variables
    //------------------------------------
    private String firstName;    // Person's first name
                                 // e.g. Soobin

    private String lastName;     // Person's last name
                                 // e.g. Rho

    private String address;      // Full address
                                 // e.g. 2001 S. Summit Ave, 57197

    private int ssNum;           // SSN
                                 // e.g. 123456789

    private Date birthDate;      // Date of birth
                                 // e.g. new Date(1998, 8, 22)

    //------------------------------------
    // Constructors
    //------------------------------------
    public Person() {
        this(
            "Default",
            "Person",
            "2001 S. Summit Ave, 57197",
            123456789,
            new Date(1998, 8, 22)
        );
    }

    public Person(
        String firstName,
        String lastName,
        String address,
        int ssNum,
        Date birthDate
    ) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.address = address;
        this.ssNum = ssNum;
        this.birthDate = birthDate;
    }

    //------------------------------------
    // Setters and Getters
    //------------------------------------
    public void setFirstName(String firstName) {this.firstName = firstName;}
    public String getFirstName() {return firstName;}

    public void setLastName(String lastName) {this.lastName = lastName;}
    public String getLastName() {return lastName;}

    public void setAddress(String address) {this.address = address;}
    public String getAddress() {return address;}

    public void setSSNum(int ssNum) {this.ssNum = ssNum;}
    public int getSSNum() {return ssNum;}

    public void setBirthDate(Date birthDate) {this.birthDate = birthDate;}
    public Date getBirthDate() {return birthDate;}

}


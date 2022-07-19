// COSC 211
// Soobin Rho
// July 19, 2022
import java.util.Scanner;

public class RhoDateTest {
    /*
     * Testing the class RhoDate.
    */
    public static void main(String[] args) {

        // Construct a RhoDate instance.
        RhoDate dateSample = new RhoDate(7, 30, 2022);

        // a) Increment into the next month.
        for (int count = 0; count < 2; count++) {
            dateSample.nextDay();
            System.out.printf("%s %n", dateSample.toString());
        }

        // Print a newline for readability.
        System.out.println();

        // b) Increment into the next year.
        dateSample = new RhoDate(12, 22, 2022);
        for (int count = 0; count < 10; count++) {
            dateSample.nextDay();
            System.out.printf("%s %n", dateSample.toString());
        }

    }

}

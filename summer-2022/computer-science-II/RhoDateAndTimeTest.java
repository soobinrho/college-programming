// COSC 211
// Soobin Rho
// July 19, 2022
import java.util.Scanner;

public class RhoDateAndTimeTest {
    /*
     * Testing the class RhoDateAndTime.
    */
    public static void main(String[] args) {

        // Constructing an instance of
        // of RhoDateAndTime, and I do this
        // by using instances of RhoDate and RhoTime2.
        RhoDate dateSample = new RhoDate(7, 30, 2022);
        RhoTime2 timeSample = new RhoTime2(22, 58, 59);
        RhoDateAndTime example = new RhoDateAndTime(
            dateSample,
            timeSample
        );
        System.out.println(example.toString());

        // Incrementing the time to the next day.
        for (int count = 0; count < 10; count++) {
            example.incrementHour();
            System.out.printf("%s", example.toString());
        }

    }

}


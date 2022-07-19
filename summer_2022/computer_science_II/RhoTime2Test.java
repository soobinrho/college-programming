// COSC 211
// Soobin Rho
// July 19, 2022
import java.util.Scanner;

public class RhoTime2Test {
    /*
     * Testing the class RhoTime2.
    */
    public static void main(String[] args) {

        // Construct an object of RhoTime2.
        RhoTime2 timeNow = new RhoTime2(22, 58, 59);
        System.out.printf("%s%n%n", timeNow.toString());

        // a) Increment into the next minute.
        timeNow.tick();
        System.out.printf("%s%n%n", timeNow.toString());

        // b) Increment into the next hour.
        timeNow.incrementMinute();
        System.out.printf("%s%n%n", timeNow.toString());

        // c) Increment into the next day.
        timeNow.incrementHour();
        System.out.printf("%s%n%n", timeNow.toString());

    }

}


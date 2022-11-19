// COSC 211
// Soobin Rho
// July 19, 2022
import java.util.Scanner;

public class RhoDateAndTime {
    /*
     * A class that combines the classes
     * RhoTime2 and RhoDate.
    */

    private RhoDate date;
    private RhoTime2 time;

    // ----------------------------
    // Constructor
    // ----------------------------
    public RhoDateAndTime(RhoDate date, RhoTime2 time) {
        this.date = date;
        this.time = time;
    }

    // ----------------------------
    // toString Method
    // ----------------------------
    public String toString() {
        String output = String.format(
            "%s %s %n",
            date.toString(),
            time.toString()
        );
        return output;
    }

    // ----------------------------
    // A method that increments
    // into the next day.
    // ----------------------------
    public void incrementHour() {

        // -----------------------------
        // Two possible cases:
        // 1. No overflow. Add as usual.
        // 2. Overflow. Next day.
        // -----------------------------

        // 1. No overflow. Add as usual.
        if (time.getHour() != 23) {time.incrementHour();}

        // 2. Overflow. Next day.
        else {
            date.nextDay();
            time.setHour(0);
        }

    }

}

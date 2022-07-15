// Programmed by: Soobin Rho
// Problem 6.28
// COSC211
// July 15, 2022
import java.util.Scanner;
import java.security.SecureRandom;

public class RhoRace {
    /*
     * The Tortoise and the Hare Simulation
    */

    // -------------------------
    // Initialization
    // -------------------------

    // Simulation settings.
    private static final int RACELENGTH = 70; // (whitespaces)
    private static final double TIMESPEED = 0.11; // (seconds)

    // Inital positions for
    // the Tortoise and Hare.
    private static int positionT = 0;
    private static int positionH = 0;
    private static int time = 0;
    private static boolean isFinished = false;

    // Initializing a SecureRandom object.
    // This will be used for generating a random number.
    private static SecureRandom random = new SecureRandom();

    public static void main(String[] args) {

        // -------------------------
        // Start
        // -------------------------
        System.out.printf(
            "BANG!!!!!%n" +
            "AND THEY'RE OFF!!!!!%n"
        );
        printDashes();
        System.out.println();

        while (isFinished == false) {

            moveToNextPosition();
            printPosition();

            // Check if eith reached
            // the finish line.
            if(isFinished == false) {
                // Sleep because
                // it's no fun if it's too fast.
                try {
                    // Convert TIMESPEED to ms.
                    // Cast to long because
                    // this method expects a long value.
                    Thread.sleep((long) (TIMESPEED * 1000));
                }
                catch (InterruptedException e) {
                    // Thread.Sleep requires that
                    // this exception be caught every time.
                    // So, I put an empty try catch.
                    ;
                }
            }

        }

        // Print a newline for readability.
        System.out.println();

        // -------------------------
        // Finish
        // -------------------------
        printDashes();
        if (positionT > positionH) {
            System.out.printf(
                "%nTORTOISE WINS!!! YAY!!!"
            );
        }
        else if (positionT < positionH) {
            System.out.printf(
                "%nHare wins..."
            );
        }
        else if (positionT == positionH) {
            System.out.printf(
                "%nIt's a tie."
            );
        }
        System.out.printf(" (time = %d)%n", time);

    }

    // A method for getting a random number
    // between 0 and 10.
    private static int getRandomValue() {
        int randomValue = random.nextInt(10);
        return randomValue;
    }

    // A method for moving T and H, and
    // increasing time by 1.
    private static void moveToNextPosition() {

        // ---------------------------------
        // Rules
        // * If they are already at
        //   position 0, they can't go left.
        // * Game ends when either reaches
        //   the finish line.
        //
        // Tortoise
        // * Fast plod | 50% | +3
        // * Slow plod | 30% | +1
        // * Slip      | 20% | -6
        //
        // Hare
        // * Small hop  | 30% |  +1
        // * Big hop    | 20% |  +9
        // * Sleep      | 20% |   0
        // * Small slip | 20% |  -2
        // * Big slip   | 10% | -12
        // ---------------------------------
        int randomValue = getRandomValue();

        // ---------------------------------
        // Tortoise
        // ---------------------------------
        if (randomValue < 5) { // Fast plod
            positionT += 3;
        }
        else if (randomValue < 8) { // Slow pld
            positionT += 1;
        }
        else if (randomValue < 10) { // Slip
            positionT -= 6;
        }

        // ---------------------------------
        // Hare
        // ---------------------------------
        if (randomValue < 3) { // Small hop
            positionH += 1;
        }
        else if (randomValue < 5) { // Big hop
            positionH += 9;
        }
        else if (randomValue < 7) { // Sleep
            ;
        }
        else if (randomValue < 9) { // Small slip
            positionH -= 2;
        }
        else if (randomValue < 10) { // Big slip
            positionH -= 12;
        }

        time++;

        // Check if T moved more left
        // than the starting point.
        if (positionT < 0) {
            positionT = 0;
        }

        // Check if T reached the finish line.
        else if (positionT >= RACELENGTH) {

            // It's possible that their
            // positions are greater than
            // RACELENGTH. So, change it back.
            positionT = RACELENGTH - 1;
            isFinished = true;

        }

        // Check if H moved more left
        // than the starting point.
        if (positionH < 0) {
            positionH = 0;
        }

        // Check if H reached the finish line.
        else if (positionH >= RACELENGTH) {

            // It's possible that their
            // positions are greater than
            // RACELENGTH. So, change it back.
            positionH = RACELENGTH - 1;
            isFinished = true;

        }

    }

    // A method for printing
    // T's and H's positions.
    private static void printPosition() {

        // ------------------------------
        // Two possible cases
        // 1. They don't overlap.
        // 2. They overlap.
        //    So, T bites H.
        // -----------------------------

        // 1. They don't overlap.
        if (positionT != positionH) {

            // -----------------------------
            // Two possible cases again
            // 1. T is ahead.
            // 2. H is ahead.
            // -----------------------------

            // 1. T is ahead.
            if (positionT > positionH) {

                // Since H is behind,
                // H should be displayed first.
                for (int count = 0; count < positionH; count++) {
                    System.out.print(" ");
                }
                System.out.print("H");

                // Display T.
                int lengthWhiteSpace = positionT - positionH - 1;
                for (int count = 0; count < lengthWhiteSpace; count++) {
                    System.out.print(" ");
                }
                System.out.print("T");

            }

            // 2. H is ahead.
            if (positionT < positionH) {

                // Since T is behind,
                // T should be displayed first.
                for (int count = 0; count < positionT; count++) {
                    System.out.print(" ");
                }
                System.out.print("T");

                // Display H.
                int lengthWhiteSpace = positionH - positionT - 1;
                for (int count = 0; count < lengthWhiteSpace; count++) {
                    System.out.print(" ");
                }
                System.out.print("H");

            }

        }

        // 2. They overlap.
        //    So, T bites H.
        if (positionT == positionH) {
            for (int count = 0; count < positionT; count++) {
                System.out.print(" ");
            }
            System.out.print("OUCH!!!");
        }

        // Uncomment to debug.
        // System.out.printf(
        //     "    T: " + positionT +
        //     " | H: " + positionH
        // );

        // Print a newline.
        System.out.println();

    }

    // A method for printing dashes for readability.
    private static void printDashes() {

        for (int count = 0; count < RACELENGTH; count++) {
            System.out.print("-");
        }

        // Print a newline for readability.
        System.out.println();

    }

}


// COSC 211
// Soobin Rho
// July 21, 2022
import java.security.SecureRandom;
import java.io.FileNotFoundException;
import java.lang.SecurityException;
import java.util.Formatter;
import java.util.FormatterClosedException;
import java.util.NoSuchElementException;

public class CreateData {
    /*
     * Exercise 15.4
     * This class is in charge of
     * creating data for test purposes.
     * This uses random numbers to generate random
     * "trans.txt" and "oldmast.txt"
    */

    // Number of accounts on "oldmast.txt"
    // to be generated.
    private static final int NUM_ACCOUNTS = 10;

    // Number of unmatching accounts on "trans.txt"
    // to be generated.
    private static final int NUM_UNMATCHING = 2;

    // Initializing common accountNumbers.
    // I call this common because these will
    // be used for both "oldmast.txt" and "trans.txt"
    private static int[] accountNumbers = new int[NUM_ACCOUNTS +
                                                  NUM_UNMATCHING];

    // Initializing fields for "oldmast.txt"
    private static String[] firstNames = new String[NUM_ACCOUNTS +
                                                    NUM_UNMATCHING];
    private static String[] lastNames = new String[NUM_ACCOUNTS +
                                                   NUM_UNMATCHING];
    private static double[] balances = new double[NUM_ACCOUNTS +
                                                  NUM_UNMATCHING];

    // Initializing regular fields for "trans.txt"
    private static double[] transactionAmounts = new double[NUM_ACCOUNTS +
                                                            NUM_UNMATCHING];

    // Initializing a SecureRandom object.
    // This will be used for generating a random data.
    private static final SecureRandom random = new SecureRandom();

    // -----------------------------------------------------
    // A method for creating "trans.txt" and "oldmast.txt"
    // based on Figs. 15.16 and 15.17
    // -----------------------------------------------------
    public static void create() {

        // --------------------------------------
        // Generate random values for
        // transactionAmounts.
        // --------------------------------------
        for (
            int count = 0;
            count < NUM_ACCOUNTS + NUM_UNMATCHING;
            count++
        ) {

            accountNumbers[count] = 1000 + (count + 1);
            firstNames[count] = "Person";
            lastNames[count] = String.format("%d", count + 1);
            balances[count] = 1000000.0;
            transactionAmounts[count] = (
                // Generate a random transaction amount.
                // 0 < amount < 1,000,000
                1000000 * random.nextDouble()
            );

        }

        // --------------------------------------
        // Create "trans.txt"
        // --------------------------------------
        try (Formatter output = new Formatter("trans.txt")) {

            // Iterate through every element in the arrays
            // and write to the file.
            for (
                int count = 0;
                count < NUM_ACCOUNTS + NUM_UNMATCHING;
                count++
            ) {

                // "trans.txt" output example:
                // 1001 383721.46
                // 1002 82442.21
                output.format(
                    "%d %.2f %s",
                    accountNumbers[count],
                    transactionAmounts[count],
                    System.getProperty("line.separator")
                );

            }
        }

        // Exception handling for writing the file.
        catch (
            SecurityException |
            FileNotFoundException |
            FormatterClosedException e
        ) {
            e.printStackTrace();
        }

        // --------------------------------------
        // Create "oldmast.txt"
        // --------------------------------------
        try (Formatter output = new Formatter("oldmast.txt")) {

            // Iterate through the arrays
            // and write to the file.
            for (
                int count = 0;
                count < NUM_ACCOUNTS;
                count++
            ) {

                // "oldmast.txt" output example:
                // 1001 Person 1 1000000.00
                // 1002 Person 2 1000000.00
                output.format(
                    "%d %s %s %.2f %s",
                    accountNumbers[count],
                    firstNames[count],
                    lastNames[count],
                    balances[count],
                    System.getProperty("line.separator")
                );

            }
        }

        // Exception handling for writing the file.
        catch (
            SecurityException |
            FileNotFoundException |
            FormatterClosedException e
        ) {
            e.printStackTrace();
        }

    }

}


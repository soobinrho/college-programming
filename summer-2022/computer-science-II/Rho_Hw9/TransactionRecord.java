// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.lang.IllegalStateException;
import java.lang.SecurityException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.Formatter;
import java.util.NoSuchElementException;
import java.util.FormatterClosedException;

public class TransactionRecord {
    /*
     * Exercise 15.4
     * This class is in charge of
     * reading from and writing to "trans.txt"
    */
    private ArrayList<Integer> accountNumbers = new ArrayList<Integer>();
    private ArrayList<Double> transactionAmounts = new ArrayList<Double>();

    //------------------------------------
    // Constructor
    //------------------------------------
    public TransactionRecord() {

        // Read "trans.txt"
        try(Scanner input = new Scanner(Paths.get("trans.txt"))) {
            while (input.hasNext()) {
                accountNumbers.add(input.nextInt());
                transactionAmounts.add(input.nextDouble());
            }
        }
        catch (
            IOException |
            NoSuchElementException |
            IllegalStateException e
        ) {
            e.printStackTrace();
        }

    }

    //------------------------------------
    // Getters
    //------------------------------------
    public ArrayList<Integer> getAccountNumbers() {return accountNumbers;}
    public ArrayList<Double> getTransactionAmounts() {return transactionAmounts;}

    //------------------------------------
    // Setters
    //------------------------------------
    public void setAccountNumbers(ArrayList<Integer> accountNumbers) {
        this.accountNumbers = accountNumbers;
        save();
    }

    public void setTransactionAmounts(ArrayList<Double> transactionAmounts) {
        this.transactionAmounts = transactionAmounts;
        save();
    }

    public void save() {

        // Initializing length for the loop below.
        // This assumes the length of accountNumbers
        // is the same as every array's.
        int length = accountNumbers.size();

        // --------------------------------------
        // Recreate "trans.txt"
        // --------------------------------------
        try (Formatter output = new Formatter("trans.txt")) {

            // Iterate through every element in the arrays
            // and write to the file.
            for (int count = 0; count < length; count++) {

                // "trans.txt" output example:
                // 1001 383721.46
                // 1002 82442.21
                output.format(
                    "%d %.2f %s",
                    accountNumbers.get(count),
                    transactionAmounts.get(count),
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


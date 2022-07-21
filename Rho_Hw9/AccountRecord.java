// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileWriter;
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

public class AccountRecord {
    /*
     * Exercise 15.4
     * This class is in charge of
     * reading from and writing to
     * "oldmast.txt" and "newmast.txt"
    */
    private ArrayList<Integer> accountNumbers = new ArrayList<Integer>();
    private ArrayList<String> firstNames = new ArrayList<String>();
    private ArrayList<String> lastNames = new ArrayList<String>();
    private ArrayList<Double> balances = new ArrayList<Double>();

    //------------------------------------
    // Constructor
    //------------------------------------
    public AccountRecord() {

        // Read "oldmast.txt"
        try(Scanner input = new Scanner(Paths.get("oldmast.txt"))) {
            while (input.hasNext()) {
                accountNumbers.add(input.nextInt());
                firstNames.add(input.next());
                lastNames.add(input.next());
                balances.add(input.nextDouble());
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
    public ArrayList<String> getFirstNames() {return firstNames;}
    public ArrayList<String> getLastNames() {return lastNames;}
    public ArrayList<Double> getBalances() {return balances;}

    //------------------------------------
    // Setters
    //------------------------------------
    public void setAccountNumbers(ArrayList<Integer> accountNumbers) {
        this.accountNumbers = accountNumbers;
        save();
    }

    public void setFirstNames(ArrayList<String> firstNames) {
        this.firstNames = firstNames;
        save();
    }

    public void setLastNames(ArrayList<String> lastNames) {
        this.lastNames = lastNames;
        save();
    }

    public void setBalances(ArrayList<Double> balances) {
        this.balances = balances;
        save();
    }

    public void save() {

        // Initializing length for the loop below.
        // This assumes the length of accountNumbers
        // is the same as every array's.
        int length = accountNumbers.size();

        // --------------------------------------
        // Create "newmast.txt"
        // --------------------------------------
        try (Formatter output = new Formatter("newmast.txt")) {

            // Iterate through every element in the arrays
            // and write to the file.
            for (int count = 0; count < length; count++) {

                // "oldmast.txt" output example:
                // 1001 Person 1 1000000.00
                // 1002 Person 2 1000000.00
                output.format(
                    "%d %s %s %.2f %s",
                    accountNumbers.get(count),
                    firstNames.get(count),
                    lastNames.get(count),
                    balances.get(count),
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

    //------------------------------------
    // A method for combining
    // "oldmast.txt" with "trans.txt"
    // and then saving to "newmast.txt"
    //------------------------------------
    public void combine(TransactionRecord transTXT) {

        // Read values from "trans.txt"
        ArrayList<Integer> transNumbers = transTXT.getAccountNumbers();
        ArrayList<Double> transactionAmounts = transTXT.getTransactionAmounts();

        //------------------------------------
        // Compare each element of
        // accountNumbers of "trans.txt"
        // with those of "oldmast.txt"
        //------------------------------------
        int length = transNumbers.size();
        for (int index = 0; index < length; index++) {

            // If they match, add the transaction amount
            // to the account's balance.
            if (accountNumbers.contains(transNumbers.get(index))) {
                double newValue = balances.get(index);
                newValue += transactionAmounts.get(index);
                balances.set(index, newValue);
            }

            // If they don't match, add to "log.txt"
            else {

                // Uncomment to debug.
                System.out.printf(
                    "%d %d %f %n",
                    index,
                    transNumbers.get(0),
                    transactionAmounts.get(index)
                );

                log(transNumbers.get(index));

            }

        }

        // Save the results to "newmast.txt"
        save();

    }

    //------------------------------------
    // A method for logging
    // "Unmatched transaction record for
    // account number ..." on "log.txt"
    //------------------------------------
    public void log(int accountNumber) {

        // --------------------------------------
        // Create "log.txt"
        // --------------------------------------

        // The reason why I'm using FileWrite is because
        // (..., true) option allows you to append
        // instead of creating a new file every time.
        try (FileWriter format = new FileWriter("log.txt", true)) {

            Formatter output = new Formatter(format);

            // "log.txt" output example:
            // Unmatched transaction record for account number 1011
            // Unmatched transaction record for account number 1012
            output.format(
                "%s %d %s",
                "Unmatched transaction record for account number",
                accountNumber,
                System.getProperty("line.separator")
            );
        }

        // Exception handling for writing the file.
        catch (
            IOException |
            NoSuchElementException |
            IllegalStateException e
        ) {
            e.printStackTrace();
        }

    }

}


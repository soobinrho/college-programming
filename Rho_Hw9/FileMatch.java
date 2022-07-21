// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.ArrayList;

public class FileMatch {
    /*
     * Exercise 15.4
     * This class is in charge of
     * comparing "oldmast.txt" with "trans.txt"
     * and then making necessary changes to
     * these files, including "newmast.txt"
     * by using methods from
     * the class AccountRecord and
     * the class TransactionRecord.
    */

    public static void updateMaster() {

        // ----------------------------------------
        // Read "oldmast.txt"
        // ----------------------------------------
        AccountRecord mastTXT = new AccountRecord();
        ArrayList<Integer> mastNumbers = mastTXT.getAccountNumbers();
        ArrayList<String> firstNames = mastTXT.getFirstNames();
        ArrayList<String> lastNames = mastTXT.getLastNames();
        ArrayList<Double> balances = mastTXT.getBalances();

        // ----------------------------------------
        // Read "trans.txt"
        // ----------------------------------------
        TransactionRecord transTXT = new TransactionRecord();

        // ------------------------------------------
        // Combine "oldmast.txt" with "trans.txt"
        // and then save the results to "newmast.txt"
        // ------------------------------------------
        mastTXT.combine(transTXT);

    }

}


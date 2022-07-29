// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.ArrayList;

public class FileMatchTest {
    /*
     * Exercise 15.4
     * This is the user interface
     * for every class created for this exercise.
    */
    public static void main(String[] args) {

        // --------------------------------------------------
        // 1. Generate sample data "trans.txt" and "oldmast.txt"
        // by using the class CreateData.
        // --------------------------------------------------
        CreateData.create();

        // --------------------------------------------------
        // 2. Update.
        // This method combines "trans.txt" and "oldmast.txt"
        // and then saves the results to "newmast.txt"
        // Also, any unmatched account number is
        // logged to "log.txt"
        // --------------------------------------------------
        FileMatch.updateMaster();

    }

}


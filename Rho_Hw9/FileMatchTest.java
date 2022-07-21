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

        // ----------------------------------------
        // Generate sample data "trans.txt" and "oldmast.txt"
        // by using the class CreateData.
        // ----------------------------------------
        CreateData.create();

        // ----------------------------------------
        // Update.
        // ----------------------------------------
        FileMatch.updateMaster();

    }

}


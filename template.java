// Soobin Rho
// Problem 3.21 | Public RhoLargest
// July 7, 2022
import java.util.Scanner;

public class RhoLargest {
    /*
     * 1.
     * 2.
     * 3.
    */
    public static void main(String[] args) {

        // 1.
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter the first integer: ");
        int input_1 = userInput.nextInt();
        System.out.print("Enter the second integer: ");
        int input_2 = userInput.nextInt();

        // 2.
        if (input_1 != input_2) {
             System.out.printf(
                 "\"%d is larger.\"%n",
                 input_1
             );
        }

        // 3.

    } // End of method main
} // End of class RhoCompare


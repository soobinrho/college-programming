// Soobin Rho
// Problem 2.15 | Public RhoArithmetic
// July 7, 2022
import java.util.Scanner;

public class RhoArithmetic {
    /*
     * 1. Prompt the user to enter two integers.
     * 2. Print their sum.
     * 3. Print their product.
     * 4. Print their difference.
     * 5. Print their quotient.
    */
    public static void main(String[] args) {

        // 1. Prompt the user to enter two integers.
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter the first integer: ");
        int input_1 = userInput.nextInt();
        System.out.print("Enter the second integer: ");
        int input_2 = userInput.nextInt();

        // 2. Print their sum.
        System.out.printf(
            "%nSum = %d",
            (input_1 + input_2)
        );

        // 3. Print their product.
        System.out.printf(
            "%nProduct = %d",
            (input_1 * input_2)
        );

        // 4. Print their difference.
        System.out.printf(
            "%nDifference = %d",
            (input_1 - input_2)
        );

        // 5. Print their quotient.
        System.out.printf(
            "%nQuotient = %d",
            (input_1 / input_2)
        );

    } // End of method main
} // End of class RhoArithmetic


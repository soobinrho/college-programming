// Soobin Rho
// Problem 2.16 | Public RhoCompare
// July 7, 2022
import java.util.Scanner;

public class RhoCompare {
    /*
     * 1. Prompt the user to enter two integers.
     * 2. If the numbers are not equal to each other,
     *    print \"is larger\".
     * 3. If the numbers are equal to each other,
     *    print \"These numbers are equal\".
    */
    public static void main(String[] args) {

        // 1. Prompt the user to enter two integers.
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter the first integer: ");
        int input_1 = userInput.nextInt();
        System.out.print("Enter the second integer: ");
        int input_2 = userInput.nextInt();

        // 2. If the numbers are not equal to each other,
        //    print \"is larger\".
        if (input_1 != input_2) {
            if (input_1 > input_2) {
                System.out.printf(
                    "%n\"%d is larger.\"%n",
                    input_1
                );
            }
            else {
                System.out.printf(
                    "%n\"%d is larger.\"%n",
                    input_2
                );
            }
        }

        // 3. If the numbers are equal to each other,
        //    print \"These numbers are equal\".
        else {
            System.out.println(
                "%n\"These numbers are equal.\""
            );
        }

    } // End of method main
} // End of class RhoCompare


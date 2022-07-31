// Soobin Rho
// Problem 5.21 | Public RhoDigits
// July 11, 2022
import java.util.Scanner;

public class RhoDigits {
    /*
     * (a) Calculate the integer part
     *     of a quotient.
     * (b) Calculate the remainder part
     *     of a quotient.
     * (c) Use (a) and (b). Receive
     *     an integer between 1 and 99999 and
     *     display it as a sequence of digits.
    */
    public static void main(String[] args) {

        // Initialize variables for
        // getting user input.
        Scanner userInput = new Scanner(System.in);
        boolean isValid = false;
        int input_1 = 0;
        int input_2 = 0;
        while (isValid == false) {

            // Prompt the user to input integers.
            System.out.print("Enter the first integer: ");
            input_1 = userInput.nextInt();
            System.out.print("Enter the second integer: ");
            input_2 = userInput.nextInt();

            // Check if the inputs are between the range.
            if (input_1 > 0 && input_1 < 100000) {
                if (input_2 > 0 && input_2 < 100000) {
                    isValid = true;
                }
                else {
                    System.out.println("Second value is invalid.");
                }
            }
            else {
                System.out.println("First value is invalid.");
            }

        }

        // Print a new line for readability.
        System.out.println();

    } // End of method main

    // (a) Calculate the integer part
    //     of a quotient.
    public static int getQuotient(int a, int b) {

        int quotient = a / b;
        return quotient;

    }

    // (b) Calculate the remainder part
    //     of a quotient.
    public static int getRemainder(int a, int b) {

        int remainder = a % b;
        return remainder;

    }

   // (c) Use (a) and (b). Receive
   //     an integer between 1 and 99999 and
   //     display it as a sequence of digits.
    public static void displayDigits(int a, int b) {

        int quotient = getQuotient(a, b);
        int remainder = getRemainder(a, b);

        while (remainder != 0) {

            System.out.printf(
                "%d  ",
                quotient
            );
            quotient = getQuotient(a, b);


        }

    }







} // End of class RhoDigits


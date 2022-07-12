// Soobin Rho
// Problem 5.21 | Public RhoDigits
// July 11, 2022
import java.util.Scanner;

public class RhoDigits {
    /*
     * (a) A method calculating the integer part
     *     of a quotient.
     * (b) A method calculating the remainder part
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
        int input = 0;
        while (isValid == false) {

            // Prompt the user to input an integer.
            System.out.print("Enter an integer: ");
            input = userInput.nextInt();

            // Check if the input is between the range.
            if (input > 0 && input < 100000) {
                isValid = true;
            }
            else {
                System.out.println("Input invalid.");
            }

        }

        // Print a new line for readability.
        System.out.println();

        // Call method (c).
        displayDigits(input);

    } // End of method main

    // (a) A method calculating the integer part
    //     of a quotient.
    public static int getQuotient(int a, int b) {

        int quotient = a / b;
        return quotient;

    }

    // (b) A method calculating the remainder part
    //     of a quotient.
    public static int getRemainder(int a, int b) {

        int remainder = a % b;
        return remainder;

    }

   // (c) Use (a) and (b). Receive
   //     an integer between 1 and 99999 and
   //     display it as a sequence of digits.
    public static void displayDigits(int input) {

        // Determine the lnegth of the digit.
        int length = (Integer.toString(input)).length();

        // input will be divided by power
        // for example, if the input is 345,
        // (int) 345 / 100 = 3
        int power = (int) Math.pow(10, length - 1);

        // Loop until the quotient is 0
        int quotient = getQuotient(input, power);
        int remainder = getRemainder(input, power);

        for (int count = 0; count < length - 1; count++) {

            System.out.printf(
                "%d  ",
                quotient
            );

            power /= 10;
            quotient = getQuotient(remainder, power);
            remainder = getRemainder(remainder, power);

        }

        // Print the last digit.
        System.out.println("" + quotient);

    }

} // End of class RhoDigits


// Soobin Rho
// Problem 5.23 | Public RhoMin3
// July 11, 2022
import java.util.Scanner;

public class RhoMin3 {
    /*
     * 1. Prompt the user for three floats.
     * 2. Display the minimum.
     * 3. A method for returning the minimum.
    */
    public static void main(String[] args) {

        // 1. Prompt the user for three floats.
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter the first float: ");
        float input_1 = userInput.nextFloat();
        System.out.print("Enter the second float: ");
        float input_2 = userInput.nextFloat();
        System.out.print("Enter the third float: ");
        float input_3 = userInput.nextFloat();

        // Print a newline for readability.
        System.out.println();

        // 2. Display the minimum.
        float minimum = getMinimum(input_1, input_2, input_3);
        System.out.println("The minimum is " + minimum);

    } // End of method main

    // 3. A method for returning the minimum.
    public static float getMinimum(
        float input_1,
        float input_2,
        float input_3
    ) {
        return Math.min(
            input_1,
            Math.min(input_2, input_3)
        );
    }

} // End of class RhoMin3


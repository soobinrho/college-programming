// COSC 211
// Soobin Rho
// July 21, 2022
import java.util.Scanner;

public class RhoTokenTest {
    /*
     * Exercise 14.9
     * Prompt for user input,
     * split, and print in reverse.
    */

    public static void main(String[] args) {

        // Prompt for user input.
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String input = userInput.nextLine();

        // Print a newline for readability.
        System.out.println();

        // Split.
        String[] output = input.split(" ");

        // Print in reverse.
        for(int index = output.length - 1; index >= 0 ; index--) {
            System.out.printf("%s ", output[index]);
        }

    }

}


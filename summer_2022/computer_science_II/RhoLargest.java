// Soobin Rho
// Problem 3.21 | Public RhoLargest
// July 10, 2022
import java.util.Scanner;

public class RhoLargest {
    /*
     * 1. Prompt the user to enter 10 integers.
     *    loop until `count` reaches 10.
     * 2. Store the input as `number`.
     * 3. If the new input is larger than
     *    `largest`, assign that as the new value.
    */
    public static void main(String[] args) {

        // 1. Prompt the user to enter 10 integers.
        //    loop until `count` reaches 10.
        Scanner userInput = new Scanner(System.in);
        int count = 0;
        int largest = -999999999;
        while (count < 10) {

            // Prompt the user.
            System.out.printf(
                "Enter integer %d: ",
                count + 1
            );

            // 2. Store the input as `number`.
            int number = userInput.nextInt();

            // 3. If the nuew input is larger than
            //    `largest`, assign that as the new value.
            if (number > largest) {
                largest = number;
            }

            ++count;

        }

        System.out.printf(
            "%nThe largest number is %d",
            largest
        );

    } // End of method main
} // End of class RhoLargest


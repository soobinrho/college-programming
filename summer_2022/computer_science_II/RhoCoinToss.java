// Soobin Rho
// Problem 5.29 | Public RhoDigits
// July 11, 2022
import java.util.Scanner;
import java.util.Random;

public class RhoCoinToss {
    /*
     * 1. The menu has two options.
     *    (t)oss coin or (q)uit
     * 2. Flip the coin and display the result.
     * 3. The method `flip` randomly
     *    selects head or tail.
    */
    public static void main(String[] args) {

        // 1. The menu has two options.
        //    (t)oss coin or (q)uit
        Scanner userInput = new Scanner(System.in);
        String menu = " ";
        while (!menu.equals("q")) {

            // Prompt the user.
            System.out.print("(t)oss coin or (q)uit: ");
            menu = userInput.nextLine();

            if (menu.equals("t")) {

                // 2. Flip the coin and display the result.
                int result = flip();
                switch (result) {
                    case 0:
                        System.out.println("Heads");
                        break;
                    case 1:
                        System.out.println("Tails");
                }

            }
        }

    } // End of method main

    // 3. The method `flip` randomly
    //    selects head or tail.
    public static int flip() {

        Random randomValue = new Random();
        int result = randomValue.nextInt(2);
        return result;

    }

} // End of class RhoCoinToss


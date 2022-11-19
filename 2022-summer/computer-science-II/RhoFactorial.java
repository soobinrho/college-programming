// Soobin Rho
// Problem 4.13 | Public RhoFactorial
// July 10, 2022

public class RhoFactorial {
    /*
     * 1. Loop for 20 times with the type long.
     * 2. Multiply the previous number with
     *    the next number.
     * 3. Display the results in tabular format.
    */
    public static void main(String[] args) {

        // 1. Loop for 20 times with the type long.
        long number = 1;
        for (long count = 1; count < 21; count++) {

            // 2. Multiply the previous number with
            //    the next number.
            number *= count;

            // 3. Display the results in tabular format.
            System.out.printf(
                "%d! = %d%n",
                count,
                number
            );

        }

        //
        // Question: "What difficulty might prevent you
        // from calculating the factorial of 100?"
        //
        // Answer: The max value of long is less than 100!
        //

    } // End of method main
} // End of class RhoFactoral


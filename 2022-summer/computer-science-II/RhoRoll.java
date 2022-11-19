// Soobin Rho
// Problem 6.17 | Public RhoRoll
// July 14, 2022
import java.util.Scanner;
import java.util.Random;

public class RhoRoll {
    /*
     * 1. Roll the dice twice using Random.
     * 2. Calculate the sum of these two.
     * 3. Print in a tabular format.
    */
    public static void main(String[] args) {

        // Initialize an array for
        // storing the results.
        int TIMES = 36000000;
        int[] results = new int[TIMES];

        // 1. Roll the dice twice using Random.
        // 2. Calculate the sum of these two.
        for (int count = 0; count < TIMES; count++) {
            results[count] = getRandomDiceSum();
        }

        // Categorize the results into
        // the range of each sum.
        int[] rangeCount = new int[11];
        for (int count = 0; count < TIMES; count++) {

            // The sum of two dice rolls
            // have the possible range of
            // 2 to 12.
            int valueSum = results[count] - 2;
            rangeCount[valueSum]++;

        }

        // 3. Print in a tabular format.
        for (int count = 0; count < rangeCount.length; count++) {
            System.out.printf(
                "Sum %2d: %,d %n",
                count + 2,
                rangeCount[count]
            );
        }

    }

    public static int getRandomDiceSum() {

        // Roll the dice twice.
        Random randomValue = new Random();
        int num1 = randomValue.nextInt(6) + 1;
        int num2 = randomValue.nextInt(6) + 1;

        // Calculate the sum.
        int sum = num1 + num2;

        // Uncomment for debugging.
        // System.out.printf(
        //     "num1: " + num1 +
        //     " num2: " + num2 +
        //     " sum: " + sum +
        //     "%n"
        // );

        return sum;

    }


}


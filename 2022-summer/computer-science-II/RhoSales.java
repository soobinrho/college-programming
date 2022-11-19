// Soobin Rho
// Problem 6.10 | Public RhoSales
// July 14, 2022
import java.util.Scanner;

public class RhoSales {
    /*
     * 1. Prompt for the number of salespeople.
     * 2. Prompt for each person's gross sales
     *    for the week.
     * 3. Calculate BASEPAY + (0.09 * grossSales)
     *    of each person.
     * 4. Print the array in a tabular format.
    */
    public static void main(String[] args) {

        //  1. Prompt for the number of salespeople.
        Scanner userInput = new Scanner(System.in);
        System.out.print("Enter the number of salespeople: ");
        int length = userInput.nextInt();

        // Create an array with the length.
        double[] sales = new double[length];

        // Initialize BASEPAY.
        double BASEPAY = 200.0;

        // Initialize maxSales.
        // This is for printing the array
        // in a nice format.
        double maxSales = 0;

        //  2. Prompt for each person's gross sales
        //     for the week.
        for (int count = 0; count < sales.length; count++) {

            System.out.printf(
                "Employee %d gross sales: ",
                count + 1
            );
            int grossSales = userInput.nextInt();

            //  3. Calculate BASEPAY + (0.09 * grossSales)
            //     of each person.
            sales[count] = BASEPAY + (0.09 * grossSales);
            if (sales[count] > maxSales) {
                maxSales = sales[count];
            }

        }

        // Print a newline for readability.
        System.out.println();

        // Categorize each salesperson into
        // the range of grossSales.
        int[] rangeCount = new int[9];
        for (int count = 0; count < 8; count++) {

            int rangeStart = (count + 1) * 100 + 100;
            int rangeEnd = (count + 1) * 100 + 199;

            for (int coun = 0; coun < sales.length; coun++) {

                // Uncomment for debugging.
                // System.out.println(
                //     "sale: " + sales[coun] +
                //     " rangeStart: " + rangeStart +
                //     " rangeEnd: " + rangeEnd
                // );

                if (
                    (sales[coun] >= rangeStart) &&
                    (sales[coun] < rangeEnd)
                ) {
                    rangeCount[count]++;
                }

            }

            // 4. Print the array in a tabular format.
            System.out.printf(
                "$%d-%d: %d%n",
                rangeStart,
                rangeEnd,
                rangeCount[count]
            );

        }

        // Print the last value of the array.
        // which is $1,000 or over.
        //
        // I could've included this section
        // on the for loop above, but
        // that would require me to use
        // an if statement just for the last value.
        // So, I opted to just make a seperate
        // loop for the last value of the array.
        //
        for (int coun = 0; coun < sales.length; coun++) {

             if (sales[coun] >= 1000) {
                 rangeCount[8]++;
             }

        }

        System.out.printf(
            "$1,000 and over: %d%n",
            rangeCount[8]
        );

    }
}


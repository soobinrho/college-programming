// Soobin Rho
// Problem 5.22 | Public RhoDigits
// July 11, 2022
import java.util.Scanner;

public class RhoTemps {
    /*
     * (a) A method returning the Celcius
     *     equivalent of a Fahrenheit.
     * (b) A method returning the Fahrenheit
     *     equivalent of a Celcius.
     * (c) An application where the user can
     *     convert one to the other.
    */
    public static void main(String[] args) {

        // (c) An application where the user can
        //     convert one to the other.
        Scanner userInput = new Scanner(System.in);
        System.out.print(
            "Convert to (f)ahrenheit or to (c)elcius: "
        );
        String menu = userInput.nextLine();

        // Convert to Celcius.
        if (menu.equals("c")) {

            System.out.print("Enter: ");
            double input = userInput.nextDouble();
            double celcius = toCelcius(input);
            System.out.printf(
                "%.1fF = %.1fC",
                input,
                celcius
            );
        }

        // Convert to Fahrenheit.
        else if (menu.equals("f")) {

            System.out.print("Enter: ");
            double input = userInput.nextDouble();
            double fahrenheit = toFahrenheit(input);
            System.out.printf(
                "%.1fC = %.1fF",
                input,
                fahrenheit
            );
        }

    } // End of method main

    // (a) A method returning the Celcius
    //     equivalent of a Fahrenheit.
    public static double toCelcius(double input) {

        double celcius = 5.0 / 9.0 * (input - 32.0);
        return celcius;

    }

    // (b) A method returning the Fahrenheit
    //     equivalent of a Celcius.
    public static double toFahrenheit(double input) {

        double fahrenheit = 9.0 / 5.0 * input + 32.0;
        return fahrenheit;

    }

} // End of class RhoTemps


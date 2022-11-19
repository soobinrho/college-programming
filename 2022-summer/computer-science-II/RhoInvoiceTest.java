// COSC 211
// Soobin Rho
// July 18, 2022
import java.util.Scanner;

public class RhoInvoiceTest {
    /*
     * Testing RhoInvoice class.
    */

    public static void main(String[] args) {

        // ----------------------------------------
        // The exercise requires the program
        // to have the following features:
        //
        // 1. Has the following four variables,
        //    has a constructor for them, and
        //    has a getter / setter for them:
        //
        //        String number;
        //        String description;
        //        int quantitySold;
        //        double pricePerItem;
        //
        // 2. A method that calculates the
        //    invoice amount.
        //
        // 3. quantitySold is set to 0 if it was
        //    set to be a non-positive number.
        //
        // 4. pricePerItem is set to 0 if it was
        //    set to be a non-positive number.
        //
        // ----------------------------------------

        // 1. Has the four instance variables,
        //    has a constructor for them, and
        //    has a getter / setter for them:
        RhoInvoice invoice1 = new RhoInvoice(
            "23",
            "A multi-purpose hammer.",
            1,
            130.5
        );
        System.out.printf("%s%n%n", invoice1);

        // 2. A method that calculates the
        //    invoice amount.
        double amount = invoice1.getInvoiceAmount();
        System.out.printf("Total amount = %s%n%n", amount);

        // 3. quantitySold is set to 0 if it was
        //    set to be a non-positive number.
        RhoInvoice invoice_invalid_quantity = new RhoInvoice(
            "24",
            "Another multi-purpose hammer.",
            -100000000,
            120.5
        );
        System.out.printf("%s%n%n", invoice_invalid_quantity);

        // 4. pricePerItem is set to 0 if it was
        //    set to be a non-positive number.
        RhoInvoice invoice_invalid_price = new RhoInvoice(
            "24",
            "Another multi-purpose hammer.",
            1,
            -100000000
        );
        System.out.printf("%s%n%n", invoice_invalid_price);

    }

}


// COSC 211
// Soobin Rho
// July 18, 2022
import java.util.Scanner;

public class RhoInvoice {
    /*
     * A class for a hardware store's invoices.
    */

    // Initialize instance variables.
    String number;
    String description;
    int quantitySold;
    double pricePerItem;

    public RhoInvoice(String number,
                      String description,
                      int quantitySold,
                      double pricePerItem) {

        this.number = number;
        this.description = description;

        // quantitySold should be a positive number.
        if (quantitySold > 0) {
            this.quantitySold = quantitySold;
        }

        // If quantitySold is not a positive number,
        // set it to 0.
        else {
            System.out.println(
                "Invalid input: Quantity sold is set to 0."
            );
            this.quantitySold = 0;
        }

        // pricePerItem should be a positive number.
        if (pricePerItem > 0) {
            this.pricePerItem = pricePerItem;
        }

        // If pricePerItem is not a positive number,
        // set it to 0.
        else {
            System.out.println(
                "Invalid input: Price per item is set to 0."
            );
            this.pricePerItem = 0.0;
        }

    }

    // ----------------------------------
    // partNumber getter and setter
    // ----------------------------------
    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    // ----------------------------------
    // partDescription getter and setter
    // ----------------------------------
    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    // ----------------------------------
    // quantitySold getter and setter
    // ----------------------------------
    public int getQuantitySold() {
        return quantitySold;
    }

    public void setQuantitySold(int quantitySold) {

        // quantitySold should be a positive number.
        if (quantitySold > 0) {
            this.quantitySold = quantitySold;
        }

        // If quantitySold is not a positive number,
        // set it to 0.
        else {
            System.out.println(
                "Invalid input: Quantity sold is set to 0."
            );
            this.quantitySold = 0;
        }

    }

    // ----------------------------------
    // pricePerItem getter and setter
    // ----------------------------------
    public double getPricePerItem() {
        return pricePerItem;
    }

    public void setPricePerItem(double pricePerItem) {

        // pricePerItem should be a positive number.
        if (pricePerItem > 0) {
            this.pricePerItem = pricePerItem;
        }

        // If pricePerItem is not a positive number,
        // set it to 0.
        else {
            System.out.println(
                "Invalid input: Price per item is set to 0."
            );
            this.pricePerItem = 0.0;
        }

    }

    // ----------------------------------
    // Additional Instance Methods
    // ----------------------------------
    public double getInvoiceAmount() {
        double invoiceAmount = quantitySold * pricePerItem;
        return invoiceAmount;
    }

    public String toString() {
        String output = String.format(
            "Part number: %s%n" +
            "Part description: %s%n" +
            "Quantity sold: %d%n" +
            "Price per item: $%,.2f",
            number,
            description,
            quantitySold,
            pricePerItem
        );
        return output;
    }

}


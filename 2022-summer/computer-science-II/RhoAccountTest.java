// COSC 211
// Soobin Rho
// July 18, 2022
import java.util.Scanner;

public class RhoAccountTest {
    /*
     * Testing the class RhoAccount.
    */

    public static void main(String[] args) {

        // Construct an object of RhoAccount.
        RhoAccount account = new RhoAccount(
            "Soobin Rho",
            130.2
        );

        // Try to withdraw more than I have.
        // This should print an error message.
        account.withdraw(150);

        // Withdraw a valid amount.
        account.withdraw(130.2);

        // Print how much I have now.
        System.out.printf(
            "Balance: $%,.2f",
            account.getBalance()
        );

    }

}


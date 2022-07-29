// COSC 211
// Soobin Rho
// July 18, 2022
import java.util.Scanner;

public class RhoAccount {
    /*
     * A class for a bank account.
    */
    private String name;
    private double balance;

    // Constructor takes in the account's
    // name and balance.
    public RhoAccount(String name, double balance) {

        this.name = name;

        // Validate balance.
        // It shouldn't be negative.
        if (balance > 0) {
            this.balance = balance;
        }
        else {
            System.out.println("Invalid balance.");
        }

    }

    // ---------------------------------
    // name getter and setter
    // ---------------------------------
    public String getName() {
        return name;
    }

    public void setName() {
        this.name = name;
    }

    // ---------------------------------
    // balance getter
    // ---------------------------------
    public double getBalance() {
        return balance;
    }

    // ---------------------------------
    // Object's Additional Methods
    // ---------------------------------
    public void deposit(double amount) {

        // Print the deposit request.
        System.out.printf(
            "Depositing $%,.2f ...%n",
            amount
        );

        // Validate amount.
        // It shouldn't be negative.
        if (amount > 0.0) {
            balance += amount;
            System.out.printf("Deposit complete.%n%n");
        }
        else {
            System.out.printf("Invalid amount.%n%n");
        }

    }

    public void withdraw(double amount) {

        // Print the withdraw request.
        System.out.printf(
            "Withdrawing $%,.2f ...%n",
            amount
        );

        // Validate amount.
        // It shouldn't be greater than balance.
        if (amount <= balance) {
            balance -= amount;
            System.out.printf("Withdraw complete.%n%n");
        }
        else {
            System.out.printf(
                "Withdrawal amount exceeded account balance.%n%n"
            );
        }

    }

}


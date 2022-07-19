// COSC 211
// Soobin Rho
// July 19, 2022
import java.util.Scanner;

public class RhoDate {
    /*
     * A class for dates.
     * This is based on Fig 8.7
     * as instructed by Exercise 8.8
    */

    private int month;
    private int day;
    private int year;
    private static final int[] daysPerMonth =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // -------------------------------
    // Constructor
    // -------------------------------
    public RhoDate(int month, int day, int year) {

        if (month <= 0 || month > 12) {
            throw new IllegalArgumentException("Invalid month.");
        }

        if (day <= 0 ||
            day > daysPerMonth[month] &&
            !(month == 2 && day == 29)) {
            throw new IllegalArgumentException("Invalid day.");
        }

        if (year <= 0) {
            throw new IllegalArgumentException("Invalid year.");
        }

        // Checking for leap years.
        if (month == 2 &&
            day == 29 &&
            !(
                year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0)
            )) {
            throw new IllegalArgumentException("Invalid date.");
        }

        this.month = month;
        this.day = day;
        this.year = year;

        System.out.printf("%nInstance created: %s%n%n", this);

    }

    // -------------------------------
    // toString Method
    // -------------------------------
    public String toString() {
        String output = String.format(
            "%d/%d/%d",
            month,
            day,
            year
        );
        return output;
    }

    // -------------------------------
    // A method for incrementing a day
    // -------------------------------
    public void nextDay() {

        // -----------------------------
        // Two possible cases:
        // 1. No overflow. Add as usual.
        // 2. Overflow. Add the higher up.
        // -----------------------------

        // 1. No overflow. Add as usual.
        if (day != daysPerMonth[month]) {day++;}

        // 2. Overflow. Add the higher up.
        else {
            nextMonth();
            day = 1;
        }

    }

    public void nextMonth() {

        // -----------------------------
        // Two possible cases:
        // 1. No overflow. Add as usual.
        // 2. Overflow. Add the higher up.
        // -----------------------------

        // 1. No overflow. Add as usual.
        if (month != 12) {month++;}

        // 2. Overflow. Add the higher up.
        else {
            nextYear();
            month = 1;
        }

    }

    public void nextYear() {year++;}

}


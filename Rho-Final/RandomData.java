// COSC 211
// Soobin Rho
// August 2, 2022
import java.security.SecureRandom;
//import java.util.FormatterClosedException;
//import java.util.NoSuchElementException;
//import java.lang.IllegalStateException;
//import java.io.FileNotFoundException;
//import java.lang.SecurityException;
//import java.util.ArrayList;
//import java.io.IOException;
//import java.nio.file.Files;
//import java.nio.file.Paths;
//import java.util.Formatter;
//import java.nio.file.Path;
//import java.util.Scanner;
//import java.util.Date;
//import java.io.File;

public class RandomData {
    /*
     * This class is in charge of providing
     * static methods for creating random data.
     *
     * This class is used by the classes
     * StudentList, FacultyList, StaffList, and
     * CourseList in order to generate random data.
    */

    // Initialize a SecureRandom object.
    private static final SecureRandom random = new SecureRandom();

    //-------------------------------------------
    // A method for generating a random name.
    //-------------------------------------------
    public static String getRandomName() {

        // A list of random names.
        final String[] RANDOM_NAMES = {
            "Acerola", "Apple", "Apricots",
            "Avocado", "Banana", "Blackberries",
            "Blueberries", "Breadfruit", "Cantaloupe",
            "Carambola", "Cherimoya", "Cherries",
            "Clementine", "Coconut", "Cranberries",
            "Durian", "Elderberries", "Feijoa",
            "Figs", "Gooseberries", "Grapefruit",
            "Grapes", "Guava", "Melon",
            "Jackfruit", "Jujube", "Kiwifruit",
            "Kumquat", "Lemon", "Longan",
            "Loquat", "Mango", "Pomegaranate",
            "Pummeio", "Quince", "Raspberries",
            "Orange", "Strawberries", "Watermelon",
            "Pineapple", "Amazing", "Awesome",
            "Cool", "Nice", "Salt",
            "Happy", "Happiest", "Wonderful",
            "Beautiful", "Kind", "Pepper",
            "Chicken", "Bean", "Soup",
            "Green", "Sweet", "Sour",
            "Spicy", "Lukewarm", "Hot",
            "Muscular", "Pink", "Violet",
            "Red", "Black", "White",
            "Caramel", "Mocha", "Pastries",
            "Gigantic", "Massive", "Huge",
            "Chocolate", "Viking", "Pickles"
        };

        // Get a random number.
        int randomNamesLength = RANDOM_NAMES.length;
        int randomNumber = random.nextInt(randomNamesLength);

        // Pick a random name.
        String randomName = RANDOM_NAMES[randomNumber];
        return randomName;

    }

    //-------------------------------------------
    // A method for generating a random address.
    //-------------------------------------------
    public static String getRandomAddress() {

        // Get a number between 1,000 and 9,999.
        int streetNumber = 1000 + random.nextInt(9000);

        // Get a number between 10,000 and 99,999.
        int zipNumber = 10000 + random.nextInt(90000);

        // Make a random address.
        String randomAddress = String.format(
            "%d S %s ST %d",
            streetNumber,
            getRandomName().toUpperCase(),
            zipNumber
        );
        return randomAddress;

    }

    //-------------------------------------------
    // A method for generating a random ssNum.
    //-------------------------------------------
    public static int getRandomSSNum() {

        // Get a number between 100,000,000 and 999,999,999.
        int randomSSNum = 100000000 + random.nextInt(900000000);
        return randomSSNum;

    }

    //-------------------------------------------
    // A method for generating a random ID.
    //-------------------------------------------
    public static int getRandomID() {

        // Get a number between 100,000 and 999,999.
        int randomID = 100000 + random.nextInt(900000);
        return randomID;

    }

    //-------------------------------------------
    // A method for generating a random title.
    //-------------------------------------------
    public static String getRandomTitle() {

        // Pick a random title.
        String randomTitle = String.format(
            "%s Wizard",
            getRandomName()
        );
        return randomTitle;

    }

    //-------------------------------------------
    // A method for generating a random dept.
    //-------------------------------------------
    public static String getRandomDept() {

        // A list of random names.
        final String[] RANDOM_DEPTS = {
            "WIZA", "WITC", "ENHA",
            "ALCH", "SPRI", "DIVI"
        };

        // Get a random number.
        int randomDeptsLength = RANDOM_DEPTS.length;
        int randomNumber = random.nextInt(randomDeptsLength);

        // Pick a random dept.
        String randomDept = RANDOM_DEPTS[randomNumber];
        return randomDept;

    }

    //-------------------------------------------
    // A method for generating a random salary.
    //-------------------------------------------
    public static int getRandomSalary() {

        // Get a number between 30,000 and 10,000,000.
        int randomSalary = 30000 + random.nextInt(9969999);
        return randomSalary;

    }

}


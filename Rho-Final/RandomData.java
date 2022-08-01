// COSC 211
// Soobin Rho
// August 2, 2022
import java.security.SecureRandom;
import java.util.Date;

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
    public static String getName() {

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
    public static String getAddress() {

        // Get a number between 1,000 and 9,999.
        int streetNumber = 1000 + random.nextInt(9000);

        // Get a number between 10,000 and 99,999.
        int zipNumber = 10000 + random.nextInt(90000);

        // Make a random address.
        String randomAddress = String.format(
            "%d S %s ST %d",
            streetNumber,
            getName().toUpperCase(),
            zipNumber
        );
        return randomAddress;

    }

    //-------------------------------------------
    // A method for generating a random ssNum.
    //-------------------------------------------
    public static int getSSNum() {

        // Get a number between 100,000,000 and 999,999,999.
        int randomSSNum = 100000000 + random.nextInt(900000000);
        return randomSSNum;

    }

    //--------------------------------------------
    // A method for generating a random birthDate.
    //--------------------------------------------
    public static Date getBirthDate() {

        // Get a number between 1990 and 2022.
        int randomYear = 1990 + random.nextInt(33);

        // Get a number between 1 and 12.
        int randomMonth = 1 + random.nextInt(12);

        // Get a number between 1 and 28.
        int randomDay = 1 + random.nextInt(28);

        // Combine the year, month, and day.
        Date randomBirthDate = new Date(randomYear, randomMonth, randomDay);
        return randomBirthDate;

    }

    //-------------------------------------------
    // A method for generating a random ID.
    //-------------------------------------------
    public static int getID() {

        // Get a number between 100,000 and 999,999.
        int randomID = 100000 + random.nextInt(900000);
        return randomID;

    }

    //---------------------------------------------------
    // A method for generating a random studentStartDate.
    //---------------------------------------------------
    public static Date getStudentStartDate(Date birthDate) {

        // Extract the year, month, and day from birthDate.
        int randomYear = birthDate.getYear();
        int randomMonth = birthDate.getMonth();
        int randomDay = birthDate.getDay();

        // Add 18 years to randomYear.
        randomYear += 18;

        // Combine the year, month, and day.
        Date randomStartDate = new Date(randomYear, randomMonth, randomDay);
        return randomStartDate;

    }

    //---------------------------------------------------
    // A method for generating a random facultyStartDate.
    //---------------------------------------------------
    public static Date getFacultyStartDate(Date birthDate) {

        // Extract the year, month, and day from birthDate.
        int randomYear = birthDate.getYear();
        int randomMonth = birthDate.getMonth();
        int randomDay = birthDate.getDay();

        // Add 34 years to randomYear.
        randomYear += 34;

        // Combine the year, month, and day.
        Date randomStartDate = new Date(randomYear, randomMonth, randomDay);
        return randomStartDate;

    }

    //---------------------------------------------------
    // A method for generating a random expGradDate.
    //---------------------------------------------------
    public static Date getExpGradDate(Date startDate) {

        // Extract the year, month, and day from birthDate.
        int randomYear = startDate.getYear();
        int randomMonth = startDate.getMonth();
        int randomDay = startDate.getDay();

        // Add 4 years to randomYear.
        randomYear += 4;

        // Combine the year, month, and day.
        Date randomExpGradDate = new Date(randomYear, randomMonth, randomDay);
        return randomExpGradDate;

    }

    //-------------------------------------------
    // A method for generating a random crTaken.
    //-------------------------------------------
    public static int getCrTaken() {

        // Get a number between 0 and 130.
        int randomCrTaken = random.nextInt(131);
        return randomCrTaken;

    }

    //-------------------------------------------
    // A method for generating a random crPassed.
    //-------------------------------------------
    public static int getCrPassed(int randomCrTaken) {

        // For 70% chance, crPassed is the same as
        // crTaken.
        int randomCrPassed = 0;
        int randomProbability = random.nextInt(10);
        if (randomProbability < 7) {randomCrPassed = randomCrTaken;}

        // For 30% Chance, crPassed is a number between
        // 0.5 * randomCrTaken and randomCrTaken.
        else {
            randomCrPassed = (int) Math.round(
                (0.5 * randomCrTaken) +
                random.nextInt(
                    (int) Math.floor(
                        (randomCrTaken + 1) -
                        (0.95 * randomCrTaken)
                    )
                )
            );
        }

        return randomCrPassed;

    }

    //-------------------------------------------
    // A method for generating a random currCr.
    //-------------------------------------------
    public static int getCurrCr() {

        // Get a number between 12 and 16.
        int randomCurrCr = 12 + random.nextInt(5);
        return randomCurrCr;

    }

    //-------------------------------------------
    // A method for generating a random title.
    //-------------------------------------------
    public static String getTitle() {

        // Pick a random title.
        String randomTitle = String.format(
            "%s Wizard",
            getName()
        );
        return randomTitle;

    }

    //-------------------------------------------
    // A method for generating a random dept.
    //-------------------------------------------
    public static String getDept() {

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
    public static int getSalary() {

        // Get a number between 30,000 and 10,000,000.
        int randomSalary = 30000 + random.nextInt(10070001);
        return randomSalary;

    }

}


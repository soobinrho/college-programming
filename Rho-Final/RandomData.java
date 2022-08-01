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
        int randomNumber = random.nextInt(RANDOM_NAMES.length);

        // Pick a random name.
        return RANDOM_NAMES[randomNumber];

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
        return 100000000 + random.nextInt(900000000);

    }

    //--------------------------------------------
    // A method for generating a random birthDate.
    //--------------------------------------------
    public static Date getBirthDate() {

        // Get a number between 1990 and 2002.
        int randomYear = 1990 + random.nextInt(13);

        // Get a number between 1 and 12.
        int randomMonth = 1 + random.nextInt(12);

        // Get a number between 1 and 28.
        int randomDay = 1 + random.nextInt(28);

        // Combine the year, month, and day.
        return new Date(randomYear, randomMonth, randomDay);

    }

    //-------------------------------------------
    // A method for generating a random ID.
    //-------------------------------------------
    public static int getID() {

        // Get a number between 100,000 and 999,999.
        return 100000 + random.nextInt(900000);

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
        return new Date(randomYear, randomMonth, randomDay);

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
        return new Date(randomYear, randomMonth, randomDay);

    }

    //---------------------------------------------------
    // A method for generating a random staffStartDate.
    //---------------------------------------------------
    public static Date getStaffStartDate(Date birthDate) {

        // Extract the year, month, and day from birthDate.
        int randomYear = birthDate.getYear();
        int randomMonth = birthDate.getMonth();
        int randomDay = birthDate.getDay();

        // Add 19 years to randomYear.
        randomYear += 19;

        // Combine the year, month, and day.
        return new Date(randomYear, randomMonth, randomDay);

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
        return new Date(randomYear, randomMonth, randomDay);

    }

    //-------------------------------------------
    // A method for generating a random crTaken.
    //-------------------------------------------
    public static int getCrTaken() {

        // Get a number between 0 and 130.
        return random.nextInt(131);

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
        return 12 + random.nextInt(5);

    }

    //------------------------------------------------
    // A method for generating a random Faculty title.
    //------------------------------------------------
    public static String getFacultyTitle() {

        // Pick a random title.
        String randomTitle = String.format(
            "%s Wizard",
            getName()
        );
        return randomTitle;

    }

    //----------------------------------------------
    // A method for generating a random Staff title.
    //----------------------------------------------
    public static String getStaffTitle() {

        // Pick a random title.
        String randomTitle = String.format(
            "%s Assistant Wizard",
            getName()
        );
        return randomTitle;

    }

    //------------------------------------------------
    // A method for generating a random Course title.
    //------------------------------------------------
    public static String getCourseTitle() {

        // A list of random Course descriptions.
        final String[] RANDOM_COURSE_DESCRIPTIONS = {
            "Introduction to", "Advanced", "Intermediary",
            "On", "Applications of", "Foundations of",
            "History of", "Modern", "Complex",
            "Systematic approach to", "Pre-modern", "Historical"
        };

        // Get a random number.
        int randomNumber = random.nextInt(
            RANDOM_COURSE_DESCRIPTIONS.length
        );

        // Pick a random Course description.
        String description = RANDOM_COURSE_DESCRIPTIONS[randomNumber];

        // Pick a random title.
        String firstWord = getName();
        String secondWord = getName();
        while (firstWord == secondWord) {secondWord = getName();}

        String randomTitle = String.format(
            "%s %s %s",
            description,
            firstWord,
            secondWord
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
            "ALCH", "SPRI", "DIVI",
            "COOK", "DELI", "PIZZ"
        };

        // Get a random number.
        int randomNumber = random.nextInt(
            RANDOM_DEPTS.length
        );

        // Pick a random dept.
        return RANDOM_DEPTS[randomNumber];

    }

    //-------------------------------------------
    // A method for generating a random salary.
    //-------------------------------------------
    public static int getSalary() {

        // Get a number between 30,000 and 10,000,000.
        return 30000 + random.nextInt(10070001);

    }

    //-------------------------------------------
    // A method for generating a random payRate.
    //-------------------------------------------
    public static double getPayRate() {

        // Get a number between 17 and 30.
        // Round to two decimal places.
        double randomPayRate = Math.round(
            (
                (17.0 + random.nextInt(13)) +
                random.nextDouble()
            ) * 100.0
        ) / 100.0;
        return randomPayRate;

    }

    //-------------------------------------------
    // A method for generating a random fullTime.
    //-------------------------------------------
    public static boolean getFullTime() {

        // Get either a true or false.
        return random.nextBoolean();

    }

    //------------------------------------------------
    // A method for generating a random Course number.
    //------------------------------------------------
    public static int getCourseNumber() {

        // Choose either 100 level, 200 level, or 300 level.
        int level = 100;
        level = level * (random.nextInt(3) + 1);

        // Chose either 1 or multiples off 11.
        // e.g. 101 or 211 or 388
        int sublevel = 1;
        sublevel = (
            Math.max(1, (11 * random.nextInt(10)))
        );

        return level + sublevel;

    }

    //------------------------------------------------
    // A method for generating a random section.
    //------------------------------------------------
    public static String getSection() {

        // Get a random capital letter.
        String randomSection = Character.toString(
            (char) (random.nextInt(26) + 'a')
        );
        randomSection = randomSection.toUpperCase();

        return randomSection;

    }

    //------------------------------------------------
    // A method for generating a random schedule.
    //------------------------------------------------
    public static String[] getSchedule() {

        // A list of random schedules.
        final String[][] RANDOM_SCHEDULES = {
            {"MWF 1:00pm - 1:50pm"},
            {"MWF 2:00pm - 2:50pm"},
            {"TR 8:30am - 9:45am"},
            {"TR 1:00pm - 2:15pm"},
            {"MWF 12:00pm - 1:50pm"},
            {"MWF 11:00am - 11:50am"},
            {"MWF 8:00am - 8:50am"},
            {"T 6:00pm - 9:00pm"}
        };

        // Get a random number.
        int randomNumber = random.nextInt(
            RANDOM_SCHEDULES.length
        );

        // Get a random capital letter.
        return RANDOM_SCHEDULES[randomNumber];

    }

}


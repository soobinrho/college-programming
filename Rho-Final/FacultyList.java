// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.FormatterClosedException;
import java.util.NoSuchElementException;
import java.lang.IllegalStateException;
import java.io.FileNotFoundException;
import java.lang.SecurityException;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Formatter;
import java.nio.file.Path;
import java.util.Scanner;
import java.util.Date;
import java.io.File;

public class FacultyList {
    /*
     * This class is in charge of reading `facultyList.txt`
     * and then converting these data into
     * Faculty objects using the class Faculty.
     *
     * Also, if `facultyList.txt` doesn't already exist,
     * this class creates it and populates it with sample data.
    */

    // Number of sample data to be created.
    private static final int NUM_RANDOM_FACULTIES = 5;

    // Name of the file being saved.
    private static final String SAVE_FILE_PATH = "facultyList.txt";

    // All instance variables are handled as ArrayLists.
    private ArrayList<Faculty> faculties = new ArrayList<Faculty>();
    private ArrayList<String> firstNames = new ArrayList<String>();
    private ArrayList<String> lastNames = new ArrayList<String>();
    private ArrayList<String> addresses = new ArrayList<String>();
    private ArrayList<Integer> ssNums = new ArrayList<Integer>();
    private ArrayList<Date> birthDates = new ArrayList<Date>();
    private ArrayList<Integer> IDs = new ArrayList<Integer>();
    private ArrayList<Date> startDates = new ArrayList<Date>();
    private ArrayList<String> titles = new ArrayList<String>();
    private ArrayList<String> depts = new ArrayList<String>();
    private ArrayList<Integer> salaries = new ArrayList<Integer>();

    // This will be used for generating sample data.
    private static final SecureRandom random = new SecureRandom();

    //-------------------------------------------
    // A method for reading SAVE_FILE_PATH
    //-------------------------------------------
    public void read() {

        // Read SAVE_FILE_PATH
        // Note that the delimiter is
        // either " | " or "\n"
        try(Scanner input = new Scanner(
            Paths.get(SAVE_FILE_PATH)
        ).useDelimiter("( \\| |\\n)")) {

            // Read each line and assign the values
            // into the corresponding ArrayLists.
            while (input.hasNext()) {

                //-------------------------------------------
                // Read firstNames and lastNames.
                //-------------------------------------------
                String namesString = input.next();
                String[] splited = namesString.split("\\s+");
                firstNames.add(splited[0]);
                lastNames.add(splited[1]);

                //-------------------------------------------
                // Read addresses.
                //-------------------------------------------
                addresses.add(input.next());

                //-------------------------------------------
                // Read ssNums.
                //-------------------------------------------
                ssNums.add(input.nextInt());

                //-------------------------------------------
                // Read birthDates.
                //-------------------------------------------
                String birthDateString = input.next();
                splited = birthDateString.split("\\s+");

                // Scanner doesn't have a method for
                // directly reading a Date object,
                // so it's read as a String first and then
                // manually converted into a Date object.
                birthDates.add(
                    new Date(
                        Integer.parseInt(splited[0]),
                        Integer.parseInt(splited[1]),
                        Integer.parseInt(splited[2])
                    )
                );

                //-------------------------------------------
                // Read IDs.
                //-------------------------------------------
                IDs.add(input.nextInt());

                //-------------------------------------------
                // Read startDates.
                //-------------------------------------------
                String startDatesString = input.next();
                splited = startDatesString.split("\\s+");
                startDates.add(
                    new Date(
                        Integer.parseInt(splited[0]),
                        Integer.parseInt(splited[1]),
                        Integer.parseInt(splited[2])
                    )
                );

                //-------------------------------------------
                // Read titles.
                //-------------------------------------------
                titles.add(input.next());

                //-------------------------------------------
                // Read depts.
                //-------------------------------------------
                depts.add(input.next());

                //-------------------------------------------
                // Read salaries.
                //-------------------------------------------
                salaries.add(input.nextInt());

            }

            // Uncomment to debug.
            //System.out.println(firstNames);
            //System.out.println(lastNames);
            //System.out.println(addresses);
            //System.out.println(ssNums);
            //System.out.println(birthDates);
            //System.out.println(IDs);
            //System.out.println(startDates);
            //System.out.println(titles);
            //System.out.println(depts);
            //System.out.println(salaries);

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Faculty.
            //-------------------------------------------
            int numFacultys = firstNames.size();
            for (int index = 0; index < numFacultys; index++) {

                // Initialize.
                faculties.add(
                    new Faculty(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        IDs.get(index),
                        startDates.get(index),
                        titles.get(index),
                        depts.get(index),
                        salaries.get(index)
                    )
                );

            }

            // Uncomment to debug.
            //System.out.println(faculties);

        }
        catch (
            IOException |
            NoSuchElementException |
            IllegalStateException e
        ) {
            e.printStackTrace();
        }

    }

    //-----------------------------------------
    // Setters
    //-----------------------------------------
    public void setFacultys(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
        save();
    }

    public void setFirstNames(ArrayList<String> firstNames) {
        this.firstNames = firstNames;
        save();
    }

    public void setLastNames(ArrayList<String> lastNames) {
        this.lastNames = lastNames;
        save();
    }

    public void setAddresses(ArrayList<String> addresses) {
        this.addresses = addresses;
        save();
    }

    public void setSSNums(ArrayList<Integer> ssNums) {
        this.ssNums = ssNums;
        save();
    }

    public void setBirthDates(ArrayList<Date> birthDates) {
        this.birthDates = birthDates;
        save();
    }

    public void setIDs(ArrayList<Integer> IDs) {
        this.IDs = IDs;
        save();
    }

    public void setStartDates(ArrayList<Date> startDates) {
        this.startDates = startDates;
        save();
    }

    public void setTitles(ArrayList<String> titles) {
        this.titles = titles;
        save();
    }

    public void setDepts(ArrayList<String> depts) {
        this.depts = depts;
        save();
    }

    public void setSalaries(ArrayList<Integer> salaries) {
        this.salaries = salaries;
        save();
    }

    //-----------------------------------------
    // Getters
    //-----------------------------------------
    public ArrayList<Faculty> getFacultys() {return faculties;}
    public ArrayList<String> getFirstNames() {return firstNames;}
    public ArrayList<String> getLastNames() {return lastNames;}
    public ArrayList<String> getAddresses() {return addresses;}
    public ArrayList<Integer> getSSNums() {return ssNums;}
    public ArrayList<Date> getBirthDates() {return birthDates;}
    public ArrayList<Integer> getIDs() {return IDs;}
    public ArrayList<Date> getStartDates() {return startDates;}
    public ArrayList<String> getTitles() {return titles;}
    public ArrayList<String> getDepts() {return depts;}
    public ArrayList<Integer> getSalaries() {return salaries;}

    //-----------------------------------------
    // A method for saving to SAVE_FILE_PATH
    //-----------------------------------------
    public void save() {

        // Overwrite SAVE_FILE_PATH
        try (Formatter output = new Formatter(SAVE_FILE_PATH)) {

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Faculty.
            //-------------------------------------------
            int numFacultys = firstNames.size();
            faculties = new ArrayList<Faculty>();
            for (int index = 0; index < numFacultys; index++) {

                // Initialize.
                faculties.add(
                    new Faculty(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        IDs.get(index),
                        startDates.get(index),
                        titles.get(index),
                        depts.get(index),
                        salaries.get(index)
                    )
                );

            }

            // Iterate through every element in the arrays
            // and write to the file.
            for (int index = 0; index < faculties.size(); index++) {

                output.format(
                    "%s%s",
                    faculties.get(index).toString(),
                    System.getProperty("line.separator")
                );

            }

        }

        // Exception handling for writing the file.
        catch (
            SecurityException |
            FileNotFoundException |
            FormatterClosedException e
        ) {
            e.printStackTrace();
        }

    }

    //-------------------------------------
    // toString Method
    //-------------------------------------
    public String toString() {

        // Initialize the output string.
        String output = "";

        // Loop through every instance of faculties.
        for (Faculty faculty : faculties) {

            // Concatenate.
            output += String.format(
                "%s%s",
                faculty.toString(),
                System.getProperty("line.separator")
            );

        }

        return output;

    }

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

    //-------------------------------------------
    // A method for creating SAVE_FILE_PATH
    // and populating it with sample data.
    //-------------------------------------------
    public void createRandomFaculties() {

        // Loop through NUM_RANDOM_FACULTIES times.
        for (int index = 0; index < NUM_RANDOM_FACULTIES; index++) {

            // Generate firstName.
            firstNames.add(getRandomName());

            // Generate lastName.
            lastNames.add(getRandomName());

            // Generate address.
            addresses.add(getRandomAddress());

            // Generate ssNum.
            ssNums.add(getRandomSSNum());

            // Generate birthDate.
            birthDates.add(new Date(1998, 8, 22));

            // Generate ID.
            IDs.add(getRandomID());

            // Generate startDate.
            startDates.add(new Date(2017, 8, 25));

            // Generate title.
            titles.add(getRandomTitle());

            // Generate dept.
            depts.add(getRandomDept());

            // Generate salary.
            salaries.add(getRandomSalary());

        }

        // Uncomment to debug.
        //System.out.println(firstNames);
        //System.out.println(lastNames);
        //System.out.println(addresses);
        //System.out.println(ssNums);
        //System.out.println(birthDates);
        //System.out.println(IDs);
        //System.out.println(startDates);
        //System.out.println(titles);
        //System.out.println(depts);
        //System.out.println(salaries);

        // Save to SAVE_FILE_PATH
        save();

    }

    //-------------------------------------------
    // The main method
    //-------------------------------------------
    public static void main(String[] args) {

        //-------------------------------------------
        // Initialize.
        //-------------------------------------------

        // Initialize an instance of facultyList.
        // This instance is in charge of
        // handling SAVE_FILE_PATH
        FacultyList facultyList = new FacultyList();

        //-------------------------------------------
        // Check if SAVE_FILE_PATH already exists.
        //-------------------------------------------

        // If SAVE_FILE_PATH doesn't already exist,
        // create one and then populate it
        // with sample data. Notice that you can adjust
        // NUM_RANDOM_FACULTIES if you'd like to.
        File saveFile = new File(SAVE_FILE_PATH);
        if (!saveFile.exists()) {
            facultyList.createRandomFaculties();
        }

        //-------------------------------------------
        // Read the file and then output the data.
        //-------------------------------------------

        // read() method parses the strings in
        // the file; assigns them as instance variables
        // of the class Faculty; and finally
        // toString() method prints the converted data.
        facultyList.read();
        System.out.println(facultyList.toString());

    }

}


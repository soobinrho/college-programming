// COSC 211
// Soobin Rho
// August 2, 2022
import java.util.FormatterClosedException;
import java.util.NoSuchElementException;
import java.lang.IllegalStateException;
import java.io.FileNotFoundException;
import java.lang.SecurityException;
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
    private ArrayList<Integer> iDs = new ArrayList<Integer>();
    private ArrayList<Date> startDates = new ArrayList<Date>();
    private ArrayList<String> titles = new ArrayList<String>();
    private ArrayList<String> depts = new ArrayList<String>();
    private ArrayList<Integer> salaries = new ArrayList<Integer>();

    //-------------------------------------------
    // A method for reading SAVE_FILE_PATH
    //-------------------------------------------
    public void read() {

        // Reset all ArrayLists so that
        // data from SAVE_FILE_PATH doesn't
        // overlap with preexisting data.
        faculties = new ArrayList<Faculty>();
        firstNames = new ArrayList<String>();
        lastNames = new ArrayList<String>();
        addresses = new ArrayList<String>();
        ssNums = new ArrayList<Integer>();
        birthDates = new ArrayList<Date>();
        iDs = new ArrayList<Integer>();
        startDates = new ArrayList<Date>();
        titles = new ArrayList<String>();
        depts = new ArrayList<String>();
        salaries = new ArrayList<Integer>();

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
                // Read iDs.
                //-------------------------------------------
                iDs.add(input.nextInt());

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
            //System.out.println(iDs);
            //System.out.println(startDates);
            //System.out.println(titles);
            //System.out.println(depts);
            //System.out.println(salaries);

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Faculty.
            //-------------------------------------------
            int numFaculties = firstNames.size();
            for (int index = 0; index < numFaculties; index++) {

                // Initialize.
                faculties.add(
                    new Faculty(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        iDs.get(index),
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

    public void setIDs(ArrayList<Integer> iDs) {
        this.iDs = iDs;
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
    public ArrayList<Faculty> getFaculties() {return faculties;}
    public ArrayList<String> getFirstNames() {return firstNames;}
    public ArrayList<String> getLastNames() {return lastNames;}
    public ArrayList<String> getAddresses() {return addresses;}
    public ArrayList<Integer> getSSNums() {return ssNums;}
    public ArrayList<Date> getBirthDates() {return birthDates;}
    public ArrayList<Integer> getIDs() {return iDs;}
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
            int numFaculties = firstNames.size();
            faculties = new ArrayList<Faculty>();
            for (int index = 0; index < numFaculties; index++) {

                // Initialize.
                faculties.add(
                    new Faculty(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        iDs.get(index),
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
                    "%s%n",
                    faculties.get(index).toString()
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
                "%s%n",
                faculty.toString()
            );

        }

        return output;

    }

    //-------------------------------------------
    // A method for creating SAVE_FILE_PATH
    // and populating it with sample data.
    //-------------------------------------------
    public void createRandomFaculties() {

        // Loop through NUM_RANDOM_FACULTIES times.
        for (int index = 0; index < NUM_RANDOM_FACULTIES; index++) {

            // Generate firstName.
            String firstName = RandomData.getName();
            firstNames.add(firstName);

            // Generate lastName.
            // This shouldn't be the same as firstName.
            String lastName = RandomData.getName();
            while (lastName == firstName) {lastName = RandomData.getName();}
            lastNames.add(lastName);

            // Generate address.
            addresses.add(RandomData.getAddress());

            // Generate ssNum.
            ssNums.add(RandomData.getSSNum());

            // Generate birthDate.
            Date birthDate = RandomData.getBirthDate();
            birthDates.add(birthDate);

            // Generate ID.
            iDs.add(RandomData.getID());

            // Generate startDate.
            startDates.add(RandomData.getFacultyStartDate(birthDate));

            // Generate title.
            titles.add(RandomData.getFacultyTitle());

            // Generate dept.
            depts.add(RandomData.getDept());

            // Generate salary.
            salaries.add(RandomData.getSalary());

        }

        // Uncomment to debug.
        //System.out.println(firstNames);
        //System.out.println(lastNames);
        //System.out.println(addresses);
        //System.out.println(ssNums);
        //System.out.println(birthDates);
        //System.out.println(iDs);
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

        // Initialize an instance of FacultyList.
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


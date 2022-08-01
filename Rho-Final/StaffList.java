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

public class StaffList {
    /*
     * This class is in charge of reading `staffList.txt`
     * and then converting these data into
     * Staff objects using the class Staff.
     *
     * Also, if `staffList.txt` doesn't already exist,
     * this class creates it and populates it with sample data.
    */

    // Number of sample data to be created.
    private static final int NUM_RANDOM_STAFFS = 10;

    // Name of the file being saved.
    private static final String SAVE_FILE_PATH = "staffList.txt";

    // All instance variables are handled as ArrayLists.
    private ArrayList<Staff> staffs = new ArrayList<Staff>();
    private ArrayList<String> firstNames = new ArrayList<String>();
    private ArrayList<String> lastNames = new ArrayList<String>();
    private ArrayList<String> addresses = new ArrayList<String>();
    private ArrayList<Integer> ssNums = new ArrayList<Integer>();
    private ArrayList<Date> birthDates = new ArrayList<Date>();
    private ArrayList<Integer> iDs = new ArrayList<Integer>();
    private ArrayList<Date> startDates = new ArrayList<Date>();
    private ArrayList<String> titles = new ArrayList<String>();
    private ArrayList<String> depts = new ArrayList<String>();
    private ArrayList<Boolean> fullTimes = new ArrayList<Boolean>();
    private ArrayList<Double> payRates = new ArrayList<Double>();

    //-------------------------------------------
    // A method for reading SAVE_FILE_PATH
    //-------------------------------------------
    public void read() {

        // Reset all ArrayLists so that
        // data from SAVE_FILE_PATH doesn't
        // overlap with preexisting data.
        staffs = new ArrayList<Staff>();
        firstNames = new ArrayList<String>();
        lastNames = new ArrayList<String>();
        addresses = new ArrayList<String>();
        ssNums = new ArrayList<Integer>();
        birthDates = new ArrayList<Date>();
        iDs = new ArrayList<Integer>();
        startDates = new ArrayList<Date>();
        titles = new ArrayList<String>();
        depts = new ArrayList<String>();
        fullTimes = new ArrayList<Boolean>();
        payRates = new ArrayList<Double>();

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
                // Read fullTimes.
                //-------------------------------------------
                fullTimes.add(Boolean.valueOf(input.next()));

                //-------------------------------------------
                // Read payRates.
                //-------------------------------------------
                payRates.add(input.nextDouble());

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
            //System.out.println(fullTimes);
            //System.out.println(payRates);

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Staff.
            //-------------------------------------------
            int numStaffs = firstNames.size();
            for (int index = 0; index < numStaffs; index++) {

                // Initialize.
                staffs.add(
                    new Staff(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        iDs.get(index),
                        startDates.get(index),
                        titles.get(index),
                        depts.get(index),
                        fullTimes.get(index),
                        payRates.get(index)
                    )
                );

            }

            // Uncomment to debug.
            //System.out.println(staffs);

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

    public void setFulltimes(ArrayList<Boolean> fullTimes) {
        this.fullTimes = fullTimes;
        save();
    }

    public void setPayRates(ArrayList<Double> payRates) {
        this.payRates = payRates;
        save();
    }

    //-----------------------------------------
    // Getters
    //-----------------------------------------
    public ArrayList<Staff> getStaffs() {return staffs;}
    public ArrayList<String> getFirstNames() {return firstNames;}
    public ArrayList<String> getLastNames() {return lastNames;}
    public ArrayList<String> getAddresses() {return addresses;}
    public ArrayList<Integer> getSSNums() {return ssNums;}
    public ArrayList<Date> getBirthDates() {return birthDates;}
    public ArrayList<Integer> getIDs() {return iDs;}
    public ArrayList<Date> getStartDates() {return startDates;}
    public ArrayList<String> getTitles() {return titles;}
    public ArrayList<String> getDepts() {return depts;}
    public ArrayList<Boolean> getFullTimes() {return fullTimes;}
    public ArrayList<Double> getPayRates() {return payRates;}

    //-----------------------------------------
    // A method for saving to SAVE_FILE_PATH
    //-----------------------------------------
    public void save() {

        // Overwrite SAVE_FILE_PATH
        try (Formatter output = new Formatter(SAVE_FILE_PATH)) {

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Staff.
            //-------------------------------------------
            int numStaffs = firstNames.size();
            staffs = new ArrayList<Staff>();
            for (int index = 0; index < numStaffs; index++) {

                // Initialize.
                staffs.add(
                    new Staff(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        iDs.get(index),
                        startDates.get(index),
                        titles.get(index),
                        depts.get(index),
                        fullTimes.get(index),
                        payRates.get(index)
                    )
                );

            }

            // Iterate through every element in the arrays
            // and write to the file.
            for (int index = 0; index < staffs.size(); index++) {

                output.format(
                    "%s%n",
                    staffs.get(index).toString()
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

        // Loop through every instance of staffs.
        for (Staff staff : staffs) {

            // Concatenate.
            output += String.format(
                "%s%n",
                staff.toString()
            );

        }

        return output;

    }

    //-------------------------------------------
    // A method for creating SAVE_FILE_PATH
    // and populating it with sample data.
    //-------------------------------------------
    public void createRandomStaffs() {

        // Loop through NUM_RANDOM_STAFFS times.
        for (int index = 0; index < NUM_RANDOM_STAFFS; index++) {

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
            startDates.add(RandomData.getStaffStartDate(birthDate));

            // Generate title.
            titles.add(RandomData.getTitle());

            // Generate dept.
            depts.add(RandomData.getDept());

            // Generate fullTime.
            fullTimes.add(RandomData.getFullTime());

            // Generate payRate.
            payRates.add(RandomData.getPayRate());

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
        //System.out.println(fullTimes);
        //System.out.println(payRates);

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

        // Initialize an instance of StaffList.
        // This instance is in charge of
        // handling SAVE_FILE_PATH
        StaffList staffList = new StaffList();

        //-------------------------------------------
        // Check if SAVE_FILE_PATH already exists.
        //-------------------------------------------

        // If SAVE_FILE_PATH doesn't already exist,
        // create one and then populate it
        // with sample data. Notice that you can adjust
        // NUM_RANDOM_STAFFS if you'd like to.
        File saveFile = new File(SAVE_FILE_PATH);
        if (!saveFile.exists()) {
            staffList.createRandomStaffs();
        }

        //-------------------------------------------
        // Read the file and then output the data.
        //-------------------------------------------

        // read() method parses the strings in
        // the file; assigns them as instance variables
        // of the class Staff; and finally
        // toString() method prints the converted data.
        staffList.read();
        System.out.println(staffList.toString());

    }

}


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

public class StudentList {
    /*
     * This class is in charge of reading `studentList.txt`
     * and then converting these data into
     * Student objects using the class Student.
     *
     * Also, if `studentList.txt` doesn't already exist,
     * this class creates it and populates it with sample data.
    */

    // Number of sample data to be created.
    private static final int NUM_RANDOM_STUDENTS = 20;

    // Name of the file being saved.
    private static final String SAVE_FILE_PATH = "studentList.txt";

    // All instance variables are handled as ArrayLists.
    private ArrayList<Student> students = new ArrayList<Student>();
    private ArrayList<String> firstNames = new ArrayList<String>();
    private ArrayList<String> lastNames = new ArrayList<String>();
    private ArrayList<String> addresses = new ArrayList<String>();
    private ArrayList<Integer> ssNums = new ArrayList<Integer>();
    private ArrayList<Date> birthDates = new ArrayList<Date>();
    private ArrayList<Integer> iDs = new ArrayList<Integer>();
    private ArrayList<Date> startDates = new ArrayList<Date>();
    private ArrayList<Date> expGradDates = new ArrayList<Date>();
    private ArrayList<Integer> crTakens = new ArrayList<Integer>();
    private ArrayList<Integer> crPassedes = new ArrayList<Integer>();
    private ArrayList<Integer> currCrs = new ArrayList<Integer>();

    //-------------------------------------------
    // A method for reading SAVE_FILE_PATH
    //-------------------------------------------
    public void read() {

        // Reset all ArrayLists so that
        // data from SAVE_FILE_PATH doesn't
        // overlap with preexisting data.
        students = new ArrayList<Student>();
        firstNames = new ArrayList<String>();
        lastNames = new ArrayList<String>();
        addresses = new ArrayList<String>();
        ssNums = new ArrayList<Integer>();
        birthDates = new ArrayList<Date>();
        iDs = new ArrayList<Integer>();
        startDates = new ArrayList<Date>();
        expGradDates = new ArrayList<Date>();
        crTakens = new ArrayList<Integer>();
        crPassedes = new ArrayList<Integer>();
        currCrs = new ArrayList<Integer>();

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
                // Read expGradDate.
                //-------------------------------------------
                String expGradDatesString = input.next();
                splited = expGradDatesString.split("\\s+");
                expGradDates.add(
                    new Date(
                        Integer.parseInt(splited[0]),
                        Integer.parseInt(splited[1]),
                        Integer.parseInt(splited[2])
                    )
                );

                //-------------------------------------------
                // Read crTakens.
                //-------------------------------------------
                crTakens.add(input.nextInt());

                //-------------------------------------------
                // Read crPassedes.
                //-------------------------------------------
                crPassedes.add(input.nextInt());

                //-------------------------------------------
                // Read currCrs.
                //-------------------------------------------
                currCrs.add(input.nextInt());

            }

            // Uncomment to debug.
            //System.out.println(firstNames);
            //System.out.println(lastNames);
            //System.out.println(addresses);
            //System.out.println(ssNums);
            //System.out.println(birthDates);
            //System.out.println(iDs);
            //System.out.println(startDates);
            //System.out.println(expGradDates);
            //System.out.println(crTakens);
            //System.out.println(crPassedes);
            //System.out.println(currCrs);

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Student.
            //-------------------------------------------
            int numStudents = firstNames.size();
            for (int index = 0; index < numStudents; index++) {

                // Initialize.
                students.add(
                    new Student(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        iDs.get(index),
                        startDates.get(index),
                        expGradDates.get(index)
                    )
                );

                // Since crTaken, crPassed, and currCr
                // are not designed to be populated
                // with the constructor,
                // call the setter methods.
                Student student = students.get(index);
                student.setCrTaken(crTakens.get(index));
                student.setCrPassed(crPassedes.get(index));
                student.setCurrCr(currCrs.get(index));
                students.set(index, student);

            }

            // Uncomment to debug.
            //System.out.println(students);

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

    public void setExpGradDates(ArrayList<Date> expGradDates) {
        this.expGradDates = expGradDates;
        save();
    }

    public void setCrTakens(ArrayList<Integer> crTakens) {
        this.crTakens = crTakens;
        save();
    }

    public void setCrPassedes(ArrayList<Integer> crPassedes) {
        this.crPassedes = crPassedes;
        save();
    }

    public void setCurrCrs(ArrayList<Integer> currCrs) {
        this.currCrs = currCrs;
        save();
    }

    //-----------------------------------------
    // Getters
    //-----------------------------------------
    public ArrayList<Student> getStudents() {return students;}
    public ArrayList<String> getFirstNames() {return firstNames;}
    public ArrayList<String> getLastNames() {return lastNames;}
    public ArrayList<String> getAddresses() {return addresses;}
    public ArrayList<Integer> getSSNums() {return ssNums;}
    public ArrayList<Date> getBirthDates() {return birthDates;}
    public ArrayList<Integer> getIDs() {return iDs;}
    public ArrayList<Date> getStartDates() {return startDates;}
    public ArrayList<Date> getExpGradDates() {return expGradDates;}
    public ArrayList<Integer> getCrTakens() {return crTakens;}
    public ArrayList<Integer> getCrPassedes() {return crPassedes;}
    public ArrayList<Integer> getCurrCrs() {return currCrs;}

    //-----------------------------------------
    // A method for saving to SAVE_FILE_PATH
    //-----------------------------------------
    public void save() {

        // Overwrite SAVE_FILE_PATH
        try (Formatter output = new Formatter(SAVE_FILE_PATH)) {

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Student.
            //-------------------------------------------
            int numStudents = firstNames.size();
            students = new ArrayList<Student>();
            for (int index = 0; index < numStudents; index++) {

                // Initialize.
                students.add(
                    new Student(
                        firstNames.get(index),
                        lastNames.get(index),
                        addresses.get(index),
                        ssNums.get(index),
                        birthDates.get(index),
                        iDs.get(index),
                        startDates.get(index),
                        expGradDates.get(index)
                    )
                );

                // Since crTaken, crPassed, and currCr
                // are not designed to be populated
                // with the constructor,
                // call the setter methods.
                Student student = students.get(index);
                student.setCrTaken(crTakens.get(index));
                student.setCrPassed(crPassedes.get(index));
                student.setCurrCr(currCrs.get(index));
                students.set(index, student);

            }

            // Iterate through every element in the arrays
            // and write to the file.
            for (int index = 0; index < students.size(); index++) {

                output.format(
                    "%s%n",
                    students.get(index).toString()
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

        // Loop through every instance of students.
        for (Student student : students) {

            // Concatenate.
            output += String.format(
                "%s%n",
                student.toString()
            );

        }

        return output;

    }

    //-------------------------------------------
    // A method for creating SAVE_FILE_PATH
    // and populating it with sample data.
    //-------------------------------------------
    public void createRandomStudents() {

        // Loop through NUM_RANDOM_STUDENTS times.
        for (int index = 0; index < NUM_RANDOM_STUDENTS; index++) {

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
            Date startDate = RandomData.getStudentStartDate(birthDate);
            startDates.add(startDate);

            // Generate expGradDate.
            expGradDates.add(RandomData.getExpGradDate(startDate));

            // Generate crTaken.
            int crTaken = RandomData.getCrTaken();
            crTakens.add(crTaken);

            // Generate crPassed.
            crPassedes.add(RandomData.getCrPassed(crTaken));

            // Generate currCr.
            currCrs.add(RandomData.getCurrCr());

        }

        // Uncomment to debug.
        //System.out.println(firstNames);
        //System.out.println(lastNames);
        //System.out.println(addresses);
        //System.out.println(ssNums);
        //System.out.println(birthDates);
        //System.out.println(iDs);
        //System.out.println(startDates);
        //System.out.println(expGradDates);
        //System.out.println(crTakens);
        //System.out.println(crPassedes);
        //System.out.println(currCrs);

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

        // Initialize an instance of StudentList.
        // This instance is in charge of
        // handling SAVE_FILE_PATH
        StudentList studentList = new StudentList();

        //-------------------------------------------
        // Check if SAVE_FILE_PATH already exists.
        //-------------------------------------------

        // If SAVE_FILE_PATH doesn't already exist,
        // create one and then populate it
        // with sample data. Notice that you can adjust
        // NUM_RANDOM_STUDENTS if you'd like to.
        File saveFile = new File(SAVE_FILE_PATH);
        if (!saveFile.exists()) {
            studentList.createRandomStudents();
        }

        //-------------------------------------------
        // Read the file and then output the data.
        //-------------------------------------------

        // read() method parses the strings in
        // the file; assigns them as instance variables
        // of the class Student; and finally
        // toString() method prints the converted data.
        studentList.read();
        System.out.println(studentList.toString());

    }

}


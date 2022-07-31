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
    private static final int NUM_STUDENTS = 20;

    // All instance variables are handled as ArrayLists.
    private ArrayList<String> firstNames = new ArrayList<String>();
    private ArrayList<String> lastNames = new ArrayList<String>();
    private ArrayList<String> addresses = new ArrayList<String>();
    private ArrayList<Integer> ssNums = new ArrayList<Integer>();
    private ArrayList<Date> birthDates = new ArrayList<Date>();
    private ArrayList<Integer> IDs = new ArrayList<Integer>();
    private ArrayList<Date> startDates = new ArrayList<Date>();
    private ArrayList<Date> expGradDates = new ArrayList<Date>();
    private ArrayList<Integer> crTakens = new ArrayList<Integer>();
    private ArrayList<Integer> crPassedes = new ArrayList<Integer>();
    private ArrayList<Integer> currCrs = new ArrayList<Integer>();

    //-------------------------------------------
    // A method for reading `studentList.txt`
    //-------------------------------------------
    public void read() {

        // Read `studentList.txt`
        // Note that the delimiter is
        // either " | " or "\n"
        try(Scanner input = new Scanner(
            Paths.get("studentList.txt")
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
                // manually convert to a Date object.
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
            System.out.println(firstNames);
            System.out.println(lastNames);
            System.out.println(addresses);
            System.out.println(ssNums);
            System.out.println(birthDates);
            System.out.println(IDs);
            System.out.println(startDates);
            System.out.println(expGradDates);
            System.out.println(crTakens);
            System.out.println(crPassedes);
            System.out.println(currCrs);

        }
        catch (
            IOException |
            NoSuchElementException |
            IllegalStateException e
        ) {
            e.printStackTrace();
        }

    }


    //------------------------------------
    // Getters
    //------------------------------------
    //public ArrayList<Integer> getAccountNumbers() {return accountNumbers;}
    //public ArrayList<Double> getTransactionAmounts() {return transactionAmounts;}

    //------------------------------------
    // Setters
    //------------------------------------
//    public void setAccountNumbers(ArrayList<Integer> accountNumbers) {
//        this.accountNumbers = accountNumbers;
//        save();
//    }
//
//    public void setTransactionAmounts(ArrayList<Double> transactionAmounts) {
//        this.transactionAmounts = transactionAmounts;
//        save();
//    }
//
//    public void save() {
//
//        // Initializing length for the loop below.
//        // This assumes the length of accountNumbers
//        // is the same as every array's.
//        int length = accountNumbers.size();
//
//        // --------------------------------------
//        // Recreate "trans.txt"
//        // --------------------------------------
//        try (Formatter output = new Formatter("trans.txt")) {
//
//            // Iterate through every element in the arrays
//            // and write to the file.
//            for (int count = 0; count < length; count++) {
//
//                // "trans.txt" output example:
//                // 1001 383721.46
//                // 1002 82442.21
//                output.format(
//                    "%d %.2f %s",
//                    accountNumbers.get(count),
//                    transactionAmounts.get(count),
//                    System.getProperty("line.separator")
//                );
//
//            }
//        }
//
//        // Exception handling for writing the file.
//        catch (
//            SecurityException |
//            FileNotFoundException |
//            FormatterClosedException e
//        ) {
//            e.printStackTrace();
//        }
//
//    }

    //-------------------------------------------
    // The main method
    //-------------------------------------------
    public static void main(String[] args) {

        // Check if `studentList.txt`
        // already exists. If not, it creates one
        // and then populates it with sample data.
        ;

        StudentList studentList = new StudentList();
        studentList.read();

    }

}


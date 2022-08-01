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
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Formatter;
import java.nio.file.Path;
import java.util.Iterator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Date;
import java.io.File;

public class CourseListingSystem {
    /*
     * This class is the main controller of the program.
     * It displays all courses along with
     * detailed information including who is teaching it
     * and a list of all students enrolled in the course.
    */

    // Number of sample data to be created.
    private static final int NUM_RANDOM_COURSELISTINGS = 12;

    // Name of the file being saved.
    public static final String SAVE_FILE_PATH = "courseListings.txt";

    // All instance variables are handled as ArrayLists.
    private static ArrayList<Course> courses = new ArrayList<Course>();
    private static ArrayList<Faculty> faculties = new ArrayList<Faculty>();
    private static ArrayList<Student[]> students = new ArrayList<Student[]>();

    //-------------------------------------------
    // A method for reading SAVE_FILE_PATH
    //-------------------------------------------
    public static void read() {

        // Reset all ArrayLists so that
        // data from SAVE_FILE_PATH doesn't
        // overlap with preexisting data.
        courses = new ArrayList<Course>();
        faculties = new ArrayList<Faculty>();
        students = new ArrayList<Student[]>();

        // Read SAVE_FILE_PATH
        // Note that the delimiter is
        // either " | " or "\n"
        try(Scanner input = new Scanner(
            Paths.get(SAVE_FILE_PATH)
        ).useDelimiter("( \\| |\\n)")) {

            // Initialize variables that will be
            // used inside the loop below.
            // These are used for parsing
            // `courseListings.txt`

            //-------------------------------------------
            // Variables for parsing the Course object.
            //-------------------------------------------
            CourseList courseList = new CourseList();
            courseList.read();
            ArrayList<Course> allCourses = courseList.getCourses();

            String dept = "";
            int number = 0;
            String section = "";

            //-------------------------------------------
            // Variables for parsing the Faculty object.
            //-------------------------------------------
            FacultyList facultyList = new FacultyList();
            facultyList.read();
            ArrayList<Faculty> allFaculties = facultyList.getFaculties();

            int facultyID = 0;

            //-------------------------------------------
            // Variables for parsing the Student object.
            //-------------------------------------------
            StudentList studentList = new StudentList();
            studentList.read();
            ArrayList<Student> allStudents = studentList.getStudents();

            int studentID = 0;

            // Read each line and assign the values
            // into the corresponding ArrayLists.
            while (input.hasNext()) {

                //-------------------------------------------
                // Read the Course object.
                //-------------------------------------------
                String courseCode = input.next();
                String[] splited = courseCode.split("\\s+");

                // Parse.
                dept = splited[0];
                number = Integer.parseInt(splited[1]);
                section = splited[2];

                // Find the detailed Course information
                // by using dept, number, and section.
                for (Course course : allCourses) {

                    if (
                        dept.equals(course.getDept()) &&
                        number == course.getNumber() &&
                        section.equals(course.getSection())
                    ) {
                        // Add the found match to the
                        // courses ArrayList.
                        courses.add(course);
                    }

                }

                //-------------------------------------------
                // Read the Faculty object.
                //-------------------------------------------
                facultyID = input.nextInt();

                // Find detailed Faculty information
                // by using facultyID.
                for (Faculty faculty : allFaculties) {

                    if (facultyID == faculty.getID()) {
                        // Add the found match to the
                        // faculties ArrayList.
                        faculties.add(faculty);
                    }

                }

                //-------------------------------------------
                // Read the Student object.
                //-------------------------------------------
                String studentIDString = input.next();
                splited = studentIDString.split("\\s+");

                // This will be used only inside a loop,
                // so it's named as studentsLoop.
                Student[] studentsLoop = new Student[0];

                for (String iDString : splited) {

                    // Parse.
                    studentID = Integer.parseInt(iDString);

                    // Find detailed Student information
                    // by using studentID.
                    for (Student student : allStudents) {
                        if (studentID == student.getID()) {

                            // Add the found match to the array.
                            studentsLoop = addStudent(studentsLoop, student);

                            // Break the loop since the match is found.
                            break;

                        }
                    }

                }

                // Add studentsLoop into the students ArrayList.
                students.add(studentsLoop);

            }

            // Uncomment to debug.
            //System.out.println(courses);
            //System.out.println(faculties);
            //for (int index = 0; index < students.size(); index++) {
            //    System.out.printf("%nIndex %d%n%n",  index);
            //    for (Student studentLoop : students.get(index)) {
            //        System.out.println(studentLoop);
            //    }
            //}

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
    public static void setCourses(ArrayList<Course> coursesInput) {
        courses = coursesInput;
    }

    public static void setFaculties(ArrayList<Faculty> facultiesInput) {
        faculties = facultiesInput;
    }

    public static void setStudents(ArrayList<Student[]> studentsInput) {
        students = studentsInput;
    }

    //-----------------------------------------
    // Getters
    //-----------------------------------------
    public static ArrayList<Course> getCourses() {return courses;}
    public static ArrayList<Faculty> getFaculties() {return faculties;}
    public static ArrayList<Student[]> getStudents() {return students;}

    //-----------------------------------------
    // A method for saving to SAVE_FILE_PATH
    //-----------------------------------------
    public static void save() {

        // Overwrite SAVE_FILE_PATH
        try (PrintWriter output = new PrintWriter(SAVE_FILE_PATH)) {
            output.print(getString());
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

    //-----------------------------------------
    // A method for adding a new Student
    // to a Student[] array.
    //-----------------------------------------
    public static Student[] addStudent(
        Student[] studentsArray, Student newStudent
    ) {

        // Create a new array with one size bigger.
        Student[] studentsBackup = studentsArray;
        studentsArray = new Student[studentsBackup.length + 1];
        int size = studentsBackup.length;

        // Assign original values back.
        for (int index = 0; index < size; index++) {
            studentsArray[index] = studentsBackup[index];
        }

        // Add newStudent to the array.
        studentsArray[size] = newStudent;

        return studentsArray;

    }

    //-------------------------------------
    // A method for combining a String
    // array of schedule into one String.
    //-------------------------------------
    public static String combineSchedule(String[] schedule) {
        return String.join(" ", schedule);
    }

    // The difference between print() method
    // and getString() method is that
    // print() is intended for end-users, so is
    // pretty formatted. On the other hand,
    // getString() method is just for internal purposes.
    // For example, save() method uses getString() method
    // to save the data into "courseListings.txt"

    //-------------------------------------
    // print Method
    //-------------------------------------
    public static void print() {

        // Loop through every courseListing.
        for (int index = 0; index < courses.size(); index++) {

            //----------------------------------------
            // Course information.
            //----------------------------------------
            Course courseLoop = courses.get(index);

            String title = courseLoop.getTitle();
            String dept = courseLoop.getDept();
            int number = courseLoop.getNumber();
            String section = courseLoop.getSection();
            String schedule = combineSchedule(courseLoop.getSchedule());

            String header = String.format(
                "%s | %s %d %s",
                title,
                dept,
                number,
                section
            );

            //----------------------------------------
            // Faculty information.
            //----------------------------------------
            Faculty facultyLoop = faculties.get(index);

            String firstName = facultyLoop.getFirstName();
            String lastName = facultyLoop.getLastName();

            // Example:
            // Fundamentals of Blackberries Chocolate | WIZA 277 A
            // Lectured by: Cool Melon
            // MWF 8:00am - 8:50am
            System.out.printf(
                "%n%n%s%nLectured by: %s %s%n%s%n%n",
                header,
                firstName,
                lastName,
                schedule
            );

            //----------------------------------------
            // Student information.
            //----------------------------------------
            Student[] studentsLoop = students.get(index);

            // Loop studentsLoop.length amount of times.
            for (int count = 0; count < studentsLoop.length; count++) {

                firstName = studentsLoop[count].getFirstName();
                lastName = studentsLoop[count].getLastName();
                int studentID = studentsLoop[count].getID();

                // Example:
                // 1. Black Durian (785923)
                // 2. Soobin Rho (698635)
                System.out.printf(
                    "%d. %s %s (%d)%n",
                    count + 1,
                    firstName,
                    lastName,
                    studentID
                );

            }

            // Print a newline for readability.
            System.out.println();

        }

    }

    //-------------------------------------
    // toString Method
    //-------------------------------------
    public static String getString() {

        // Initialize the output string.
        String output = "";

        // Loop through every courseListing.
        for (int index = 0; index < courses.size(); index++) {

            //----------------------------------------
            // Write dept, number, and section.
            //----------------------------------------
            Course courseLoop = courses.get(index);

            String dept = courseLoop.getDept();
            int number = courseLoop.getNumber();
            String section = courseLoop.getSection();

            // e.g. COSC 211 A
            output = String.format(
                "%s%s %d %s | ",
                output,
                dept,
                number,
                section
            );

            //----------------------------------------
            // Write facultyID.
            //----------------------------------------
            Faculty facultyLoop = faculties.get(index);

            int facultyID = facultyLoop.getID();

            // e.g. 100217
            output = String.format(
                "%s%d | ",
                output,
                facultyID
            );

            //----------------------------------------
            // Write studentID.
            //----------------------------------------
            Student[] studentsLoop = students.get(index);
            for (Student studentLoop : studentsLoop) {

                int studentID = studentLoop.getID();

                // e.g. 698635 724087 724509
                output = String.format(
                    "%s%d ",
                    output,
                    studentID
                );

            }

            // Trim the white space at the end
            // and add a newline for the next course.
            output = String.format("%s%n", output.trim());

        }

        return output;

    }

    //-------------------------------------------
    // A method for creating SAVE_FILE_PATH
    // and populating it with sample data.
    //-------------------------------------------
    public static void createRandomCourseListings() {

        //-------------------------------------------
        // Pick random courses.
        //-------------------------------------------

        // Read `courseList.txt`
        CourseList courseList = new CourseList();
        courseList.read();
        ArrayList<Course> allCourses = courseList.getCourses();
        ArrayList<Course> randomCourses = new ArrayList<Course>();

        // Determine how many courseListings to create.
        int size = Math.min(
            allCourses.size(),
            NUM_RANDOM_COURSELISTINGS
        );

        // Loop size amount of times and get
        // random integers to choose random courses.
        // Use a HashSet to avoid duplicates.
        HashSet<Course> randomCoursesLoop = new HashSet<Course>();
        for (int index = 0; index < size; index++) {
            randomCoursesLoop.add(
                allCourses.get(RandomData.getInt(allCourses.size()))
            );
        }

        // Assign all values of the HashSet
        // into the ArrayList.
        Iterator<Course> coursesIterator = randomCoursesLoop.iterator();
        while (coursesIterator.hasNext()) {
            randomCourses.add(coursesIterator.next());
        }

        // Apply the changes.
        setCourses(randomCourses);

        //-------------------------------------------
        // Pick random faculties.
        //-------------------------------------------

        // Read `facultyList.txt`
        FacultyList facultyList = new FacultyList();
        facultyList.read();
        ArrayList<Faculty> allFaculties = facultyList.getFaculties();
        ArrayList<Faculty> randomFaculties = new ArrayList<Faculty>();

        // Loop size amount of times and get
        // random integers to choose random faculties.
        for (int index = 0; index < size; index++) {
            randomFaculties.add(
                allFaculties.get(RandomData.getInt(allFaculties.size()))
            );
        }

        // Apply the changes.
        setFaculties(randomFaculties);

        //-------------------------------------------
        // Pick random students.
        //-------------------------------------------

        // Read `studentList.txt`
        StudentList studentList = new StudentList();
        studentList.read();
        ArrayList<Student> allStudents = studentList.getStudents();
        ArrayList<Student[]> randomStudents = new ArrayList<Student[]>();

        // Loop size amount of times and get
        // random integers to choose random students.
        // Use a HashSet to avoid duplicates.
        for (int index = 0; index < size; index++) {

            // Reset for each loop iteration.
            Student[] randomStudentsLoop = new Student[0];
            HashSet<Student> randomStudentsHash = new HashSet<Student>();

            // Get a random number between 1 and 25.
            int randomNumber = 1 + RandomData.getInt(25);

            // Loop randomNumber amount of times.
            for (int inde = 0; inde < randomNumber; inde++) {
                randomStudentsHash.add(
                    allStudents.get(RandomData.getInt(allStudents.size()))
                );
            }

            // Assign all values of the HashSet
            // into the ArrayList.
            Iterator<Student> studentsIterator = randomStudentsHash.iterator();
            while (studentsIterator.hasNext()) {
                randomStudentsLoop = (
                    addStudent(randomStudentsLoop, studentsIterator.next())
                );
            }

            // Add the ArrayList<Student> randomStudentsLoop
            // into the ArrayList<Student[]> randomStudents.
            randomStudents.add(randomStudentsLoop);

        }

        // Apply the changes.
        setStudents(randomStudents);

        //-------------------------------------------
        // Save to "courseListingsSystem.txt"
        //-------------------------------------------
        save();

    }

    //-------------------------------------------
    // The main method
    //-------------------------------------------
    public static void main(String[] args) {

        //-------------------------------------------
        // Initialize.
        //-------------------------------------------

        // Create "courseList.txt" if it doesn't exist.
        String filePath = CourseList.SAVE_FILE_PATH;
        File saveFile = new File(filePath);
        if (!saveFile.exists()) {
            CourseList courseList = new CourseList();
            courseList.createRandomCourses();
        }

        // Create "facultyList.txt" if it doesn't exist.
        filePath = FacultyList.SAVE_FILE_PATH;
        saveFile = new File(filePath);
        if (!saveFile.exists()) {
            FacultyList facultyList = new FacultyList();
            facultyList.createRandomFaculties();
        }

        // Create "studentList.txt" if it doesn't exist.
        filePath = StudentList.SAVE_FILE_PATH;
        saveFile = new File(filePath);
        if (!saveFile.exists()) {
            StudentList studentList = new StudentList();
            studentList.createRandomStudents();
        }

        // Create "courseListings.txt" if it doesn't exist.
        saveFile = new File(SAVE_FILE_PATH);
        if (!saveFile.exists()) {
            createRandomCourseListings();
        }

        //-------------------------------------------
        // Read "courseListings.txt"
        //-------------------------------------------
        read();

        //-------------------------------------------
        // Print "courseListings.txt"
        //-------------------------------------------
        print();

    }

}

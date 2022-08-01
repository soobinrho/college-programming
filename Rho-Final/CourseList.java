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

public class CourseList {
    /*
     * This class is in charge of reading `courseList.txt`
     * and then converting these data into
     * Course objects using the class Course.
     *
     * Also, if `courseList.txt` doesn't already exist,
     * this class creates it and populates it with sample data.
    */

    // Number of sample data to be created.
    public static final int NUM_RANDOM_COURSES = 10;

    // Name of the file being saved.
    public static final String SAVE_FILE_PATH = "courseList.txt";

    // All instance variables are handled as ArrayLists.
    private ArrayList<Course> courses = new ArrayList<Course>();
    private ArrayList<String> titles = new ArrayList<String>();
    private ArrayList<String> depts = new ArrayList<String>();
    private ArrayList<Integer> numbers = new ArrayList<Integer>();
    private ArrayList<String> sections = new ArrayList<String>();
    private ArrayList<String[]> schedules = new ArrayList<String[]>();

    //-------------------------------------------
    // A method for reading SAVE_FILE_PATH
    //-------------------------------------------
    public void read() {

        // Reset all ArrayLists so that
        // data from SAVE_FILE_PATH doesn't
        // overlap with preexisting data.
        courses = new ArrayList<Course>();
        titles = new ArrayList<String>();
        depts = new ArrayList<String>();
        numbers = new ArrayList<Integer>();
        sections = new ArrayList<String>();
        schedules = new ArrayList<String[]>();

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
                // Read titles.
                //-------------------------------------------
                titles.add(input.next());

                //-------------------------------------------
                // Read depts & numbers & sections.
                //-------------------------------------------
                String courseCodesString = input.next();
                String[] splited = courseCodesString.split("\\s+");
                depts.add(splited[0]);
                numbers.add(Integer.parseInt(splited[1]));
                sections.add(splited[2]);

                //-------------------------------------------
                // Read schedules.
                //-------------------------------------------
                String schedulesString = input.next();
                splited = schedulesString.split("\\s+");
                schedules.add(splited);

            }

            // Uncomment to debug.
            //System.out.println(titles);
            //System.out.println(depts);
            //System.out.println(numbers);
            //System.out.println(sections);
            //System.out.println(schedules);

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Course.
            //-------------------------------------------
            int numCourses = titles.size();
            for (int index = 0; index < numCourses; index++) {

                // Initialize.
                courses.add(
                    new Course(
                        titles.get(index),
                        depts.get(index),
                        numbers.get(index),
                        sections.get(index),
                        schedules.get(index)
                    )
                );

            }

            // Uncomment to debug.
            //System.out.println(courses);

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
    public void setTitles(ArrayList<String> titles) {
        this.titles = titles;
        save();
    }

    public void setDepts(ArrayList<String> depts) {
        this.depts = depts;
        save();
    }

    public void setNumbers(ArrayList<Integer> numbers) {
        this.numbers = numbers;
        save();
    }

    public void setSections(ArrayList<String> sections) {
        this.sections = sections;
        save();
    }

    public void setSchedules(ArrayList<String[]> schedules) {
        this.schedules = schedules;
        save();
    }

    //-----------------------------------------
    // Getters
    //-----------------------------------------
    public ArrayList<Course> getCourses() {return courses;}
    public ArrayList<String> getTitles() {return titles;}
    public ArrayList<String> getDepts() {return depts;}
    public ArrayList<Integer> getNumbers() {return numbers;}
    public ArrayList<String> getSections() {return sections;}
    public ArrayList<String[]> getSchedules() {return schedules;}

    //-----------------------------------------
    // A method for saving to SAVE_FILE_PATH
    //-----------------------------------------
    public void save() {

        // Overwrite SAVE_FILE_PATH
        try (Formatter output = new Formatter(SAVE_FILE_PATH)) {

            //-------------------------------------------
            // Combines all instance variables into
            // complete objects of the class Course.
            //-------------------------------------------
            int numCourses = titles.size();
            courses = new ArrayList<Course>();
            for (int index = 0; index < numCourses; index++) {

                // Initialize.
                courses.add(
                    new Course(
                        titles.get(index),
                        depts.get(index),
                        numbers.get(index),
                        sections.get(index),
                        schedules.get(index)
                    )
                );

            }

            // Iterate through every element in the arrays
            // and write to the file.
            for (int index = 0; index < courses.size(); index++) {

                output.format(
                    "%s%n",
                    courses.get(index).toString()
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

        // Loop through every instance of courses.
        for (Course course : courses) {

            // Concatenate.
            output += String.format(
                "%s%n",
                course.toString()
            );

        }

        return output;

    }

    //-------------------------------------------
    // A method for creating SAVE_FILE_PATH
    // and populating it with sample data.
    //-------------------------------------------
    public void createRandomCourses() {

        // Loop through NUM_RANDOM_COURSES times.
        for (int index = 0; index < NUM_RANDOM_COURSES; index++) {

            // Generate title.
            titles.add(RandomData.getCourseTitle());

            // Generate dept.
            depts.add(RandomData.getDept());

            // Generate number.
            numbers.add(RandomData.getCourseNumber());

            // Generate section.
            sections.add(RandomData.getSection());

            // Generate schedules.
            schedules.add(RandomData.getSchedule());

        }

        // Uncomment to debug.
        //System.out.println(titles);
        //System.out.println(depts);
        //System.out.println(numbers);
        //System.out.println(sections);
        //System.out.println(schedules);

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

        // Initialize an instance of CourseList.
        // This instance is in charge of
        // handling SAVE_FILE_PATH
        CourseList courseList = new CourseList();

        //-------------------------------------------
        // Check if SAVE_FILE_PATH already exists.
        //-------------------------------------------

        // If SAVE_FILE_PATH doesn't already exist,
        // create one and then populate it
        // with sample data. Notice that you can adjust
        // NUM_RANDOM_COURSES if you'd like to.
        File saveFile = new File(SAVE_FILE_PATH);
        if (!saveFile.exists()) {
            courseList.createRandomCourses();
        }

        //-------------------------------------------
        // Read the file and then output the data.
        //-------------------------------------------

        // read() method parses the strings in
        // the file; assigns them as instance variables
        // of the class Course; and finally
        // toString() method prints the converted data.
        courseList.read();
        System.out.println(courseList.toString());

    }

}


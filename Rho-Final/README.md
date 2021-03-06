## Final Programming Assignment: Course Listing System<br>
`COSC 211: Computer Science II`
`August 2, 2022`
`Soobin Rho`

<br>
<br>

***What does this program do?***
The main purpose of this program,
which is named `CourseListingSystem.java`, is to
display all courses including
who is teaching the course and
which students are enrolled in it.
In order to run it, type this
into your terminal:

```bash
# Compile.
javac CourseListingSystem.java

# Run.
java CourseListingSystem
```

<br>

First, the program reads `courseList.txt`,
`facultlyList.txt`, and `studentList.txt`.
The program then prints each course information
along with the corresponding faculty and students list.
Here's how the output looks like:

```bash
dddd | dddd

```

<br>

***Additional Functions:***
This program also has additional functions
in case you want to test the program
without having to input your own data.
These functions create sample data for you:

```bash
# 1. Create 10 example courses.
#    Write to `courseList.txt`
javac CourseList.java
java CourseList

# 2. Create 5 example faculty members.
#    Write to `facultyList.txt`
javac FacultyList.java
java FacultyList

# 3. Create 20 example students.
#    Write to `studentList.txt`
javac StudentList.java
java StudentList

# (Bonus). Create 10 example student employees.
#          Write to staffList.txt
#
#          Note that the class StudentEmployees
#          is not used by the main program.
#          This is an extra class.
#
javac StaffList.java
java StaffList
```

<br>

By the way, notice that every class
has a `...Test.java` file:
`CourseTest.java`,
`FacultyTest.java`,
`StudentTest.java`,
`PersonTest.java`,
`EmployeeTest.java`,
`StaffTest.java`, and
`StudentEmployeeTest.java`.

End-users can ignore all `...Test.java`
files becuase they are just for debugging
purposes. Basically, they just test and show
examples of how to use setter and
getter methods. For example,
`StudentTest.java` shows how to
set and get the attributes of
the class *Student*, such as
*Date expGradDate* and *int crTaken*.

<br>
<br>

## Design Approach

Everything you need to know in order
to run the program was shown above.
This section is for those who want to
get a better understanding of what
happens behind the scene each time
the program is run.

```java
System.out.println("t");
```

<br>
<br>

## How This Documentation was Made

This documentation was first written
as a markdown file. Then, it was exported
to a GitHub flavored html file with *grip*:

```bash
# Install grip.
pip3 install grip

# Install wkhtmltopdf.
sudo dnf -y install wkhtmltopdf

# Convert README.md to html and then
# host to http://localhost:6419
grip README.md 6419

# Export the html to a pdf file.
wkhtmltopdf http://localhost:6419 README.pdf
```

<br>
<br>

Thank you, Professor Steinwand!
We've learned a lot about Java
thanks to you, and I'm looking forward
to learn C++ with you next semester.
Have a great rest of the summer!

<br>

<p align="center">
  --- End of Assignment ---
</p>

<br>
<br>
<br>



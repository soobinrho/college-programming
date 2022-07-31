## Final Programming Assignment: Course Listing System<br>
`COSC211`
`August 2, 2022`
`Soobin Rho`

<br>
<br>

***What does this program do?***
The main purpose of this program,
which is named `ListCourses.java`, is to
display all courses including
who is teaching the course and
which students are enrolled in it.
In order to run it, type this
into your terminal:

```bash
# Compile.
javac ListCourses.java

# Run.
java ListCourses
```

<br>

First, the program reads `courseList.txt`,
`facultlyList.txt`, and `studentList.txt`.
The program then prints each course information
along with the corresponding faculty and students list.
Here's what the output would look like:

```


```

<br>

***Additional Functions***
This program also has additional functions
in case you want to test with sample data
without having to input your own data.
These functions create sample data for you.

1. `CoursesTest.java` creates four course
3. `StudentTest.java` creates 20 instances
of the class *Student*.

By the way, notice that every class
has a `...test.java` file:
`CourseTest.java`,
`FacultyTest.java`,
`StudentTest.java`,
`PersonTest.java`,
`EmployeeTest.java`,
`StaffTest.java`, and
`StudentEmployeeTest.java`.

End-users can ignore all `...test.java`
files becuase they are just for debugging
purposes. Basically, they just show
examples of how to use setter and
getter methods. For example,
`StudentTest.java` shows how to
set and get the attributes of
the class *Student*, such as
*expGradDate* and *crTaken*.

<br>
<br>

## Detailed Design Approach

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
to a GitHub flavored html file with *grip*.

```bash
# Install grip.
pip install grip

# Export the markdown file.
grip README.md --export README.html
```

<br>
<br>
<br>



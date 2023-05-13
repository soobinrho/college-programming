<br>

## Coursework Examples

<!---
June 30, 2022
For the example writeup image,
I needed to add a light grey (HTML Color Code F6F8FA)
border around it so that it doesn't just blend in too much
with a white background -- e.g. GitHub on desktop.

I used Gimp. 'Filter' 'Decor' 'Border' size 4, D value 1

Plus, you can see the HTML color code on any website on Chrome
on Chrome Developer's mode by typing Ctrl + Shift + c
--->

<br>
<br>

***Operating Systems***, Spring 2023 **[[Example: Virtual Memory Simulator](https://github.com/soobinrho/college-programming/tree/main/2023-spring/operating-systems/RhoLab5)]**

Elements of operating systems. In this class, we referenced two textbooks:
*Operating Systems and Middleware: Supporting Controlled Interaction* by Max Hailperin
(https://gustavus.edu/mcs/max/os-book/) and
*The Linux Command Line* by William Shotts.
(https://linuxcommand.org/tlcl.php)

For one of my class lab sessions, I had to write a virtual memory simulator
in C, with support for such functions as `int physAddr = MMU(virtAddr);` which
stands for Memory Management Unit. (MMU)

<img src="https://user-images.githubusercontent.com/19341857/227884907-0e2d1c2b-e3dd-42a0-baf3-fe084977cc45.png" width="500px">

<br>

Also, I did a small research on *Which Infrastructure / OS for Our Next Startup?*

<img src="https://github.com/soobinrho/college-programming/assets/19341857/0c9a67f0-0b82-4d6f-ae5c-35ccd4b6b5ac" width="500px">

<br>
<br>

***Intro to Geographic Information Systems (GIS)***, Spring 2023 **[[Example: GIS Porfolio](https://github.com/soobinrho/college-programming/tree/main/2023-spring/intro-to-GIS)]**

"A GIS is a computer-based system to aid in the collection, maintenance, storage, analysis,
output, and distribution of spatial data and information." (Professor Sarah Olimb, 2023) We used ArcGIS in this class.

<img src="https://user-images.githubusercontent.com/19341857/233396327-0d93ac2d-4e10-48f0-b965-79e7363c01ca.jpg" width="500px">

<br>

***C++ Programming***, Fall 2022 **[[Final Project Example](https://github.com/soobinrho/college-programming/tree/main/2022-fall/c%2B%2B-programming/final-project)]**

Foundations of C++ programming. In my final project,
I wrote an STL-like container that can read or write images
in either binary or ASCII data formats, both conforming
to the PGM specifications as dictated by the
[Netpbm](https://netpbm.sourceforge.net/doc/pgm.html)
open-source graphics library.

<img src="https://user-images.githubusercontent.com/19341857/206621901-49d342fb-2854-4796-ad12-4fc58b8b55e8.png" width="500px">

<br>

***Calculus II***, Summer 2022 **[[Writeup Example](https://github.com/soobinrho/college-programming/blob/main/2022-summer/calculus-II/AFP2-SoobinRho.pdf)]**

A course on differentiation, integration,
linear systems, infinite integrals, and
infinite series.

<img src="https://user-images.githubusercontent.com/19341857/176699968-c9cd420b-b0f9-47d5-98cb-320e533e9907.png" width="500px">

<br>

***Computer Science II***, Summer 2022 **[[Java Example](https://github.com/soobinrho/college-programming/blob/main/2022-summer/computer-science-II/RhoRace.java)]**

A course on basic programming with Java.

<img src="https://user-images.githubusercontent.com/19341857/184002427-9c12da89-9818-4590-b4c8-11bf8eac9032.svg" width="500px">

<br>

***Computer Science I***, Summer 2022 **[[Python Jupyter Notebook Example](https://github.com/soobinrho/college-programming/blob/main/2022-summer/computer-science-I/15-final-project.ipynb)]**

A course on basic programming with Python.

```Python
# When I was writing a paper for my Calculus II class,
# I happened to be in a situation where
# I had to draw a right-angle triangle
# to demonstrate how trigonometric substitution
# for integration works. Using Matplotlib and seaborn,
# I was finally able to draw a right-angle triangle,
# but it took me around five hours to do that.

# That's why I chose to write this
# `Graph_Right_Angle_Triangle` class. I wanted
# to write a wrapper for Matplotlib and seaborn
# such that I can draw a right-angle triangle
# easily and quickly, and that's what I did.

# Making an instance and calling .show() to graph the triangle.
triangle_1 = Graph_Right_Angle_Trinalge(len_adjacent=12, len_opposite=12)
triangle_1.show()

# Graphing another instance.
triangle_2 = Graph_Right_Angle_Trinalge(len_adjacent=12, len_opposite=7)
triangle_2.show()
```
![output-3-1](https://user-images.githubusercontent.com/19341857/176696554-3a81950c-e087-44a8-b3fe-2b7695275e62.svg)
![output-3-2](https://user-images.githubusercontent.com/19341857/176696587-50ca1232-f5ff-4d00-9cc9-ad9834ba6589.svg)

<br>
<br>
<br>

<!---

"A Note About Git Commit Messages" by Tim Pope
https://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html

Capitalized, short (50 chars or less) summary

More detailed explanatory text, if necessary.  Wrap it to about 72
characters or so.  In some contexts, the first line is treated as the
subject of an email and the rest of the text as the body.  The blank
line separating the summary from the body is critical (unless you omit
the body entirely); tools like rebase can get confused if you run the
two together.

Write your commit message in the imperative: "Fix bug" and not "Fixed bug"
or "Fixes bug."  This convention matches up with commit messages generated
by commands like git merge and git revert.

--->


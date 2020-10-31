Authors:
Alexander Blake and Lucas Larocco

How To Build:
To build the main program, type the command "make dateCalc"
To build the test program, type the command "make date_test"
To Build the Docker,
which will simultaneously build the main and test program, type the command "docker build ./"

Versions:
C++: 7.5.0
G++: 7.5.0

Purpose:
The purpose of this program is to make calculations involving dates.
This program can do things such as predict a date a few days after a certain date,
find the difference in days between two dates,
and tell what the day of the week was on a certain date.

Limitations:
In the day of the week function, there have been a few instances of the program
getting the wrong day of the week from a date by one day before. I could not
find a cause in my own code, nor any correlation between the faulty dates,
thus it must be a flaw with the tm and/or time_t objects.
In the difference between days function,
it can't handle dates before the year 1000 and after the year 9999.


# Academic Office Management System

## Overview

The Academic Office Management System is a console-based C++ application developed using Object-Oriented Programming (OOP) concepts. The system is designed to manage academic entities such as students, teachers, courses, sections, venues, and assessments.

The project also includes file handling functionality, allowing all records to be saved permanently and loaded automatically whenever the program starts.

---

# Features

## Student Management
- Add new students
- View all students
- Support for multiple student types:
  - Regular Students
  - Scholarship Students
  - Exchange Students
- GPA management
- Scholarship probation checking
- Exchange student fail status checking
- Fee status management

## Teacher Management
- Add teachers
- View teacher records
- Teacher feedback system
- Average teacher score calculation

## Course Management
- Add courses
- View available courses
- Assign teachers to courses
- Register students in courses
- Support for multiple course types:
  - Core Courses
  - Elective Courses
  - Lab Courses

## Venue Management
- Add venues
- View all venues
- Manage venue capacity
- Computer lab availability checking

## Section Management
- Create sections
- Link courses, teachers, and venues
- Display all sections

## Assessment Management
- Add student assessments
- Support for:
  - Finals
  - Quizzes
  - Assignments
- Store total and obtained marks
- Display assessments of individual students

## File Handling
The system stores all data in text files:

- `Students.txt`
- `Teachers.txt`
- `Courses.txt`
- `Venues.txt`
- `Sections.txt`
- `Assessments.txt`

All records are:
- Automatically loaded at program startup
- Automatically saved before exiting the program

---

# Technologies Used

- Language: C++
- Concepts:
  - Object-Oriented Programming (OOP)
  - Inheritance
  - Polymorphism
  - Abstraction
  - Encapsulation
  - Friend Functions
  - File Handling
  - Dynamic Memory Allocation
  - STL Vectors

---

# Class Structure

## Base Classes
- `academicEntity`
- `student`
- `course`
- `Assessment`

## Derived Student Classes
- `regularStudent`
- `scholarshipStudent`
- `exchangeStudent`

## Derived Course Classes
- `core`
- `elective`
- `lab`

## Derived Assessment Classes
- `finals`
- `quizzes`
- `assignments`

---

# Project Structure

```bash
├── main.cpp
├── Students.txt
├── Teachers.txt
├── Courses.txt
├── Venues.txt
├── Sections.txt
├── Assessments.txt
└── README.md
```

---

# How to Run

## Using Visual Studio
1. Open the project in Visual Studio
2. Build the project
3. Run the application

## Using g++

```bash
g++ main.cpp -o AcademicSystem
./AcademicSystem
```

---

# Main Menu

```text
1.  Add Student
2.  View Students
3.  Add Teacher
4.  View Teachers
5.  Add Course
6.  View Courses
7.  Register Student in Course
8.  Assign Course to Teacher
9.  Add Venue
10. Show Venues
11. Show All Sections
12. Add Section
13. Add Assessment
14. Show Student Assessments
15. Exit
```

---

# OOP Concepts Implemented

## Inheritance
Used in:
- Student hierarchy
- Course hierarchy
- Assessment hierarchy

## Polymorphism
Implemented through:
- Virtual functions
- Function overriding

## Abstraction
Abstract base classes:
- `academicEntity`
- `student`
- `course`
- `Assessment`

## Encapsulation
Protected and private members are used to secure and organize data.

---

# Future Improvements

Possible future enhancements include:

- Graphical User Interface (GUI)
- Database integration using MySQL or SQLite
- Login system for students, teachers, and admin
- Attendance management
- CGPA calculation
- Timetable generation
- Advanced search and filtering
- Better exception handling
- Smart pointers for memory management

---

# Learning Outcomes

This project helped in understanding:

- Real-world implementation of OOP concepts
- File handling in C++
- Dynamic object management
- Class relationships and inheritance
- Menu-driven application design
- Data persistence techniques

---

# Author

Developed by Asghar

Academic Project — FAST Academic Office System

---

# Conclusion

The Academic Office Management System is a structured and modular C++ project that demonstrates the practical implementation of Object-Oriented Programming concepts along with file handling and dynamic data management.

The project provides a simplified academic management solution while maintaining scalability and readability in code design.

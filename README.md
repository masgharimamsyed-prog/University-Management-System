Academic Office Management System
Overview

The Academic Office Management System is a console-based C++ application built using Object-Oriented Programming (OOP) principles. It simulates a complete academic environment where students, teachers, courses, venues, sections, and assessments are managed through a structured menu-driven interface.

The system uses dynamic memory allocation, STL vectors, and file handling to ensure data persistence across program runs.

System Architecture

The project is divided into modular pages, each handling a specific domain:

Teacher Management Page
Student Management Page
Course Management Page
Venue Management Page
Section Management Page
Assessment Management Page

Each page provides CRUD operations (Create, Read, Update, Delete) with validation.

Features
Student Management
Add student (Regular / Scholarship / Exchange)
View all students
Remove student
Update student details
Register student in courses
GPA tracking
Fee status handling (for regular students)
Teacher Management
Add teacher
View teacher list
Remove teacher
Update teacher details
Assign course to teacher
Teacher-course mapping
Course Management
Add course (Core / Elective / Lab)
View all courses
Remove course
Update course details
Assign teacher to course
Register students in courses
Display enrolled students
Venue Management
Add venue
View venues
Remove venue
Update venue
Manage capacity
Computer lab availability flag
Section Management
Create sections
Assign:
Course
Teacher
Venue
View all sections
Remove sections
Update section mapping
Assessment Management
Add assessment:
Finals
Quizzes
Assignments
Link assessment with student and course
View student assessments
File Handling System

All data is stored permanently using text files:

Students.txt
Teachers.txt
Courses.txt
Venues.txt
Sections.txt
Assessments.txt
Data Behavior
Data loads automatically on program start (loadData())
Data saves automatically before exit (saveData())
Technologies Used
C++ Programming Language
Object-Oriented Programming (OOP)
Inheritance
Polymorphism
Abstraction
Encapsulation
STL (Vectors)
Dynamic Memory Allocation (new/delete)
File Handling
Menu-driven system design
Class Structure
Base Classes
academicEntity
student
course
Assessment
Student Hierarchy
regularStudent
scholarshipStudent
exchangeStudent
Course Hierarchy
core
elective
lab
Assessment Hierarchy
finals
quizzes
assignments
System Pages (Menu Design)
Main Menu
Teacher Page
Student Page
Course Page
Venue Page
Section Page
Assessment Page
Exit (Auto Save)
Teacher Page
Add Teacher
View Teachers
Remove Teacher
Update Teacher
Assign Course
Student Page
Add Student
View Students
Remove Student
Update Student
Register Student in Course
Course Page
Add Course
View Courses
Remove Course
Update Course
Venue Page
Add Venue
View Venues
Remove Venue
Update Venue
Section Page
Add Section
View Sections
Remove Section
Update Section
Assessment Page
Add Assessment
View Student Assessments
Key Functional Logic
Data Validation
Ensures unique IDs for:
Students
Teachers
Courses
Venues
Sections
Relationship Mapping
Students ↔ Courses (registration)
Teachers ↔ Courses (assignment)
Courses ↔ Venues (sections)
Students ↔ Assessments
Memory Management
Uses dynamic allocation (new)
Stores objects in STL vectors
Prevents duplicate entries using ID checks
Main Functional Highlights
Add Operations
Create entities with validation
Assign relationships during creation
Remove Operations
Deletes objects from vectors using ID matching
Update Operations
Modify existing records safely
Maintain relationships during updates
View Operations
Displays structured data for each module
Future Improvements
Database integration (MySQL / SQLite)
GUI (Qt / Windows Forms)
Login system (Admin / Student / Teacher)
Attendance system
CGPA calculation system
Timetable generator
Search and filter system
Smart memory management (smart pointers)
Role-based access control
Learning Outcomes

This project demonstrates:

Real-world OOP system design
Modular programming using functions
Data persistence using file handling
Relationship management between entities
Menu-driven architecture design
Memory and resource management in C++
Author

Developed by Asghar

FAST Academic Project — Academic Office Management System

Conclusion

This system is a structured academic management simulation built in C++. It demonstrates how real-world academic operations can be modeled using object-oriented programming, modular design, and persistent storage mechanisms.

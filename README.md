# Academic Office Management System

## Overview

The **Academic Office Management System** is a console-based C++ application built using **Object-Oriented Programming (OOP)** principles. It simulates a complete academic environment where students, teachers, courses, venues, sections, and assessments are managed through a structured menu-driven interface.

The system uses **dynamic memory allocation**, **STL vectors**, and **file handling** to ensure data persistence across program runs.

---

## System Architecture

The project is divided into modular pages, each handling a specific domain:

- **Teacher Management Page**
- **Student Management Page**
- **Course Management Page**
- **Venue Management Page**
- **Section Management Page**
- **Assessment Management Page**

Each module supports **CRUD operations (Create, Read, Update, Delete)** with proper validation.

---

## Features

### Student Management
- Add student (Regular / Scholarship / Exchange)
- View all students
- Remove student
- Update student details
- Register student in courses
- GPA tracking
- Fee status handling

---

### Teacher Management
- Add teacher
- View teacher list
- Remove teacher
- Update teacher details
- Assign course to teacher
- Teacher-course mapping

---

### Course Management
- Add course (Core / Elective / Lab)
- View all courses
- Remove course
- Update course details
- Assign teacher to course
- Register students in courses
- Display enrolled students

---

### Venue Management
- Add venue
- View venues
- Remove venue
- Update venue
- Manage capacity
- Computer lab availability

---

### Section Management
- Create sections
- Assign course, teacher, and venue
- View all sections
- Remove sections
- Update section mapping

---

### Assessment Management
- Add assessments (Finals, Quizzes, Assignments)
- Link assessment with student and course
- View student assessments

---

## File Handling System

All data is stored permanently using text files:

- `Students.txt`
- `Teachers.txt`
- `Courses.txt`
- `Venues.txt`
- `Sections.txt`
- `Assessments.txt`

### Data Behavior
- Data loads automatically on program start using `loadData()`
- Data saves automatically before exit using `saveData()`

---

## Technologies Used

- **C++ Programming Language**
- **Object-Oriented Programming (OOP)**
  - Inheritance
  - Polymorphism
  - Abstraction
  - Encapsulation
- **STL (Vectors)**
- **Dynamic Memory Allocation (new/delete)**
- **File Handling**
- **Menu-driven System Design**

---

## Class Structure

### Base Classes
- `academicEntity`
- `student`
- `course`
- `Assessment`

---

### Student Hierarchy
- `regularStudent`
- `scholarshipStudent`
- `exchangeStudent`

---

### Course Hierarchy
- `core`
- `elective`
- `lab`

---

### Assessment Hierarchy
- `finals`
- `quizzes`
- `assignments`

---

## System Pages (Menu Design)

### Main Menu
- Teacher Page
- Student Page
- Course Page
- Venue Page
- Section Page
- Assessment Page
- Exit (Auto Save)

---

### Teacher Page
- Add Teacher
- View Teachers
- Remove Teacher
- Update Teacher
- Assign Course

---

### Student Page
- Add Student
- View Students
- Remove Student
- Update Student
- Register Student in Course

---

### Course Page
- Add Course
- View Courses
- Remove Course
- Update Course

---

### Venue Page
- Add Venue
- View Venues
- Remove Venue
- Update Venue

---

### Section Page
- Add Section
- View Sections
- Remove Section
- Update Section

---

### Assessment Page
- Add Assessment
- View Student Assessments

---

## Key Functional Logic

### Data Validation
Ensures **unique IDs** for:
- Students
- Teachers
- Courses
- Venues
- Sections

---

### Relationship Mapping
- Students ↔ Courses (registration)
- Teachers ↔ Courses (assignment)
- Courses ↔ Venues (sections)
- Students ↔ Assessments

---

### Memory Management
- Uses dynamic allocation (`new`)
- Stores objects in STL vectors
- Prevents duplicate entries using ID checks

---

## Main Functional Highlights

### Add Operations
Create entities with validation and assign relationships during creation.

### Remove Operations
Delete objects from vectors using ID matching.

### Update Operations
Modify existing records safely while maintaining relationships.

### View Operations
Display structured data for each module.

---

## Future Improvements

- Database integration (MySQL / SQLite)
- GUI (Qt / Windows Forms)
- Login system (Admin / Student / Teacher)
- Attendance system
- CGPA calculation system
- Timetable generator
- Search and filter system
- Smart pointers for memory management
- Role-based access control

---

## Learning Outcomes

This project demonstrates:
- Real-world OOP system design
- Modular programming using functions
- File handling for data persistence
- Relationship management between entities
- Menu-driven application design
- Memory management in C++

---

## Author

Developed by **Asghar**

FAST Academic Project — Academic Office Management System

---

## Conclusion

This project is a structured academic management system built in C++. It demonstrates practical implementation of object-oriented programming, modular design, and persistent storage mechanisms.

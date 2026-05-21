# 🎓 Academic Office Management System

## 📌 Overview

The **Academic Office Management System** is a console-based C++ application developed using **Object-Oriented Programming (OOP)** concepts. The project simulates a real academic environment where students, teachers, courses, sections, venues, and assessments are managed through a fully structured menu-driven system.

The application focuses on modular design, relationship management between entities, dynamic memory handling, and persistent data storage using file handling techniques.

This project was developed as a hands-on implementation of core OOP principles and demonstrates how real-world academic systems can be modeled using C++.

---

# 🏗️ System Architecture

The system is divided into multiple independent modules:

| Module | Description |
|---|---|
| 👨‍🎓 Student Management | Manage students, GPA, fee status, and course registrations |
| 👨‍🏫 Teacher Management | Manage teachers and teacher-course assignments |
| 📚 Course Management | Handle courses, enrollments, and course details |
| 🏢 Venue Management | Manage classrooms, labs, and seating capacity |
| 🧩 Section Management | Create and manage course sections |
| 📝 Assessment Management | Store quizzes, assignments, and finals |

Each module supports complete **CRUD operations** with validation and relationship handling.

---

# ✨ Features

## 👨‍🎓 Student Management

| Feature | Description |
|---|---|
| Add Students | Add Regular, Scholarship, and Exchange students |
| View Students | Display complete student records |
| Update Students | Modify existing student details |
| Remove Students | Delete student records safely |
| Course Registration | Register students in courses |
| GPA Management | Track student GPA |
| Fee Tracking | Manage fee payment status |

---

## 👨‍🏫 Teacher Management

| Feature | Description |
|---|---|
| Add Teachers | Create teacher records |
| View Teachers | Display all teachers |
| Update Teachers | Modify teacher information |
| Remove Teachers | Delete teacher records |
| Assign Courses | Map teachers to courses |

---

## 📚 Course Management

| Feature | Description |
|---|---|
| Add Courses | Add Core, Elective, and Lab courses |
| View Courses | Display all courses |
| Update Courses | Modify course details |
| Remove Courses | Delete courses |
| Teacher Assignment | Assign teachers to courses |
| Student Enrollment | Register students in courses |
| Enrollment Records | Display enrolled students |

---

## 🏢 Venue Management

| Feature | Description |
|---|---|
| Add Venues | Create venue records |
| View Venues | Display venue details |
| Update Venues | Modify venue information |
| Remove Venues | Delete venue records |
| Capacity Handling | Manage seating capacity |
| Lab Availability | Handle computer labs |

---

## 🧩 Section Management

| Feature | Description |
|---|---|
| Create Sections | Create course sections |
| Assign Resources | Assign teachers and venues |
| View Sections | Display section details |
| Update Sections | Modify section mappings |
| Remove Sections | Delete sections |

---

## 📝 Assessment Management

| Feature | Description |
|---|---|
| Add Assessments | Add Finals, Quizzes, and Assignments |
| Student Mapping | Link assessments with students |
| Course Mapping | Associate assessments with courses |
| View Records | Display assessment records |

---

# 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Core programming language |
| OOP | System architecture and design |
| STL Vectors | Dynamic object storage |
| Dynamic Memory Allocation | Runtime object management |
| File Handling | Persistent data storage |
| Menu-Driven Design | User interaction |

---

# 🧠 OOP Concepts Implemented

- Inheritance
- Polymorphism
- Encapsulation
- Abstraction
- Composition
- Function Overriding

---

# 💾 File Handling System

The project stores data permanently using text files.

| File Name | Purpose |
|---|---|
| `Students.txt` | Store student records |
| `Teachers.txt` | Store teacher records |
| `Courses.txt` | Store course records |
| `Venues.txt` | Store venue records |
| `Sections.txt` | Store section records |
| `Assessments.txt` | Store assessment records |

### 🔄 Data Persistence
- Data loads automatically when the program starts
- Data saves automatically before program exit

---

# 🧬 Class Structure

## Base Classes
- `academicEntity`
- `student`
- `course`
- `Assessment`

---

## Student Hierarchy
- `regularStudent`
- `scholarshipStudent`
- `exchangeStudent`

---

## Course Hierarchy
- `core`
- `elective`
- `lab`

---

## Assessment Hierarchy
- `finals`
- `quizzes`
- `assignments`

---

# ⚙️ Functional Highlights

| Functionality | Description |
|---|---|
| Data Validation | Prevents duplicate IDs |
| Relationship Management | Handles entity relationships |
| Dynamic Memory | Uses `new` with STL vectors |
| CRUD Operations | Create, Read, Update, Delete support |
| File Persistence | Automatic save/load system |
| Menu Navigation | Structured console-based interface |

---

# 🧭 System Menus

| Main Menu Options |
|---|
| Teacher Page |
| Student Page |
| Course Page |
| Venue Page |
| Section Page |
| Assessment Page |
| Exit System |

---

# 📚 Learning Outcomes

This project helped in understanding:

- Real-world OOP architecture
- Modular software development
- Entity relationship management
- Dynamic memory management
- File handling in C++
- STL vector operations
- Menu-driven application design

---

# 🚀 Future Improvements

- MySQL / SQLite integration
- GUI using Qt
- Authentication system
- Attendance management
- Automated CGPA calculation
- Search and filtering
- Smart pointers
- Role-based access control

---

# 📌 Conclusion

The **Academic Office Management System** is a comprehensive C++ project that demonstrates practical implementation of object-oriented programming concepts, modular architecture, file handling, and entity relationship management.

The project reflects strong problem-solving skills and serves as a solid foundation for larger-scale management systems and backend development projects.

---

# 👨‍💻 Author

## Asghar

[![GitHub](https://img.shields.io/badge/GitHub-masgharimamsyed--prog-181717?style=flat&logo=github)](https://github.com/masgharimamsyed-prog)

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Asghar%20Imam-0A66C2?style=flat&logo=linkedin)](https://www.linkedin.com/in/asghar-imam/)

[![Email](https://img.shields.io/badge/Email-masgharimamsyed@gmail.com-EA4335?style=flat&logo=gmail&logoColor=white)](mailto:masgharimamsyed@gmail.com)

---

<p align="center">
Built with ❤️ using C++ and Object-Oriented Programming
</p>

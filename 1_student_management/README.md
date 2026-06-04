# Student Management System

## Overview
A console-based application that efficiently manages student records with persistent file storage.

## Features
- ✅ Add new student records
- ✅ Display all students in a formatted table
- ✅ Search for students by ID
- ✅ Update student information
- ✅ Delete student records
- ✅ Persistent data storage using binary files
- ✅ User-friendly menu-driven interface

## Data Structure
Each student record contains:
- **ID**: Unique student identifier (integer)
- **Name**: Student's full name (string, max 50 chars)
- **Email**: Student's email address (string, max 50 chars)
- **GPA**: Grade Point Average (float, 0.0-4.0)
- **Phone**: Contact phone number (string, max 15 chars)

## Compilation & Execution

### Linux/Mac:
```bash
g++ -std=c++11 -o student_management student_management.cpp
./student_management
```

### Windows (MinGW):
```bash
g++ -std=c++11 -o student_management.exe student_management.cpp
student_management.exe
```

## Usage Guide

### Menu Options:

**1. Add Student**
- Enter student ID, name, email, GPA, and phone number
- Data is automatically saved to `students.dat` file

**2. Display All Students**
- Shows all students in a formatted table
- Displays total number of records

**3. Search Student**
- Enter student ID to search
- Displays detailed information if found

**4. Update Student**
- Enter student ID to update
- Modify name, email, GPA, or phone number
- Changes are saved immediately

**5. Delete Student**
- Enter student ID to delete
- Record is permanently removed from database

**6. Exit**
- Closes the application

## File Format
- **students.dat**: Binary file storing student records
- Each record is exactly `sizeof(Student)` bytes

## Learning Concepts
- **File I/O**: Binary file operations in C++
- **Structures**: Organizing related data
- **Functions**: Modular programming approach
- **Arrays & Strings**: Data storage
- **Stream Operations**: File handling with ifstream/ofstream/fstream

## Author
libnaansu-hash

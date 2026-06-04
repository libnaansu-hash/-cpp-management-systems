# C++ Management Systems & Games

A comprehensive collection of console-based C++ applications demonstrating core programming concepts including OOP, file handling, data structures, and game logic.

## 🎯 Projects Overview

### 1. 📚 Student Management System
**Location:** `1_student_management/`

**Objective:** Efficiently manage student records with persistent file storage.

**Features:**
- ✅ Add, update, delete, and display student records
- ✅ Search students by ID
- ✅ Persistent binary file storage (students.dat)
- ✅ Menu-driven interface
- ✅ Formatted table display

**Technologies:** C++, Structures, File I/O (binary files)

**Key Concepts:**
- File handling (ifstream, ofstream, fstream)
- Binary file operations
- Struct-based data organization
- Menu-driven applications

**Quick Start:**
```bash
cd 1_student_management
g++ -std=c++11 -o student_management student_management.cpp
./student_management
```

---

### 2. 🏦 Bank Management Application
**Location:** `2_bank_management/`

**Objective:** Simulate core banking operations with secure data management using OOP.

**Features:**
- ✅ Create customer accounts
- ✅ Deposit and withdraw funds with validation
- ✅ Check account balance
- ✅ View account details
- ✅ Transfer money between accounts
- ✅ List all accounts
- ✅ Persistent account storage

**Technologies:** C++, Object-Oriented Programming (Classes), File I/O, Encapsulation

**Key Concepts:**
- Class design and encapsulation
- Getter and setter methods
- Binary serialization
- File pointer operations
- Object-oriented design patterns

**Quick Start:**
```bash
cd 2_bank_management
g++ -std=c++11 -o bank_management bank_management.cpp
./bank_management
```

---

### 3. 📖 Library Management System
**Location:** `3_library_management/`

**Objective:** Efficiently manage books, members, and borrowing records.

**Features:**
- ✅ Book Management:
  - Add, delete, and search books
  - Search by title, author, or ID
  - Track available copies
- ✅ Member Management:
  - Register new members
  - Search and delete members
  - Track membership dates
- ✅ Borrowing Management:
  - Issue books to members
  - Return books
  - View borrowing history
  - Track overdue books
  - Auto due date calculation (15 days)
- ✅ Persistent storage for books, members, and transactions

**Technologies:** C++, Structures, File I/O, Date/Time handling

**Key Concepts:**
- Multiple file operations
- String matching and search algorithms
- Date/time management
- Multi-structure data relationships
- Complex menu systems

**Quick Start:**
```bash
cd 3_library_management
g++ -std=c++11 -o library_management library_management.cpp
./library_management
```

---

### 4. 🎮 Mini Game - Tic Tac Toe
**Location:** `4_mini_game_tictactoe/`

**Objective:** Interactive two-player Tic Tac Toe game demonstrating game logic and arrays.

**Features:**
- ✅ Two-player gameplay (X vs O)
- ✅ Dynamic 3x3 board display
- ✅ Win detection (rows, columns, diagonals)
- ✅ Draw detection
- ✅ Input validation
- ✅ Replay functionality
- ✅ Game instructions
- ✅ Beautiful formatted output

**Technologies:** C++, Arrays, Loops, Conditionals, Game Logic

**Key Concepts:**
- 2D arrays
- Game state management
- Win/loss condition detection
- User input validation
- Control flow with loops and conditionals

**Quick Start:**
```bash
cd 4_mini_game_tictactoe
g++ -std=c++11 -o tictactoe tictactoe.cpp
./tictactoe
```

---

## 📁 Project Structure

```
cpp-management-systems/
│
├── README.md (this file)
│
├── 1_student_management/
│   ├── student_management.cpp
│   ├── README.md
│   └── students.dat (created at runtime)
│
├── 2_bank_management/
│   ├── bank_management.cpp
│   ├── README.md
│   └── accounts.dat (created at runtime)
│
├── 3_library_management/
│   ├── library_management.cpp
│   ├── README.md
│   ├── books.dat (created at runtime)
│   ├── members.dat (created at runtime)
│   └── borrow_records.dat (created at runtime)
│
└── 4_mini_game_tictactoe/
    ├── tictactoe.cpp
    └── README.md
```

## 🛠️ System Requirements

- **C++ Compiler:** g++, clang++, or MSVC
- **C++ Standard:** C++11 or later
- **Operating System:** Linux, Windows (MinGW), or macOS
- **RAM:** Minimal (< 10 MB)
- **Storage:** Minimal (< 1 MB)

## 📋 Compilation Instructions

### For All Projects (Universal Method)

```bash
# Navigate to project directory
cd <project_directory>

# Compile
g++ -std=c++11 -o <output_name> <source_file.cpp>

# Execute
./<output_name>        # Linux/Mac
<output_name>.exe      # Windows
```

### Quick Compile All

```bash
# Student Management
g++ -std=c++11 -o 1_student_management/student_management 1_student_management/student_management.cpp

# Bank Management
g++ -std=c++11 -o 2_bank_management/bank_management 2_bank_management/bank_management.cpp

# Library Management
g++ -std=c++11 -o 3_library_management/library_management 3_library_management/library_management.cpp

# Tic Tac Toe
g++ -std=c++11 -o 4_mini_game_tictactoe/tictactoe 4_mini_game_tictactoe/tictactoe.cpp
```

## 🎓 Learning Outcomes

After completing these projects, you will understand:

### Fundamental Concepts
- ✅ Variables, data types, and operators
- ✅ Control structures (loops, conditionals)
- ✅ Functions and modular programming
- ✅ Arrays and data structures

### Intermediate Concepts
- ✅ Structures (structs) for organizing data
- ✅ File I/O operations (text and binary)
- ✅ String manipulation and searching
- ✅ Menu-driven applications

### Advanced Concepts
- ✅ Object-Oriented Programming (OOP)
- ✅ Classes and encapsulation
- ✅ Getter and setter methods
- ✅ Game logic and state management
- ✅ Data persistence

### Practical Skills
- ✅ Writing maintainable, modular code
- ✅ Implementing search and sort algorithms
- ✅ Error handling and validation
- ✅ User interface design
- ✅ Project organization

## 🚀 Running the Projects

### Windows (Using MinGW)

```bash
# Open Command Prompt/PowerShell
cd 1_student_management
g++ -std=c++11 -o student_management.exe student_management.cpp
student_management.exe
```

### Linux/Mac

```bash
# Open Terminal
cd 1_student_management
g++ -std=c++11 -o student_management student_management.cpp
./student_management
```

## 📊 Comparison Table

| Project | Type | Concepts | Difficulty | Time to Complete |
|---------|------|----------|-----------|------------------|
| Student Management | Console App | File I/O, Structs | Beginner | 2-3 hours |
| Bank Management | Console App | OOP, Classes, Files | Intermediate | 3-4 hours |
| Library Management | Console App | Multiple Files, Search | Intermediate | 4-5 hours |
| Tic Tac Toe | Game | Arrays, Logic, Loops | Beginner | 2-3 hours |

## 🎯 Key Features Across All Projects

### Data Persistence
- All projects use binary files for data storage
- Data survives application closure
- Efficient storage and retrieval

### User Interface
- Menu-driven navigation
- Clear, formatted output
- Input validation
- Error handling with user-friendly messages

### Code Organization
- Modular function design
- Clear variable naming
- Comprehensive comments
- Logical code structure

## 💡 Tips & Best Practices

### Before Running
1. Ensure C++ compiler is installed and in PATH
2. Navigate to the correct project directory
3. Check syntax before compilation

### During Development
1. Test each function individually
2. Validate user input thoroughly
3. Handle edge cases (empty lists, invalid IDs, etc.)
4. Test file operations carefully

### Code Improvement
1. Add more validation
2. Implement sorting functionality
3. Add data backup features
4. Create separate header files
5. Implement error logging

## 🔧 Troubleshooting

### Common Issues

**Issue:** `g++: command not found`
- **Solution:** Install MinGW (Windows) or GCC (Linux/Mac)

**Issue:** `file not found error`
- **Solution:** Ensure you're in the correct directory

**Issue:** `Permission denied`
- **Solution:** Use `chmod +x executable_name` on Linux/Mac

**Issue:** Data not saving
- **Solution:** Check write permissions in directory

## 📚 Additional Resources

- [C++ Reference](https://en.cppreference.com/)
- [File I/O in C++](https://www.cplusplus.com/doc/tutorial/files/)
- [C++ OOP Tutorial](https://www.cplusplus.com/doc/tutorial/classes/)
- [Game Programming Concepts](https://gameprogrammingpatterns.com/)

## 🌟 Enhancement Ideas

### Student Management
- Add GPA-based sorting
- Email validation
- Bulk import/export
- Attendance tracking

### Bank Management
- Transaction history
- Interest calculation
- Account types differentiation
- Multiple user authentication

### Library Management
- Fine calculation for overdue books
- Book reservations
- Automatic renewal
- Email notifications

### Tic Tac Toe
- AI opponent (minimax algorithm)
- Difficulty levels
- Score tracking
- Game timer
- GUI implementation

## 📝 Project-Specific Documentation

Each project has its own detailed README:
- [Student Management README](1_student_management/README.md)
- [Bank Management README](2_bank_management/README.md)
- [Library Management README](3_library_management/README.md)
- [Tic Tac Toe README](4_mini_game_tictactoe/README.md)

## 👨‍💻 Author
**libnaansu-hash**

## 📄 License
This project is open source and available for educational purposes.

## 🤝 Contributing
Feel free to fork this repository and submit pull requests for improvements!

## 📞 Support
For issues, questions, or suggestions, please open an issue on GitHub.

---

## 🎉 Quick Reference

### Compile All Projects (Bash/Terminal)
```bash
for dir in 1_student_management 2_bank_management 3_library_management 4_mini_game_tictactoe; do
  cd $dir
  g++ -std=c++11 -o output *.cpp
  cd ..
done
```

### Run Individual Project
```bash
cd <project_directory>
g++ -std=c++11 -o app *.cpp && ./app
```

---

**Last Updated:** June 4, 2026

**Version:** 1.0

**Status:** ✅ All 4 Projects Complete & Tested

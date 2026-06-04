# Library Management System

## Overview
A comprehensive console-based library management system that efficiently manages books, members, and borrowing records using structured programming and file handling.

## Features

### Book Management
- ✅ Add new books to library catalog
- ✅ Display all books with availability status
- ✅ Search books by:
  - Title
  - Author
  - Book ID
- ✅ Delete books from catalog
- ✅ Track total and available copies

### Member Management
- ✅ Register new library members
- ✅ Display all registered members
- ✅ Search members by ID
- ✅ Delete member records
- ✅ Track membership date

### Borrowing Management
- ✅ Issue books to members
- ✅ Return borrowed books
- ✅ View borrowing history per member
- ✅ Track overdue books
- ✅ Automatic due date calculation (15 days)
- ✅ Update book availability on issue/return

## Data Structures

### Book Structure
```cpp
struct Book {
    int bookID;              // Unique identifier
    char title[60];          // Book title
    char author[40];         // Author name
    char isbn[20];           // ISBN number
    char genre[30];          // Book genre/category
    int totalCopies;         // Total copies in library
    int availableCopies;     // Available for borrowing
    char addedDate[20];      // Date book was added
};
```

### Member Structure
```cpp
struct Member {
    int memberID;            // Unique member identifier
    char name[50];           // Member's full name
    char email[50];          // Email address
    char phone[15];          // Contact number
    char membershipDate[20]; // Date of membership
};
```

### BorrowRecord Structure
```cpp
struct BorrowRecord {
    int recordID;            // Record identifier
    int memberID;            // Member borrowing book
    int bookID;              // Book being borrowed
    char borrowDate[20];     // Date of borrowing
    char dueDate[20];        // Return due date
    char returnDate[20];     // Actual return date
    bool isReturned;         // Return status
};
```

## File Structure

- **books.dat**: Binary file storing book records
- **members.dat**: Binary file storing member information
- **borrow_records.dat**: Binary file storing borrowing transactions

## Compilation & Execution

### Linux/Mac:
```bash
cd 3_library_management
g++ -std=c++11 -o library_management library_management.cpp
./library_management
```

### Windows (MinGW):
```bash
g++ -std=c++11 -o library_management.exe library_management.cpp
library_management.exe
```

## Usage Guide

### Main Menu Options:

#### 1. Manage Books

**Add Book**
- Enter book ID, title, author
- Provide ISBN and genre
- Specify total number of copies
- System records addition date

**Display All Books**
- View all books in tabular format
- Shows ID, title, author, total copies, available copies

**Search Book**
- Three search options:
  1. Search by Title (partial matching)
  2. Search by Author (partial matching)
  3. Search by Book ID (exact match)
- Displays detailed book information

**Delete Book**
- Remove book from library catalog
- Enter book ID to delete

#### 2. Manage Members

**Register New Member**
- Assign unique member ID
- Enter name, email, phone
- System records membership date

**Display All Members**
- View all members in table format
- Shows ID, name, email, phone number

**Search Member**
- Search by member ID
- Displays member details

**Delete Member**
- Remove member from system
- Enter member ID to delete

#### 3. Manage Borrowing

**Issue Book**
- Select member and book
- System verifies:
  - Member exists
  - Book exists
  - Copies available
- Calculates due date (15 days)
- Updates book availability
- Creates borrow record

**Return Book**
- Enter member ID and book ID
- System marks book as returned
- Records return date
- Updates book availability

**View Borrow History**
- Shows all transactions for a member
- Displays borrow date, due date, return status
- Marks returned/active status

**View Overdue Books**
- Lists all unreturned books
- Shows member ID, book ID, due date
- Helps identify overdue items

## Sample Operations

### Adding a Book:
```
=== Add New Book ===
Enter Book ID: 1001
Enter Book Title: The Great Gatsby
Enter Author Name: F. Scott Fitzgerald
Enter ISBN: 978-0743273565
Enter Genre: Fiction
Enter Total Copies: 5
✅ Book added successfully!
```

### Registering a Member:
```
=== Register New Member ===
Enter Member ID: 2001
Enter Member Name: Aman Singh
Enter Email: aman@email.com
Enter Phone: 9876543210
✅ Member registered successfully!
```

### Issuing a Book:
```
=== Issue Book ===
Enter Member ID: 2001
Enter Book ID: 1001
✅ Book issued successfully!
Due Date: 19-06-2026
```

### Returning a Book:
```
=== Return Book ===
Enter Member ID: 2001
Enter Book ID: 1001
✅ Book returned successfully!
```

## Key Features

### Search Functionality
- **Flexible Search**: Partial matching for title/author
- **Exact Search**: Precise ID-based search
- **Multi-field Search**: Search across different book attributes

### Data Persistence
- All data automatically saved to binary files
- Data survives application closure
- Efficient binary format for fast access

### Dynamic Book Availability
- Automatically decrements on issue
- Automatically increments on return
- Prevents overbooking

### Automatic Date Management
- Current date captured on transactions
- Due date auto-calculated (15 days)
- Return date recorded on book return

## Error Handling
- Member existence validation
- Book existence validation
- Availability verification
- File operation error checking
- User-friendly error messages

## Learning Concepts

- **Data Structures**: Working with multiple related structures
- **File I/O**: Binary file operations and record management
- **Search Algorithms**: String matching and linear search
- **Data Persistence**: Serialization and deserialization
- **Modular Programming**: Organized function design
- **Date/Time Management**: Date handling in C++
- **User Interface**: Multi-level menu system

## Potential Enhancements

- Fine calculation for overdue books
- Book rating/review system
- Reservation functionality
- Renewal of borrowed books
- Member categories (student, faculty, staff)
- Book recommendations
- Attendance tracking
- Digital receipt generation
- Email notifications for due dates
- Database migration (SQL)

## Author
libnaansu-hash

## License
Open source - Educational purposes

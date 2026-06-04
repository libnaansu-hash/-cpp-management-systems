#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

// Structure for Book
struct Book {
    int bookID;
    char title[60];
    char author[40];
    char isbn[20];
    char genre[30];
    int totalCopies;
    int availableCopies;
    char addedDate[20];
};

// Structure for Member
struct Member {
    int memberID;
    char name[50];
    char email[50];
    char phone[15];
    char membershipDate[20];
};

// Structure for Borrowing Record
struct BorrowRecord {
    int recordID;
    int memberID;
    int bookID;
    char borrowDate[20];
    char dueDate[20];
    char returnDate[20];  // Empty if not returned
    bool isReturned;
};

const char* BOOKS_FILE = "books.dat";
const char* MEMBERS_FILE = "members.dat";
const char* BORROW_FILE = "borrow_records.dat";

// Function prototypes
void displayMainMenu();
void manageBooks();
void manageMembers();
static void manageBorrowing();

// Book Functions
void addBook();
void displayAllBooks();
void searchBook();
void updateBook();
void deleteBook();

// Member Functions
void addMember();
void displayAllMembers();
void searchMember();
void deleteMember();

// Borrowing Functions
void issueBook();
void returnBook();
void displayBorrowHistory();
void displayOverdueBooks();

// Utility Functions
void getCurrentDate(char* date);
Book* findBook(int bookID);
Member* findMember(int memberID);
void updateBookInFile(Book& book);
void updateMemberInFile(Member& member);

// Get current date
void getCurrentDate(char* date) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    strftime(date, 20, "%d-%m-%Y", timeinfo);
}

// Get due date (15 days from now)
void getDueDate(char* dueDate) {
    time_t now = time(0);
    now += (15 * 24 * 60 * 60); // Add 15 days
    tm* timeinfo = localtime(&now);
    strftime(dueDate, 20, "%d-%m-%Y", timeinfo);
}

// ============ BOOK FUNCTIONS ============

void addBook() {
    ofstream file(BOOKS_FILE, ios::app | ios::binary);
    
    if (!file) {
        cout << "\n❌ Error opening file!\n";
        return;
    }
    
    Book book;
    char date[20];
    
    cout << "\n=== Add New Book ===";
    cout << "\nEnter Book ID: ";
    cin >> book.bookID;
    cin.ignore();
    
    cout << "Enter Book Title: ";
    cin.getline(book.title, 60);
    
    cout << "Enter Author Name: ";
    cin.getline(book.author, 40);
    
    cout << "Enter ISBN: ";
    cin.getline(book.isbn, 20);
    
    cout << "Enter Genre: ";
    cin.getline(book.genre, 30);
    
    cout << "Enter Total Copies: ";
    cin >> book.totalCopies;
    
    book.availableCopies = book.totalCopies;
    getCurrentDate(date);
    strcpy(book.addedDate, date);
    
    file.write((char*)&book, sizeof(Book));
    file.close();
    
    cout << "\n✅ Book added successfully!\n";
}

void displayAllBooks() {
    ifstream file(BOOKS_FILE, ios::binary);
    
    if (!file) {
        cout << "\n❌ No books found!\n";
        return;
    }
    
    Book book;
    int count = 0;
    
    cout << "\n=== All Books in Library ===";
    cout << "\n" << setw(6) << "ID" << setw(25) << "Title" << setw(18) << "Author" 
         << setw(8) << "Total" << setw(8) << "Avail" << "\n";
    cout << string(65, '-') << "\n";
    
    while (file.read((char*)&book, sizeof(Book))) {
        cout << setw(6) << book.bookID
             << setw(25) << book.title
             << setw(18) << book.author
             << setw(8) << book.totalCopies
             << setw(8) << book.availableCopies << "\n";
        count++;
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No books found!\n";
    } else {
        cout << string(65, '-') << "\n";
        cout << "Total Books: " << count << "\n";
    }
}

void searchBook() {
    ifstream file(BOOKS_FILE, ios::binary);
    
    if (!file) {
        cout << "\n❌ No books found!\n";
        return;
    }
    
    cout << "\n=== Search Book ===";
    cout << "\n1. Search by Title\n2. Search by Author\n3. Search by ID\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    cin.ignore();
    
    Book book;
    bool found = false;
    
    if (choice == 1) {
        char searchTitle[60];
        cout << "Enter Book Title: ";
        cin.getline(searchTitle, 60);
        
        while (file.read((char*)&book, sizeof(Book))) {
            if (strstr(book.title, searchTitle) != nullptr) {
                if (!found) {
                    cout << "\n✅ Book(s) Found!\n";
                    cout << "\n" << setw(6) << "ID" << setw(25) << "Title" << setw(18) << "Author" 
                         << setw(12) << "Available" << "\n";
                    cout << string(61, '-') << "\n";
                    found = true;
                }
                cout << setw(6) << book.bookID
                     << setw(25) << book.title
                     << setw(18) << book.author
                     << setw(12) << book.availableCopies << "\n";
            }
        }
    }
    else if (choice == 2) {
        char searchAuthor[40];
        cout << "Enter Author Name: ";
        cin.getline(searchAuthor, 40);
        
        file.clear();
        file.seekg(0);
        
        while (file.read((char*)&book, sizeof(Book))) {
            if (strstr(book.author, searchAuthor) != nullptr) {
                if (!found) {
                    cout << "\n✅ Book(s) Found!\n";
                    cout << "\n" << setw(6) << "ID" << setw(25) << "Title" << setw(18) << "Author" 
                         << setw(12) << "Available" << "\n";
                    cout << string(61, '-') << "\n";
                    found = true;
                }
                cout << setw(6) << book.bookID
                     << setw(25) << book.title
                     << setw(18) << book.author
                     << setw(12) << book.availableCopies << "\n";
            }
        }
    }
    else if (choice == 3) {
        int bookID;
        cout << "Enter Book ID: ";
        cin >> bookID;
        
        file.clear();
        file.seekg(0);
        
        while (file.read((char*)&book, sizeof(Book))) {
            if (book.bookID == bookID) {
                cout << "\n✅ Book Found!\n";
                cout << "ID: " << book.bookID << "\n";
                cout << "Title: " << book.title << "\n";
                cout << "Author: " << book.author << "\n";
                cout << "ISBN: " << book.isbn << "\n";
                cout << "Genre: " << book.genre << "\n";
                cout << "Total Copies: " << book.totalCopies << "\n";
                cout << "Available: " << book.availableCopies << "\n";
                found = true;
                break;
            }
        }
    }
    
    file.close();
    
    if (!found) {
        cout << "\n❌ No books found matching your search!\n";
    }
}

Book* findBook(int bookID) {
    ifstream file(BOOKS_FILE, ios::binary);
    
    if (!file) return nullptr;
    
    Book* book = new Book();
    
    while (file.read((char*)book, sizeof(Book))) {
        if (book->bookID == bookID) {
            file.close();
            return book;
        }
    }
    
    file.close();
    delete book;
    return nullptr;
}

void updateBookInFile(Book& book) {
    fstream file(BOOKS_FILE, ios::in | ios::out | ios::binary);
    
    if (!file) return;
    
    Book temp;
    int pos = 0;
    
    while (file.read((char*)&temp, sizeof(Book))) {
        if (temp.bookID == book.bookID) {
            file.seekp(pos);
            file.write((char*)&book, sizeof(Book));
            file.close();
            return;
        }
        pos = file.tellg();
    }
    
    file.close();
}

void deleteBook() {
    ifstream infile(BOOKS_FILE, ios::binary);
    ofstream tempfile("temp_books.dat", ios::binary);
    
    if (!infile || !tempfile) {
        cout << "\n❌ Error opening files!\n";
        return;
    }
    
    int bookID;
    cout << "\n=== Delete Book ===";
    cout << "\nEnter Book ID to Delete: ";
    cin >> bookID;
    
    Book book;
    bool found = false;
    
    while (infile.read((char*)&book, sizeof(Book))) {
        if (book.bookID != bookID) {
            tempfile.write((char*)&book, sizeof(Book));
        } else {
            found = true;
        }
    }
    
    infile.close();
    tempfile.close();
    
    if (found) {
        remove(BOOKS_FILE);
        rename("temp_books.dat", BOOKS_FILE);
        cout << "\n✅ Book deleted successfully!\n";
    } else {
        remove("temp_books.dat");
        cout << "\n❌ Book not found!\n";
    }
}

// ============ MEMBER FUNCTIONS ============

void addMember() {
    ofstream file(MEMBERS_FILE, ios::app | ios::binary);
    
    if (!file) {
        cout << "\n❌ Error opening file!\n";
        return;
    }
    
    Member member;
    char date[20];
    
    cout << "\n=== Register New Member ===";
    cout << "\nEnter Member ID: ";
    cin >> member.memberID;
    cin.ignore();
    
    cout << "Enter Member Name: ";
    cin.getline(member.name, 50);
    
    cout << "Enter Email: ";
    cin.getline(member.email, 50);
    
    cout << "Enter Phone: ";
    cin.getline(member.phone, 15);
    
    getCurrentDate(date);
    strcpy(member.membershipDate, date);
    
    file.write((char*)&member, sizeof(Member));
    file.close();
    
    cout << "\n✅ Member registered successfully!\n";
}

void displayAllMembers() {
    ifstream file(MEMBERS_FILE, ios::binary);
    
    if (!file) {
        cout << "\n❌ No members found!\n";
        return;
    }
    
    Member member;
    int count = 0;
    
    cout << "\n=== All Library Members ===";
    cout << "\n" << setw(6) << "ID" << setw(25) << "Name" << setw(20) << "Email" << setw(12) << "Phone" << "\n";
    cout << string(63, '-') << "\n";
    
    while (file.read((char*)&member, sizeof(Member))) {
        cout << setw(6) << member.memberID
             << setw(25) << member.name
             << setw(20) << member.email
             << setw(12) << member.phone << "\n";
        count++;
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No members found!\n";
    } else {
        cout << string(63, '-') << "\n";
        cout << "Total Members: " << count << "\n";
    }
}

void searchMember() {
    ifstream file(MEMBERS_FILE, ios::binary);
    
    if (!file) {
        cout << "\n❌ No members found!\n";
        return;
    }
    
    int memberID;
    cout << "\n=== Search Member ===";
    cout << "\nEnter Member ID: ";
    cin >> memberID;
    
    Member member;
    bool found = false;
    
    while (file.read((char*)&member, sizeof(Member))) {
        if (member.memberID == memberID) {
            found = true;
            cout << "\n✅ Member Found!\n";
            cout << "ID: " << member.memberID << "\n";
            cout << "Name: " << member.name << "\n";
            cout << "Email: " << member.email << "\n";
            cout << "Phone: " << member.phone << "\n";
            cout << "Member Since: " << member.membershipDate << "\n";
            break;
        }
    }
    
    file.close();
    
    if (!found) {
        cout << "\n❌ Member not found!\n";
    }
}

Member* findMember(int memberID) {
    ifstream file(MEMBERS_FILE, ios::binary);
    
    if (!file) return nullptr;
    
    Member* member = new Member();
    
    while (file.read((char*)member, sizeof(Member))) {
        if (member->memberID == memberID) {
            file.close();
            return member;
        }
    }
    
    file.close();
    delete member;
    return nullptr;
}

void deleteMember() {
    ifstream infile(MEMBERS_FILE, ios::binary);
    ofstream tempfile("temp_members.dat", ios::binary);
    
    if (!infile || !tempfile) {
        cout << "\n❌ Error opening files!\n";
        return;
    }
    
    int memberID;
    cout << "\n=== Delete Member ===";
    cout << "\nEnter Member ID to Delete: ";
    cin >> memberID;
    
    Member member;
    bool found = false;
    
    while (infile.read((char*)&member, sizeof(Member))) {
        if (member.memberID != memberID) {
            tempfile.write((char*)&member, sizeof(Member));
        } else {
            found = true;
        }
    }
    
    infile.close();
    tempfile.close();
    
    if (found) {
        remove(MEMBERS_FILE);
        rename("temp_members.dat", MEMBERS_FILE);
        cout << "\n✅ Member deleted successfully!\n";
    } else {
        remove("temp_members.dat");
        cout << "\n❌ Member not found!\n";
    }
}

// ============ BORROWING FUNCTIONS ============

void issueBook() {
    ofstream file(BORROW_FILE, ios::app | ios::binary);
    
    if (!file) {
        cout << "\n❌ Error opening file!\n";
        return;
    }
    
    int memberID, bookID;
    char borrowDate[20], dueDate[20];
    
    cout << "\n=== Issue Book ===";
    cout << "\nEnter Member ID: ";
    cin >> memberID;
    
    Member* member = findMember(memberID);
    if (!member) {
        cout << "\n❌ Member not found!\n";
        return;
    }
    delete member;
    
    cout << "Enter Book ID: ";
    cin >> bookID;
    
    Book* book = findBook(bookID);
    if (!book) {
        cout << "\n❌ Book not found!\n";
        return;
    }
    
    if (book->availableCopies <= 0) {
        cout << "\n❌ Book not available!\n";
        delete book;
        return;
    }
    
    // Create borrow record
    BorrowRecord record;
    record.recordID = 1; // Simple ID
    record.memberID = memberID;
    record.bookID = bookID;
    record.isReturned = false;
    
    getCurrentDate(borrowDate);
    getDueDate(dueDate);
    
    strcpy(record.borrowDate, borrowDate);
    strcpy(record.dueDate, dueDate);
    strcpy(record.returnDate, "");
    
    // Update book availability
    book->availableCopies--;
    updateBookInFile(*book);
    
    // Write borrow record
    file.write((char*)&record, sizeof(BorrowRecord));
    file.close();
    
    cout << "\n✅ Book issued successfully!\n";
    cout << "Due Date: " << dueDate << "\n";
    
    delete book;
}

void returnBook() {
    ifstream infile(BORROW_FILE, ios::binary);
    ofstream tempfile("temp_borrow.dat", ios::binary);
    
    if (!infile || !tempfile) {
        cout << "\n❌ Error opening files!\n";
        return;
    }
    
    int memberID, bookID;
    char returnDate[20];
    
    cout << "\n=== Return Book ===";
    cout << "\nEnter Member ID: ";
    cin >> memberID;
    cout << "Enter Book ID: ";
    cin >> bookID;
    
    BorrowRecord record;
    bool found = false;
    
    while (infile.read((char*)&record, sizeof(BorrowRecord))) {
        if (record.memberID == memberID && record.bookID == bookID && !record.isReturned) {
            found = true;
            record.isReturned = true;
            getCurrentDate(returnDate);
            strcpy(record.returnDate, returnDate);
        }
        tempfile.write((char*)&record, sizeof(BorrowRecord));
    }
    
    infile.close();
    tempfile.close();
    
    if (found) {
        remove(BORROW_FILE);
        rename("temp_borrow.dat", BORROW_FILE);
        
        // Update book availability
        Book* book = findBook(bookID);
        if (book) {
            book->availableCopies++;
            updateBookInFile(*book);
            delete book;
        }
        
        cout << "\n✅ Book returned successfully!\n";
    } else {
        remove("temp_borrow.dat");
        cout << "\n❌ Record not found!\n";
    }
}

void displayBorrowHistory() {
    ifstream file(BORROW_FILE, ios::binary);
    
    if (!file) {
        cout << "\n❌ No borrow records found!\n";
        return;
    }
    
    int memberID;
    cout << "\n=== Borrow History ===";
    cout << "\nEnter Member ID: ";
    cin >> memberID;
    
    BorrowRecord record;
    int count = 0;
    
    cout << "\n" << setw(8) << "BookID" << setw(20) << "Borrow Date" << setw(15) << "Due Date" 
         << setw(15) << "Return Date" << setw(8) << "Status" << "\n";
    cout << string(66, '-') << "\n";
    
    while (file.read((char*)&record, sizeof(BorrowRecord))) {
        if (record.memberID == memberID) {
            cout << setw(8) << record.bookID
                 << setw(20) << record.borrowDate
                 << setw(15) << record.dueDate
                 << setw(15) << (record.isReturned ? record.returnDate : "Not Returned")
                 << setw(8) << (record.isReturned ? "Done" : "Active") << "\n";
            count++;
        }
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No borrowing history found!\n";
    } else {
        cout << string(66, '-') << "\n";
        cout << "Total Records: " << count << "\n";
    }
}

void displayOverdueBooks() {
    ifstream file(BORROW_FILE, ios::binary);
    
    if (!file) {
        cout << "\n❌ No borrow records found!\n";
        return;
    }
    
    cout << "\n=== Overdue Books ===";
    cout << "\n" << setw(8) << "MemberID" << setw(8) << "BookID" << setw(15) << "Due Date" << "\n";
    cout << string(31, '-') << "\n";
    
    BorrowRecord record;
    int count = 0;
    
    while (file.read((char*)&record, sizeof(BorrowRecord))) {
        if (!record.isReturned) {
            cout << setw(8) << record.memberID
                 << setw(8) << record.bookID
                 << setw(15) << record.dueDate << "\n";
            count++;
        }
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No overdue books!\n";
    } else {
        cout << string(31, '-') << "\n";
        cout << "Total Overdue: " << count << "\n";
    }
}

// ============ MENU FUNCTIONS ============

void manageBooks() {
    int choice;
    
    while (true) {
        cout << "\n╔══════════════════════════════════════╗\n";
        cout << "║  Book Management                      ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║  1. Add Book                           ║\n";
        cout << "║  2. Display All Books                  ║\n";
        cout << "║  3. Search Book                        ║\n";
        cout << "║  4. Delete Book                        ║\n";
        cout << "║  5. Back to Main Menu                  ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayAllBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: return;
            default: cout << "\n❌ Invalid choice!\n";
        }
    }
}

void manageMembers() {
    int choice;
    
    while (true) {
        cout << "\n╔══════════════════════════════════════╗\n";
        cout << "║  Member Management                    ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║  1. Register New Member                ║\n";
        cout << "║  2. Display All Members                ║\n";
        cout << "║  3. Search Member                      ║\n";
        cout << "║  4. Delete Member                      ║\n";
        cout << "║  5. Back to Main Menu                  ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addMember(); break;
            case 2: displayAllMembers(); break;
            case 3: searchMember(); break;
            case 4: deleteMember(); break;
            case 5: return;
            default: cout << "\n❌ Invalid choice!\n";
        }
    }
}

void manageBorrowing() {
    int choice;
    
    while (true) {
        cout << "\n╔══════════════════════════════════════╗\n";
        cout << "║  Borrowing Management                 ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║  1. Issue Book                         ║\n";
        cout << "║  2. Return Book                        ║\n";
        cout << "║  3. View Borrow History                ║\n";
        cout << "║  4. View Overdue Books                 ║\n";
        cout << "║  5. Back to Main Menu                  ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: issueBook(); break;
            case 2: returnBook(); break;
            case 3: displayBorrowHistory(); break;
            case 4: displayOverdueBooks(); break;
            case 5: return;
            default: cout << "\n❌ Invalid choice!\n";
        }
    }
}

void displayMainMenu() {
    int choice;
    
    while (true) {
        cout << "\n╔══════════════════════════════════════╗\n";
        cout << "║  Library Management System            ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║  1. Manage Books                       ║\n";
        cout << "║  2. Manage Members                     ║\n";
        cout << "║  3. Manage Borrowing                   ║\n";
        cout << "║  4. Exit                               ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: manageBooks(); break;
            case 2: manageMembers(); break;
            case 3: manageBorrowing(); break;
            case 4:
                cout << "\n👋 Thank you for using Library Management System!\n";
                return;
            default: cout << "\n❌ Invalid choice!\n";
        }
    }
}

int main() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║  Welcome to Library Management System ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    displayMainMenu();
    
    return 0;
}

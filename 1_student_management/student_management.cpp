#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Structure to store student data
struct Student {
    int id;
    char name[50];
    char email[50];
    float gpa;
    char phone[15];
};

const char* FILENAME = "students.dat";

// Function prototypes
void addStudent();
void displayAllStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void displayMenu();

// Function to add a new student
void addStudent() {
    ofstream file(FILENAME, ios::app | ios::binary);
    
    if (!file) {
        cout << "\n❌ Error opening file!\n";
        return;
    }
    
    Student student;
    
    cout << "\n=== Add New Student ===";
    cout << "\nEnter Student ID: ";
    cin >> student.id;
    cin.ignore();
    
    cout << "Enter Student Name: ";
    cin.getline(student.name, 50);
    
    cout << "Enter Email: ";
    cin.getline(student.email, 50);
    
    cout << "Enter GPA (0.0 - 4.0): ";
    cin >> student.gpa;
    cin.ignore();
    
    cout << "Enter Phone Number: ";
    cin.getline(student.phone, 15);
    
    file.write((char*)&student, sizeof(Student));
    file.close();
    
    cout << "\n✅ Student added successfully!\n";
}

// Function to display all students
void displayAllStudents() {
    ifstream file(FILENAME, ios::binary);
    
    if (!file) {
        cout << "\n❌ No student records found!\n";
        return;
    }
    
    Student student;
    int count = 0;
    
    cout << "\n=== All Student Records ===";
    cout << "\n" << setw(5) << "ID" << setw(20) << "Name" << setw(25) << "Email" 
         << setw(8) << "GPA" << setw(15) << "Phone" << "\n";
    cout << string(73, '-') << "\n";
    
    while (file.read((char*)&student, sizeof(Student))) {
        cout << setw(5) << student.id 
             << setw(20) << student.name 
             << setw(25) << student.email 
             << setw(8) << student.gpa 
             << setw(15) << student.phone << "\n";
        count++;
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No records found!\n";
    } else {
        cout << string(73, '-') << "\n";
        cout << "Total Students: " << count << "\n";
    }
}

// Function to search for a student by ID
void searchStudent() {
    ifstream file(FILENAME, ios::binary);
    
    if (!file) {
        cout << "\n❌ No student records found!\n";
        return;
    }
    
    int searchID;
    cout << "\n=== Search Student ===";
    cout << "\nEnter Student ID to search: ";
    cin >> searchID;
    
    Student student;
    bool found = false;
    
    while (file.read((char*)&student, sizeof(Student))) {
        if (student.id == searchID) {
            found = true;
            cout << "\n✅ Student Found!\n";
            cout << "ID: " << student.id << "\n";
            cout << "Name: " << student.name << "\n";
            cout << "Email: " << student.email << "\n";
            cout << "GPA: " << student.gpa << "\n";
            cout << "Phone: " << student.phone << "\n";
            break;
        }
    }
    
    if (!found) {
        cout << "\n❌ Student with ID " << searchID << " not found!\n";
    }
    
    file.close();
}

// Function to update a student's information
void updateStudent() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    
    if (!file) {
        cout << "\n❌ No student records found!\n";
        return;
    }
    
    int searchID;
    cout << "\n=== Update Student ===";
    cout << "\nEnter Student ID to update: ";
    cin >> searchID;
    cin.ignore();
    
    Student student;
    bool found = false;
    int pos = 0;
    
    while (file.read((char*)&student, sizeof(Student))) {
        if (student.id == searchID) {
            found = true;
            cout << "\n✅ Student Found!\n";
            cout << "\nEnter New Name: ";
            cin.getline(student.name, 50);
            
            cout << "Enter New Email: ";
            cin.getline(student.email, 50);
            
            cout << "Enter New GPA: ";
            cin >> student.gpa;
            cin.ignore();
            
            cout << "Enter New Phone Number: ";
            cin.getline(student.phone, 15);
            
            // Write back to file
            file.seekp(pos);
            file.write((char*)&student, sizeof(Student));
            cout << "\n✅ Student updated successfully!\n";
            break;
        }
        pos = file.tellg();
    }
    
    if (!found) {
        cout << "\n❌ Student with ID " << searchID << " not found!\n";
    }
    
    file.close();
}

// Function to delete a student
void deleteStudent() {
    ifstream infile(FILENAME, ios::binary);
    ofstream tempfile("temp.dat", ios::binary);
    
    if (!infile || !tempfile) {
        cout << "\n❌ Error opening files!\n";
        return;
    }
    
    int searchID;
    cout << "\n=== Delete Student ===";
    cout << "\nEnter Student ID to delete: ";
    cin >> searchID;
    
    Student student;
    bool found = false;
    
    while (infile.read((char*)&student, sizeof(Student))) {
        if (student.id != searchID) {
            tempfile.write((char*)&student, sizeof(Student));
        } else {
            found = true;
        }
    }
    
    infile.close();
    tempfile.close();
    
    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        cout << "\n✅ Student deleted successfully!\n";
    } else {
        remove("temp.dat");
        cout << "\n❌ Student with ID " << searchID << " not found!\n";
    }
}

// Function to display menu
void displayMenu() {
    cout << "\n╔════════════════════════════════════╗\n";
    cout << "║  Student Management System        ║\n";
    cout << "╠════════════════════════════════════╣\n";
    cout << "║  1. Add Student                    ║\n";
    cout << "║  2. Display All Students           ║\n";
    cout << "║  3. Search Student                 ║\n";
    cout << "║  4. Update Student                 ║\n";
    cout << "║  5. Delete Student                 ║\n";
    cout << "║  6. Exit                           ║\n";
    cout << "╚════════════════════════════════════╝\n";
    cout << "\nEnter your choice (1-6): ";
}

// Main function
int main() {
    int choice;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "\n👋 Thank you for using Student Management System!\n";
                return 0;
            default:
                cout << "\n❌ Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }
    
    return 0;
}

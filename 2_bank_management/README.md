# Bank Management Application

## Overview
A comprehensive console-based banking system that simulates real-world banking operations using Object-Oriented Programming principles and file handling for persistent data storage.

## Features
- ✅ Create new customer accounts
- ✅ Deposit funds with validation
- ✅ Withdraw funds with balance verification
- ✅ Check account balance
- ✅ View complete account details
- ✅ Transfer money between accounts
- ✅ List all accounts with summary
- ✅ Delete accounts
- ✅ Persistent account data storage
- ✅ Secure file-based database
- ✅ User-friendly interface

## Class Structure

### BankAccount Class

**Private Members:**
- `int accountNumber` - Unique account identifier
- `char customerName[50]` - Customer's full name
- `char email[50]` - Customer's email address
- `double balance` - Current account balance
- `char accountType[20]` - Type (Savings/Checking)
- `char createdDate[20]` - Account creation date

**Public Methods:**
- `deposit(double amount)` - Add funds to account
- `withdraw(double amount)` - Remove funds from account
- `checkBalance()` - Display current balance
- `displayAccountDetails()` - Show all account information
- Getter and setter methods for all attributes

## Data Persistence
- **File**: `accounts.dat` (binary file)
- **Format**: Serialized BankAccount objects
- **Benefits**: Fast I/O, space-efficient, secure

## Compilation & Execution

### Linux/Mac:
```bash
cd 2_bank_management
g++ -std=c++11 -o bank_management bank_management.cpp
./bank_management
```

### Windows (MinGW):
```bash
g++ -std=c++11 -o bank_management.exe bank_management.cpp
bank_management.exe
```

## Usage Guide

### Menu Operations:

**1. Create New Account**
- Enter account number (unique identifier)
- Provide customer name
- Enter email address
- Choose account type (Savings or Checking)
- Set initial deposit amount
- Account is created with current date

**2. Deposit Money**
- Enter account number
- Specify amount to deposit
- Balance is updated immediately
- Changes saved to file

**3. Withdraw Money**
- Enter account number
- Enter withdrawal amount
- System validates sufficient balance
- Transaction is processed and saved

**4. Check Balance**
- Enter account number
- View current balance
- Quick balance inquiry

**5. View Account Details**
- Enter account number
- Display:
  - Account number
  - Customer name
  - Email
  - Account type
  - Current balance
  - Creation date

**6. Transfer Money**
- Enter source account number
- Enter destination account number
- Specify transfer amount
- System validates and processes transfer
- Both accounts updated

**7. List All Accounts**
- View all accounts in tabular format
- Shows:
  - Account numbers
  - Customer names
  - Account types
  - Current balances
  - Creation dates
- Total account count displayed

**8. Delete Account**
- Enter account number to delete
- Account is permanently removed
- File is updated accordingly

**9. Exit**
- Closes the application
- All data preserved

## Sample Output

```
╔════════════════════════════════════════╗
║   Welcome to Bank Management System    ║
╚════════════════════════════════════════╝

╔════════════════════════════════════════╗
║    Bank Management System              ║
╠════════════════════════════════════════╣
║  1. Create New Account                 ║
║  2. Deposit Money                      ║
║  3. Withdraw Money                     ║
║  4. Check Balance                      ║
║  5. View Account Details               ║
║  6. Transfer Money                     ║
║  7. List All Accounts                  ║
║  8. Delete Account                     ║
║  9. Exit                               ║
╚════════════════════════════════════════╝

=== Create New Account ===
Enter Account Number: 1001
Enter Customer Name: John Doe
Enter Email: john@bank.com
Enter Account Type (Savings/Checking): Savings
Enter Initial Balance: ₹50000

✅ Account created successfully!

=== Account Details ===
Account Number: 1001
Customer Name: John Doe
Email: john@bank.com
Account Type: Savings
Balance: ₹50000.00
Created Date: 04-06-2026
```

## Key OOP Concepts Demonstrated

### 1. Encapsulation
- Private member variables
- Public getter/setter methods
- Data protection and validation

### 2. Data Abstraction
- Complex operations abstracted into methods
- Users don't need to know internal implementation
- Clean, intuitive interface

### 3. File Persistence
- Serialize objects to binary file
- Deserialize objects from file
- Maintain data across sessions

### 4. Error Handling
- Balance validation
- Amount validation
- File operation error checks
- User-friendly error messages

## Security Features
- Binary file format (not easily readable as text)
- Account number uniqueness
- Balance verification before withdrawals
- Data persistence prevents loss

## Performance Characteristics
- **Create Account**: O(1) - Simple append operation
- **Find Account**: O(n) - Linear search through file
- **Update Account**: O(n) - Find then update
- **Delete Account**: O(n) - Rewrite file without account

## Potential Enhancements
- Transaction history logging
- Interest calculation
- Account freeze/lock functionality
- PIN/Password protection
- Multi-user authentication
- Transaction reports
- Monthly statement generation
- Account overdraft facility
- Minimum balance enforcement

## Learning Outcomes
- **Object-Oriented Programming**: Class design, encapsulation
- **File I/O**: Binary file operations
- **Data Management**: Persistent storage
- **Error Handling**: Validation and exception handling
- **Data Structures**: Organizing account information
- **User Interface**: Menu-driven design

## Author
libnaansu-hash

## License
Open source - Educational purposes

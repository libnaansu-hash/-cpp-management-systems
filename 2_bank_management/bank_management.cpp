#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

// Class to represent a Bank Account
class BankAccount {
private:
    int accountNumber;
    char customerName[50];
    char email[50];
    double balance;
    char accountType[20]; // Savings or Checking
    char createdDate[20];

public:
    BankAccount() {
        accountNumber = 0;
        balance = 0.0;
        strcpy(accountType, "");
        strcpy(customerName, "");
        strcpy(email, "");
        strcpy(createdDate, "");
    }

    // Getters
    int getAccountNumber() { return accountNumber; }
    char* getCustomerName() { return customerName; }
    char* getEmail() { return email; }
    double getBalance() { return balance; }
    char* getAccountType() { return accountType; }
    char* getCreatedDate() { return createdDate; }

    // Setters
    void setAccountNumber(int acc) { accountNumber = acc; }
    void setCustomerName(char* name) { strcpy(customerName, name); }
    void setEmail(char* em) { strcpy(email, em); }
    void setBalance(double bal) { balance = bal; }
    void setAccountType(char* type) { strcpy(accountType, type); }
    void setCreatedDate(char* date) { strcpy(createdDate, date); }

    // Deposit money
    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "\n❌ Invalid amount! Deposit must be greater than 0.\n";
            return false;
        }
        balance += amount;
        cout << "\n✅ Deposit successful! New Balance: ₹" << fixed << setprecision(2) << balance << "\n";
        return true;
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "\n❌ Invalid amount! Withdrawal must be greater than 0.\n";
            return false;
        }
        if (amount > balance) {
            cout << "\n❌ Insufficient balance! Current balance: ₹" << fixed << setprecision(2) << balance << "\n";
            return false;
        }
        balance -= amount;
        cout << "\n✅ Withdrawal successful! New Balance: ₹" << fixed << setprecision(2) << balance << "\n";
        return true;
    }

    // Check balance
    void checkBalance() {
        cout << "\n=== Account Balance ===";
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCustomer Name: " << customerName;
        cout << "\nCurrent Balance: ₹" << fixed << setprecision(2) << balance << "\n";
    }

    // Display account details
    void displayAccountDetails() {
        cout << "\n=== Account Details ===";
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCustomer Name: " << customerName;
        cout << "\nEmail: " << email;
        cout << "\nAccount Type: " << accountType;
        cout << "\nBalance: ₹" << fixed << setprecision(2) << balance;
        cout << "\nCreated Date: " << createdDate << "\n";
    }
};

const char* FILENAME = "accounts.dat";

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccountDetails();
void transferMoney();
void listAllAccounts();
void deleteAccount();
void displayMenu();
BankAccount* findAccount(int accNumber);

// Function to get current date
void getCurrentDate(char* date) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    strftime(date, 20, "%d-%m-%Y", timeinfo);
}

// Function to create a new account
void createAccount() {
    ofstream file(FILENAME, ios::app | ios::binary);
    
    if (!file) {
        cout << "\n❌ Error opening file!\n";
        return;
    }
    
    BankAccount account;
    int accNum;
    char name[50], email[50], type[20], date[20];
    double initialBalance;
    
    cout << "\n=== Create New Account ===";
    cout << "\nEnter Account Number: ";
    cin >> accNum;
    cin.ignore();
    
    cout << "Enter Customer Name: ";
    cin.getline(name, 50);
    
    cout << "Enter Email: ";
    cin.getline(email, 50);
    
    cout << "Enter Account Type (Savings/Checking): ";
    cin.getline(type, 20);
    
    cout << "Enter Initial Balance: ₹";
    cin >> initialBalance;
    
    getCurrentDate(date);
    
    account.setAccountNumber(accNum);
    account.setCustomerName(name);
    account.setEmail(email);
    account.setAccountType(type);
    account.setBalance(initialBalance);
    account.setCreatedDate(date);
    
    file.write((char*)&account, sizeof(BankAccount));
    file.close();
    
    cout << "\n✅ Account created successfully!\n";
    account.displayAccountDetails();
}

// Function to find an account
BankAccount* findAccount(int accNumber) {
    ifstream file(FILENAME, ios::binary);
    
    if (!file) {
        return nullptr;
    }
    
    BankAccount* account = new BankAccount();
    
    while (file.read((char*)account, sizeof(BankAccount))) {
        if (account->getAccountNumber() == accNumber) {
            file.close();
            return account;
        }
    }
    
    file.close();
    delete account;
    return nullptr;
}

// Function to update account in file
void updateAccountInFile(BankAccount& account) {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    
    if (!file) {
        cout << "\n❌ Error opening file!\n";
        return;
    }
    
    BankAccount temp;
    int pos = 0;
    
    while (file.read((char*)&temp, sizeof(BankAccount))) {
        if (temp.getAccountNumber() == account.getAccountNumber()) {
            file.seekp(pos);
            file.write((char*)&account, sizeof(BankAccount));
            file.close();
            return;
        }
        pos = file.tellg();
    }
    
    file.close();
}

// Function to deposit money
void deposit() {
    int accNum;
    double amount;
    
    cout << "\n=== Deposit Money ===";
    cout << "\nEnter Account Number: ";
    cin >> accNum;
    
    BankAccount* account = findAccount(accNum);
    
    if (!account) {
        cout << "\n❌ Account not found!\n";
        return;
    }
    
    cout << "Enter Amount to Deposit: ₹";
    cin >> amount;
    
    account->deposit(amount);
    updateAccountInFile(*account);
    
    delete account;
}

// Function to withdraw money
void withdraw() {
    int accNum;
    double amount;
    
    cout << "\n=== Withdraw Money ===";
    cout << "\nEnter Account Number: ";
    cin >> accNum;
    
    BankAccount* account = findAccount(accNum);
    
    if (!account) {
        cout << "\n❌ Account not found!\n";
        return;
    }
    
    cout << "Enter Amount to Withdraw: ₹";
    cin >> amount;
    
    account->withdraw(amount);
    updateAccountInFile(*account);
    
    delete account;
}

// Function to check balance
void checkBalance() {
    int accNum;
    
    cout << "\n=== Check Balance ===";
    cout << "\nEnter Account Number: ";
    cin >> accNum;
    
    BankAccount* account = findAccount(accNum);
    
    if (!account) {
        cout << "\n❌ Account not found!\n";
        return;
    }
    
    account->checkBalance();
    delete account;
}

// Function to display account details
void displayAccountDetails() {
    int accNum;
    
    cout << "\n=== Display Account Details ===";
    cout << "\nEnter Account Number: ";
    cin >> accNum;
    
    BankAccount* account = findAccount(accNum);
    
    if (!account) {
        cout << "\n❌ Account not found!\n";
        return;
    }
    
    account->displayAccountDetails();
    delete account;
}

// Function to transfer money between accounts
void transferMoney() {
    int fromAccNum, toAccNum;
    double amount;
    
    cout << "\n=== Transfer Money ===";
    cout << "\nEnter From Account Number: ";
    cin >> fromAccNum;
    
    BankAccount* fromAccount = findAccount(fromAccNum);
    if (!fromAccount) {
        cout << "\n❌ Source account not found!\n";
        return;
    }
    
    cout << "Enter To Account Number: ";
    cin >> toAccNum;
    
    BankAccount* toAccount = findAccount(toAccNum);
    if (!toAccount) {
        cout << "\n❌ Destination account not found!\n";
        delete fromAccount;
        return;
    }
    
    cout << "Enter Amount to Transfer: ₹";
    cin >> amount;
    
    if (fromAccount->getBalance() < amount) {
        cout << "\n❌ Insufficient balance!\n";
    } else {
        fromAccount->withdraw(amount);
        toAccount->deposit(amount);
        
        updateAccountInFile(*fromAccount);
        updateAccountInFile(*toAccount);
        
        cout << "\n✅ Transfer successful!\n";
    }
    
    delete fromAccount;
    delete toAccount;
}

// Function to list all accounts
void listAllAccounts() {
    ifstream file(FILENAME, ios::binary);
    
    if (!file) {
        cout << "\n❌ No accounts found!\n";
        return;
    }
    
    BankAccount account;
    int count = 0;
    
    cout << "\n=== All Bank Accounts ===";
    cout << "\n" << setw(8) << "Acc#" << setw(18) << "Name" << setw(15) << "Type" 
         << setw(15) << "Balance" << setw(12) << "Created" << "\n";
    cout << string(68, '-') << "\n";
    
    while (file.read((char*)&account, sizeof(BankAccount))) {
        cout << setw(8) << account.getAccountNumber()
             << setw(18) << account.getCustomerName()
             << setw(15) << account.getAccountType()
             << "₹" << setw(13) << fixed << setprecision(2) << account.getBalance()
             << setw(12) << account.getCreatedDate() << "\n";
        count++;
    }
    
    file.close();
    
    if (count == 0) {
        cout << "No accounts found!\n";
    } else {
        cout << string(68, '-') << "\n";
        cout << "Total Accounts: " << count << "\n";
    }
}

// Function to delete account
void deleteAccount() {
    ifstream infile(FILENAME, ios::binary);
    ofstream tempfile("temp.dat", ios::binary);
    
    if (!infile || !tempfile) {
        cout << "\n❌ Error opening files!\n";
        return;
    }
    
    int accNum;
    cout << "\n=== Delete Account ===";
    cout << "\nEnter Account Number to Delete: ";
    cin >> accNum;
    
    BankAccount account;
    bool found = false;
    
    while (infile.read((char*)&account, sizeof(BankAccount))) {
        if (account.getAccountNumber() != accNum) {
            tempfile.write((char*)&account, sizeof(BankAccount));
        } else {
            found = true;
        }
    }
    
    infile.close();
    tempfile.close();
    
    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        cout << "\n✅ Account deleted successfully!\n";
    } else {
        remove("temp.dat");
        cout << "\n❌ Account with number " << accNum << " not found!\n";
    }
}

// Function to display menu
void displayMenu() {
    cout << "\n╔════════════════════════════════════════╗\n";
    cout << "║    Bank Management System              ║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║  1. Create New Account                 ║\n";
    cout << "║  2. Deposit Money                      ║\n";
    cout << "║  3. Withdraw Money                     ║\n";
    cout << "║  4. Check Balance                      ║\n";
    cout << "║  5. View Account Details               ║\n";
    cout << "║  6. Transfer Money                     ║\n";
    cout << "║  7. List All Accounts                  ║\n";
    cout << "║  8. Delete Account                     ║\n";
    cout << "║  9. Exit                               ║\n";
    cout << "╚════════════════════════════════════════╝\n";
    cout << "\nEnter your choice (1-9): ";
}

// Main function
int main() {
    int choice;
    
    cout << "\n╔════════════════════════════════════════╗\n";
    cout << "║   Welcome to Bank Management System    ║\n";
    cout << "╚════════════════════════════════════════╝\n";
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAccountDetails();
                break;
            case 6:
                transferMoney();
                break;
            case 7:
                listAllAccounts();
                break;
            case 8:
                deleteAccount();
                break;
            case 9:
                cout << "\n👋 Thank you for using Bank Management System!\n";
                return 0;
            default:
                cout << "\n❌ Invalid choice! Please enter a number between 1 and 9.\n";
        }
    }
    
    return 0;
}

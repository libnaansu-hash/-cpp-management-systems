#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Global game board
char board[3][3];
char player1 = 'X';
char player2 = 'O';
char currentPlayer = 'X';

// Function prototypes
void initializeBoard();
void displayBoard();
bool isValidMove(int row, int col);
bool makeMove(int row, int col);
bool checkWin(char player);
bool isBoardFull();
void switchPlayer();
bool playGame();
void displayInstructions();
void displayMenu();

// Initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = player1;
}

// Display the current game board
void displayBoard() {
    cout << "\n\n";
    cout << "     0   1   2\n";
    cout << "   +---+---+---+\n";
    
    for (int i = 0; i < 3; i++) {
        cout << " " << i << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |\n";
        cout << "   +---+---+---+\n";
    }
    cout << "\n";
}

// Check if a move is valid
bool isValidMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

// Make a move on the board
bool makeMove(int row, int col) {
    if (!isValidMove(row, col)) {
        cout << "\n❌ Invalid move! Position already occupied or out of bounds.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

// Check if a player has won
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

// Check if board is full
bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Switch current player
void switchPlayer() {
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

// Display game instructions
void displayInstructions() {
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║              How to Play Tic Tac Toe                 ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ - The board has rows (0-2) and columns (0-2)      ║\n";
    cout << "║ - Player 1 (X) and Player 2 (O) take turns       ║\n";
    cout << "║ - Enter row and column to place your mark        ║\n";
    cout << "║ - First to get 3 in a row wins!                  ║\n";
    cout << "║ - The game ends in a draw if board is full       ║\n";
    cout << "║ - Example: Row 0, Column 0 = Top-Left cell      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}

// Main game loop
bool playGame() {
    initializeBoard();
    
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║          Tic Tac Toe Game Started!                ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    displayBoard();
    
    int moveCount = 0;
    
    while (true) {
        cout << "Player " << currentPlayer << "'s Turn\n";
        cout << "Enter Row (0-2): ";
        int row;
        cin >> row;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n❌ Invalid input! Please enter a number.\n\n";
            continue;
        }
        
        cout << "Enter Column (0-2): ";
        int col;
        cin >> col;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n❌ Invalid input! Please enter a number.\n\n";
            continue;
        }
        
        if (!makeMove(row, col)) {
            cout << "\n";
            continue;
        }
        
        displayBoard();
        moveCount++;
        
        // Check if current player won
        if (checkWin(currentPlayer)) {
            cout << "\n╔═════════════════════════════════════╘\n";
            cout << "║  🎆 Player " << currentPlayer << " Wins! 🎉      ║\n";
            cout << "╚═════════════════════════════════════╙\n";
            return true;
        }
        
        // Check if board is full (draw)
        if (isBoardFull()) {
            cout << "\n╔═════════════════════════════════════╘\n";
            cout << "║     It's a Draw! No winner this time.     ║\n";
            cout << "╚═════════════════════════════════════╙\n";
            return false;
        }
        
        // Switch to next player
        switchPlayer();
    }
}

// Display main menu
void displayMenu() {
    int choice;
    bool playAgain = true;
    
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║    Welcome to Tic Tac Toe Game                 ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    while (playAgain) {
        cout << "\n╔═════════════════════════════════════╘\n";
        cout << "║           Main Menu                      ║\n";
        cout << "╠═════════════════════════════════════╣\n";
        cout << "║  1. Play Game                              ║\n";
        cout << "║  2. View Instructions                      ║\n";
        cout << "║  3. Exit                                   ║\n";
        cout << "╚═════════════════════════════════════╙\n";
        cout << "\nEnter your choice (1-3): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                playGame();
                
                cout << "\nDo you want to play again? (y/n): ";
                char response;
                cin >> response;
                
                if (tolower(response) != 'y') {
                    playAgain = false;
                }
                break;
            }
            case 2:
                displayInstructions();
                break;
            case 3:
                cout << "\n👋 Thank you for playing Tic Tac Toe!\n\n";
                playAgain = false;
                break;
            default:
                cout << "\n❌ Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generator
    
    displayMenu();
    
    return 0;
}

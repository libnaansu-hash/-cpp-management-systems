# Tic Tac Toe Game

## Overview
An interactive console-based Tic Tac Toe game for two players. This project demonstrates core C++ programming concepts including arrays, loops, conditionals, and game logic implementation.

## Features
- ✅ Two-player gameplay (Player X vs Player O)
- ✅ Dynamic 3x3 game board display
- ✅ Input validation for moves
- ✅ Win detection (rows, columns, diagonals)
- ✅ Draw detection
- ✅ Replay functionality
- ✅ User-friendly menu system
- ✅ Game instructions
- ✅ Beautiful formatted output

## Game Board Coordinates

The board is indexed from 0-2 for both rows and columns:

```
     0   1   2
   +---+---+---+
 0 |   |   |   |
   +---+---+---+
 1 |   |   |   |
   +---+---+---+
 2 |   |   |   |
   +---+---+---+
```

**Example Moves:**
- Top-Left: Row 0, Column 0
- Center: Row 1, Column 1
- Bottom-Right: Row 2, Column 2

## Game Rules

1. The game is played on a 3x3 grid
2. Players alternate turns (X goes first)
3. Each player marks a cell with their symbol
4. A player wins by getting three of their symbols in a row:
   - Horizontally (three in a row)
   - Vertically (three in a column)
   - Diagonally (three on a diagonal)
5. If the board is filled and no player has won, it's a draw
6. The game ends immediately when a player wins or board is full

## Compilation & Execution

### Linux/Mac:
```bash
cd 4_mini_game_tictactoe
g++ -std=c++11 -o tictactoe tictactoe.cpp
./tictactoe
```

### Windows (MinGW):
```bash
g++ -std=c++11 -o tictactoe.exe tictactoe.cpp
tictactoe.exe
```

## How to Play

### Starting the Game:
1. Run the program
2. Select "1. Play Game" from main menu
3. Game starts with an empty board

### Making a Move:
1. Current player is announced (Player X or Player O)
2. Enter the row number (0-2)
3. Enter the column number (0-2)
4. The board updates immediately
5. Next player's turn begins

### Game Outcomes:
- **Win**: When a player gets 3 marks in a row
- **Draw**: When board is full and no winner
- **Continue**: If neither condition is met, game continues

### After Game:
- Choose to play again or return to menu
- Option to view instructions
- Exit program

## Sample Game Session

```
╔═════════════════════════════════════╘
║          Tic Tac Toe Game Started!                ║
╚═════════════════════════════════════╙

     0   1   2
   +---+---+---+
 0 |   |   |   |
   +---+---+---+
 1 |   |   |   |
   +---+---+---+
 2 |   |   |   |
   +---+---+---+

Player X's Turn
Enter Row (0-2): 1
Enter Column (0-2): 1

     0   1   2
   +---+---+---+
 0 |   |   |   |
   +---+---+---+
 1 |   | X |   |
   +---+---+---+
 2 |   |   |   |
   +---+---+---+

Player O's Turn
Enter Row (0-2): 0
Enter Column (0-2): 0

     0   1   2
   +---+---+---+
 0 | O |   |   |
   +---+---+---+
 1 |   | X |   |
   +---+---+---+
 2 |   |   |   |
   +---+---+---+

[Game continues...]

╔═════════════════════════════════════╘
║  🎆 Player X Wins! 🎉      ║
╚═════════════════════════════════════╙

Do you want to play again? (y/n): n
```

## Code Structure

### Global Variables
- `board[3][3]` - The game board
- `currentPlayer` - Tracks whose turn it is
- `player1` - 'X' symbol
- `player2` - 'O' symbol

### Key Functions

**initializeBoard()**
- Clears the board
- Sets all cells to empty space
- Resets current player to X

**displayBoard()**
- Prints the current game state
- Shows row and column numbers
- Uses ASCII art for formatting

**isValidMove(row, col)**
- Checks if move is within bounds (0-2)
- Verifies cell is empty
- Returns true if valid, false otherwise

**makeMove(row, col)**
- Places player's symbol on board
- Calls isValidMove() for validation
- Returns true if successful

**checkWin(player)**
- Checks all three rows for match
- Checks all three columns for match
- Checks both diagonals for match
- Returns true if player won

**isBoardFull()**
- Iterates through all cells
- Returns false if any empty cell found
- Returns true if all cells filled

**switchPlayer()**
- Toggles currentPlayer between X and O
- Uses ternary operator for efficiency

**playGame()**
- Main game loop
- Handles user input
- Checks win/draw conditions
- Controls game flow

## Learning Concepts

### Arrays
- 2D array for game board
- Index-based access
- Iterating through arrays

### Loops
- While loops for game loop
- For loops for board initialization and win checking
- Nested loops for 2D array traversal

### Conditionals
- If/else statements for input validation
- Switch statements for menu
- Ternary operators for player switching

### Game Logic
- Win condition detection
- Draw detection
- Input validation
- Game state management

### String/Character Operations
- Character comparison
- Array element manipulation
- Input/output handling

## Error Handling
- Invalid row/column input
- Out of bounds checking
- Occupied cell detection
- Non-numeric input handling

## Possible Enhancements
- Computer AI opponent (minimax algorithm)
- Difficulty levels
- Score tracking across games
- Game statistics
- Timer for moves
- Network multiplayer
- GUI implementation
- Sound effects
- Animated board display
- Larger board variants (4x4, 5x5)

## Performance
- **Time Complexity**: 
  - Move validation: O(1)
  - Win check: O(1) - fixed board size
  - Game loop: O(9) maximum moves
- **Space Complexity**: O(1) - fixed size board

## Author
libnaansu-hash

## License
Open source - Educational purposes

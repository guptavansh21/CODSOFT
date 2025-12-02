#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits> // For numeric_limits

// Function to display the Tic-Tac-Toe board
void display_board(const std::vector<char>& board) {
    std::cout << "\n--- TIC-TAC-TOE (CODSOFT C++) ---\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    std::cout << "     |     |     \n\n";
}

// Function to check if a player has won
// Returns: 'X', 'O', or ' ' (for no winner)
char check_win(const std::vector<char>& board) {
    // Checking 8 winning possibilities (3 rows, 3 columns, 2 diagonals)
    
    // Rows
    if (board[0] == board[1] && board[1] == board[2]) return board[0];
    if (board[3] == board[4] && board[4] == board[5]) return board[3];
    if (board[6] == board[7] && board[7] == board[8]) return board[6];
    
    // Columns
    if (board[0] == board[3] && board[3] == board[6]) return board[0];
    if (board[1] == board[4] && board[4] == board[7]) return board[1];
    if (board[2] == board[5] && board[5] == board[8]) return board[2];

    // Diagonals
    if (board[0] == board[4] && board[4] == board[8]) return board[0];
    if (board[2] == board[4] && board[4] == board[6]) return board[2];

    return ' '; // No winner yet
}

void play_tic_tac_toe() {
    // Board initialization: Using numbers 1-9 for player input reference
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char current_player = 'X';
    int moves = 0;
    char winner = ' ';

    std::cout << "\nWelcome to Tic-Tac-Toe! Player X starts.\n";

    do {
        // 1. Board Display
        display_board(board);

        int move_choice;
        bool valid_move = false;

        while (!valid_move) {
            std::cout << "Player " << current_player << ", enter a number (1-9) for your move: ";
            
            // Input validation check
            if (!(std::cin >> move_choice)) {
                std::cout << "❌ Invalid input! Please enter a number.\n";
                // Clear error flags and ignore the rest of the line
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            // 2. Move Validation and Update
            int index = move_choice - 1; // Convert 1-9 to 0-8 index

            if (index >= 0 && index < 9) {
                if (board[index] != 'X' && board[index] != 'O') {
                    board[index] = current_player;
                    valid_move = true;
                    moves++;
                } else {
                    std::cout << "❌ Slot already taken. Try again.\n";
                }
            } else {
                std::cout << "❌ Invalid number. Must be between 1 and 9.\n";
            }
        }
        
        // 3. Check for Win or Draw
        winner = check_win(board);
        if (winner == ' ' && moves < 9) {
            // 4. Switch Player
            current_player = (current_player == 'X') ? 'O' : 'X';
        }

    } while (winner == ' ' && moves < 9); // Loop until win or draw

    // Final Result Display
    display_board(board);
    if (winner != ' ') {
        std::cout << "🥳 CONGRATULATIONS! Player " << winner << " wins the game!\n";
    } else {
        std::cout << "🤝 It's a DRAW! Game Over.\n";
    }
}

int main() {
    char play_again_choice;

    do {
        play_tic_tac_toe();
        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> play_again_choice;
        // Clear input buffer for the next round
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (play_again_choice == 'y' || play_again_choice == 'Y');

    std::cout << "Thanks for playing! 👋\n";
    return 0;
}
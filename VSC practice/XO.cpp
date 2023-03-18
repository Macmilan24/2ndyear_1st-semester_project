#include <iostream>
#include <string>

using namespace std;

// Define constants for the game board size and player symbols
const int BOARD_SIZE = 3;
const char PLAYER_1_SYMBOL = 'X';
const char PLAYER_2_SYMBOL = 'O';

// Define a function to draw the game board
void draw_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << " " << board[i][j] << " ";
            if (j != BOARD_SIZE - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i != BOARD_SIZE - 1) {
            cout << "---+---+---" << endl;
        }
    }
}

// Define a function to check if there is a winner
char check_winner(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // If there is no winner, return a space character
    return ' ';
}

// Define a function to check if the game is tied
bool check_tie(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Define the main game loop
void play_game() {
    // Set up the game board
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Set up the game variables
    char current_player = PLAYER_1_SYMBOL;
    bool game_over = false;

    // Loop until the game is over
    while (!game_over) {
        // Draw the game board
        draw_board(board);

        // Get the current player's move
        int row, col;
        cout << "Player " << current_player << ", enter your move (row column): ";
        cin >> row >> col;

        // Check if the move is valid and make it
        // Check if the move is valid and make it
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Invalid move, please try again." << endl;
        } else if (board[row][col] != ' ') {
            cout << "That space is already occupied, please try again." << endl;
        } else {
            board[row][col] = current_player;
            // Check if the game is over
            char winner = check_winner(board);
            if (winner != ' ') {
                draw_board(board);
                cout << "Player " << winner << " wins!" << endl;
                game_over = true;
            } else if (check_tie(board)) {
                draw_board(board);
                cout << "The game is tied." << endl;
                game_over = true;
            } else {
                // Switch to the other player
                current_player = (current_player == PLAYER_1_SYMBOL) ? PLAYER_2_SYMBOL : PLAYER_1_SYMBOL;
            }
        }
    }
}

// Define the main function to start the game
int main() {
    cout << "Welcome to the XO game!" << endl;
    play_game();
    return 0;
}

#include <array>
#include <iostream>
#include <string>

#include "tictactoe.h"

using std::cout, std::string, std::array;

int main() {
    string currentPlayer = "X";
    string winner = "none";
    array<string, 9> game = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    cout << "Welcome to Tic Tac Toe!\n";
    while (winner == "none") {
        draw_board(game);
        game = ask_player(game, currentPlayer);
        winner = check_win(game);
        currentPlayer = currentPlayer == "O" ? "X" : "O";
    }
    if (winner == "tie") {
        cout << "It's a tie!\n";
        draw_board(game);
        return 0;
    }
    cout << "Player " << winner << " wins!\n";
    draw_board(game);
    return 0;
}

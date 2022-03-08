#include <array>
#include <iostream>
#include <string>

void draw_board(std::array<std::string, 9> game_board) {
    int line = 0;
    std::cout << "┼───┼───┼───┼\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "│";
        for (int j = 0; j < 3; j++) {
            std::cout << " " << game_board[j + line] << " │";
        }
        std::cout << "\n┼───┼───┼───┼\n";
        line += 3;
    }
}

std::array<std::string, 9> ask_player(std::array<std::string, 9> game_board,
                                      std::string player) {
    std::string posString;
    while (1) {
        std::cout << "Player " << player
                  << "'s turn (e.g., 1 for top-left and 5 for middle): ";
        std::getline(std::cin, posString);
        if (posString.length() == 0) {
            continue;
        }
        int pos = std::stoi(posString);
        if (game_board[pos - 1] != " ") {
            std::cout << "Either this position is already taken or is an invalid "
                         "position. Try again.\n";
            continue;
        } else {
            game_board[pos - 1] = player;
            return game_board;
        }
    }
}

std::string check_win(std::array<std::string, 9> game_board) {
    int line = 0;
    long unsigned int taken = 0;
    for (int i = 0; i < 3; i++) {
        if (game_board[i + line] == game_board[i + 1 + line] &&
            game_board[i + 1 + line] == game_board[i + 2 + line] &&
            game_board[i + line] != " ") {
            return game_board[i + line];
        }
        line += 3;
    }
    line = 0;
    for (int j = 0; j < 3; j++) {
        if (game_board[j + line] == game_board[j + 3 + line] &&
            game_board[j + 3 + line] == game_board[j + 6 + line] &&
            game_board[j + line] != " ") {
            return game_board[j + line];
        }
        line += 1;
    }
    if (game_board[0] == game_board[4] && game_board[4] == game_board[8] &&
            game_board[0] != " " ||
        game_board[2] == game_board[4] && game_board[4] == game_board[6] &&
            game_board[2] != " ") {
        return game_board[4];
    }
    for (long unsigned int k = 0; k < game_board.size(); k++) {
        if (game_board[k] != " ") {
            taken += 1;
        }
    }
    if (taken == game_board.size()) {
        return "tie";
    }
    return "none";
}

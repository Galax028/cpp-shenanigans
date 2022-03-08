#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <array>
#include <string>

void draw_board(std::array<std::string, 9> game_board);
std::array<std::string, 9> ask_player(std::array<std::string, 9> game_board,
                                      std::string player);
std::string check_win(std::array<std::string, 9> game_board);

#endif  // TICTACTOE_H

#pragma once

#include <vector>
#include <iostream>
#include <sstream>

const int BOARD_SIZE = 3;

class Board {
public:
    /**
     * @brief Constructor to initialize the board.
     *
     * Creates a 3x3 grid and fills it with empty spaces.
     */
    Board();

    /**
     * @brief Displays the current state of the board to the console.
     *
     * Prints the grid with rows and columns for easy viewing.
     */
    void display() const;

    /**
     * @brief Places a player's symbol on the board at a specific location.
     *
     * @param row The row to place the move (0-2).
     * @param col The column to place the move (0-2).
     * @param playerSymbol The character symbol of the player ('X' or 'O').
     */
    void place_move(const int &row, const int &col, const char &playerSymbol);

    /**
     * @brief Checks if a specific move is valid.
     *
     * A move is valid if the cell is within the board's bounds (0-2)
     * and is currently empty.
     *
     * @param row The row to check.
     * @param col The column to check.
     * @return true if the move is valid, false otherwise.
     */
    bool is_valid_move(const int &row, const int &col) const;

    /**
     * @brief Checks if the specified player has won the game.
     *
     * Checks all rows, columns, and both diagonals for a winning line.
     *
     * @param playerSymbol The symbol of the player to check for a win.
     * @return true if the player has won, false otherwise.
     */
    bool check_win(const char &playerSymbol) const;

    /**
     * @brief Checks if the board is completely full.
     *
     * Used to determine if the game is a draw.
     *
     * @return true if no empty spaces are left, false otherwise.
     */
    bool is_full() const;

    /**
     * @brief Converts the board to a string representation.
     *
     * @return A string representation of the board.
     */
    std::string get_board_as_string() const;

private:
    // The 2D grid representing the Tic-Tac-Toe board.
    std::vector<std::vector<char>> grid;
};
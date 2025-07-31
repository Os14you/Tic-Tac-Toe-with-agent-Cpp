#pragma once

#include "Board.hpp"

/**
 * @class Player
 * @brief An abstract base class representing a player in the game.
 *
 * This class provides a common interface for any type of player.
 * Specific player logic (e.g., for a human or an AI) should be
 * implemented in a derived class.
 */
class Player {
public:
    /**
     * @brief Constructor to create a player with a given symbol.
     * @param playerSymbol The character symbol for the player (e.g., 'X' or 'O').
     */
    Player(char playerSymbol);

    /**
     * @brief Virtual destructor.
     * This is essential for a base class to ensure proper cleanup of derived classes.
     */
    virtual ~Player() = default;

    /**
     * @brief Gets the player's symbol.
     * @return The character symbol ('X' or 'O') of the player.
     */
    char get_symbol() const;

    /**
     * @brief Pure virtual function to get the player's next move.
     *
     * This function is implemented by concrete derived classes (e.g., HumanPlayer and AIPlayer).
     * It's responsible for deciding on a move and providing the row and column.
     *
     * @param board A read-only reference to the current board to help decide the move.
     * @param row A reference to an integer where the chosen row (0-2) will be stored.
     * @param col A reference to an integer where the chosen column (0-2) will be stored.
     */
    virtual void make_move(const Board& board, int& row, int& col) = 0;

protected:
    // The player's symbol, accessible to derived classes.
    char symbol;
};
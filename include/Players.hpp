#pragma once

#include "Player.hpp" // Include the abstract base class
#include <vector>

/**
 * @class HumanPlayer
 * @brief Represents a human player who enters moves via the console.
 *
 * This class implements the make_move method by prompting the user
 * for their desired row and column.
 */
class HumanPlayer : public Player {
public:
    /**
     * @brief Constructor for a human player.
     * @param playerSymbol The symbol for the player ('X' or 'O').
     */
    HumanPlayer(char playerSymbol);

    /**
     * @brief Gets the human player's move from console input.
     *
     * Prompts the user to enter a row and column (1-3), validates the input,
     * and converts it to 0-indexed values for the game logic.
     *
     * @param board A read-only reference to the current board (used for validation).
     * @param row A reference to store the chosen row.
     * @param col A reference to store the chosen column.
     */
    void make_move(const Board& board, int& row, int& col) override;
};


/**
 * @class AIPlayer
 * @brief Represents an AI player that uses the Minimax algorithm to choose moves.
 *
 * This class implements the get_move method by analyzing the board state
 * and selecting the optimal move.
 */
class AIPlayer : public Player {
public:
    /**
     * @brief Constructor for an AI player.
     * @param playerSymbol The symbol for the player ('X' or 'O').
     */
    AIPlayer(char playerSymbol);

    /**
     * @brief Determines and executes the AI's best move using Minimax.
     *
     * @param board A read-only reference to the current board.
     * @param row A reference to store the chosen row.
     * @param col A reference to store the chosen column.
     */
    void make_move(const Board& board, int& row, int& col) override;

private:
    char opponentSymbol; // To keep track of the opponent's symbol

    /**
     * @brief The core Minimax algorithm to find the best possible score.
     *
     * @param board The current state of the board.
     * @param isMaximizing A boolean indicating if it's the AI's (maximizing) turn or opponent's (minimizing) turn.
     * @return The best score achievable from the current board state (+10 for win, -10 for loss, 0 for draw).
     */
    int minimax(Board board, bool isMaximizing);

    /**
     * @brief Evaluates the board to check for a terminal state (win, loss, or draw).
     *
     * @param board The board to evaluate.
     * @return +10 if the AI has won, -10 if the opponent has won, 0 otherwise.
     */
    int evaluate_board(const Board& board);
};

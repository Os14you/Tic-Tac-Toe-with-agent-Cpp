#pragma once

#include "Board.hpp"
#include "Players.hpp"
#include <iostream>
#include <memory> // for std::unique_ptr (smart pointers)

/**
 * @class Game
 * @brief Manages the overall Tic-Tac-Toe game flow.
 *
 * This class initializes the players and the board, runs the main game loop,
 * and determines when the game is over.
 */
class Game {
public:
    /**
     * @brief Constructs a new game session.
     *
     * This constructor initializes the two players based on the types specified ('h' for human, 'a' for AI).
     * It uses std::make_unique for modern, safe memory management. Player 1 ('X') always starts.
     *
     * @param player1_type The type of player 1.
     * @param player2_type The type of player 2.
     */
    Game(char player1_type, char player2_type);

    /**
     * @brief Starts and runs the main game loop.
     *
     * This function will continue to run until a player wins or the game is a draw.
     */
    void run();

private:
    /**
     * @brief Switches the current player.
     *
     * If the current player is player 1, it switches to player 2, and vice-versa.
     */
    void switch_player();

    /**
     * @brief Checks if the game has reached a terminal state.
     * @return true if a player has won or the board is full, false otherwise.
     */
    bool is_game_over();

    // --- Member Variables ---
    Board board; // The game board object.

    // Smart pointers to manage the player objects. This is modern C++ practice.
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

    // A raw pointer to keep track of whose turn it is.
    Player* currentPlayer;
};
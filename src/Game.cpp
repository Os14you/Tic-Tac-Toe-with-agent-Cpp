#include <Game.hpp>

Game::Game(char player1_type, char player2_type) {
    // Create Player 1 ('X') based on the specified type
    if (player1_type == 'h')
        player1 = std::make_unique<HumanPlayer>('X');
    else
        player1 = std::make_unique<AIPlayer>('X');

    // Create Player 2 ('O') based on the specified type
    if (player2_type == 'h')
        player2 = std::make_unique<HumanPlayer>('O');
    else
        player2 = std::make_unique<AIPlayer>('O');

    // Set the starting player
    currentPlayer = player1.get();
}

void Game::run() {
    // The game loop continues as long as the game is not over
    while (!is_game_over()) {
        board.display();

        int row, col;
        currentPlayer->make_move(board, row, col); // Ask the current player for their move

        board.place_move(row, col, currentPlayer->get_symbol()); 
        switch_player();
    }

    // Display the final board state once the game has ended
    board.display();
}

void Game::switch_player() {
    currentPlayer = (currentPlayer == player1.get()) ? player2.get() : player1.get();
}

bool Game::is_game_over() {
    // Check if player 1 has won
    if (board.check_win(player1->get_symbol())) {
        std::cout << ">>> Player " << player1->get_symbol() << " wins!\n";
        return true;
    }

    // Check if player 2 has won
    if (board.check_win(player2->get_symbol())) {
        std::cout << ">>> Player " << player2->get_symbol() << " wins!\n";
        return true;
    }

    // Check if the game is a draw
    if (board.is_full()) {
        std::cout << ">>> The game is a draw!\n";
        return true;
    }

    // If none of the above, the game is not over
    return false;
}
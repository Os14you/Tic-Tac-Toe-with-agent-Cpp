#include <Game.hpp>

// This function creates a timestamp string for the filename.
std::string get_formatted_time() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%H-%M-%S");
    return ss.str();
}

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

    std::string subdir;
    if (player1_type == 'h' && player2_type == 'h') subdir = "Human vs Human";
    else if (player1_type == 'h' && player2_type == 'a') subdir = "Human vs AI";
    else subdir = "AI vs AI";

    std::string log_dir_path = "log/" + subdir;
    std::filesystem::create_directories(log_dir_path); // Create directory if it doesn't exist

    std::string file_path = log_dir_path + "/" + get_formatted_time() + ".log";
    log_file.open(file_path);

    log_file << "Game Started: " << subdir << "\n";
    log_file << "Player 1: " << player1->get_symbol() << " | Player 2: " << player2->get_symbol() << "\n\n";
}

void Game::run() {
    // The game loop continues as long as the game is not over
    while (!is_game_over()) {
        board.display();
        log_board_state(); // Log the board before the move

        int row, col;
        currentPlayer->make_move(board, row, col); // Ask the current player for their move

        log_file << "Player " << currentPlayer->get_symbol() << " places move at (" << row + 1 << ", " << col + 1 << ")\n";

        board.place_move(row, col, currentPlayer->get_symbol()); 
        switch_player();
    }

    // Display the final board state once the game has ended
    board.display();
    log_board_state(); // Log the final board state
    log_file.close();  // Close the file when the game is done
}

void Game::switch_player() {
    currentPlayer = (currentPlayer == player1.get()) ? player2.get() : player1.get();
}

bool Game::is_game_over() {
    // Check if player 1 has won
    if (board.check_win(player1->get_symbol())) {
        std::cout << ">>> Player " << player1->get_symbol() << " wins!\n";
        log_file << "\n--- Player " << player1->get_symbol() << " wins! ---\n"; // Log winner
        return true;
    }

    // Check if player 2 has won
    if (board.check_win(player2->get_symbol())) {
        std::cout << ">>> Player " << player2->get_symbol() << " wins!\n";
        log_file << "\n--- Player " << player2->get_symbol() << " wins! ---\n"; // Log winner
        return true;
    }

    // Check if the game is a draw
    if (board.is_full()) {
        std::cout << ">>> The game is a draw!\n";
        log_file << "\n--- The game is a draw! ---\n"; // Log draw
        return true;
    }

    // If none of the above, the game is not over
    return false;
}

void Game::log_board_state() {
    log_file << "--- Board State ---";
    log_file << board.get_board_as_string(); // Get the formatted string from the board
    log_file << "\n";
}
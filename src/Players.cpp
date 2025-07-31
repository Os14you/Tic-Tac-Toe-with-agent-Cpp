#include <Players.hpp>

// --- HumanPlayer Implementation ---

HumanPlayer::HumanPlayer(char playerSymbol) : Player(playerSymbol) {}

void HumanPlayer::make_move(const Board& board, int& row, int& col) {
    while (true) {
        std::cout << "Player " << this->symbol << ", enter your move (row and column, e.g., 1 3): ";
        
        int inputRow, inputCol;
        std::cin >> inputRow >> inputCol;

        // Check if the input was valid (i.e., numbers were entered)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter numbers only.\n";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the line
            continue; // Ask for input again
        }

        // Convert 1-based input (1-3) to 0-based index (0-2)
        row = inputRow - 1;
        col = inputCol - 1;

        // Check if the move is valid according to the board state
        if (board.is_valid_move(row, col)) break;
        else std::cout << "Invalid move. The cell is either taken or out of bounds. Please try again.\n";
    }
}

// --- AIPlayer Implementation ---

AIPlayer::AIPlayer(char playerSymbol) : Player(playerSymbol) {
    // Determine the opponent's symbol
    opponentSymbol = (symbol == 'X') ? 'O' : 'X';
}

void AIPlayer::make_move(const Board& board, int& row, int& col) {
    int bestScore = INT_MIN;
    int bestRow = -1;
    int bestCol = -1;

    // Iterate through every cell on the board
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            // Check if the cell is empty
            if (board.is_valid_move(i, j)) {
                Board tempBoard = board;
                tempBoard.place_move(i, j, symbol);

                // Get the score for this move using the minimax algorithm
                int moveScore = minimax(tempBoard, false); // It's now the opponent's (minimizing) turn

                // If this move has a better score than the current best, update it
                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    row = bestRow;
    col = bestCol;
}

int AIPlayer::evaluate_board(const Board& board) {
    // Check if the AI (maximizing player) has won
    if (board.check_win(symbol))
        return +10;
    // Check if the opponent (minimizing player) has won
    else if (board.check_win(opponentSymbol))
        return -10;
    // If no one has won, it's a neutral state (or a draw)
    else
        return 0;
}

int AIPlayer::minimax(Board board, bool isMaximizing) {
    int score = evaluate_board(board);

    // If the board is in a terminal state (win/loss), return its score
    if (score == 10 || score == -10 || board.is_full()) {
        return score;
    }

    // If it's the maximizing player's (AI's) turn
    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board.is_valid_move(i, j)) {
                    Board tempBoard = board;
                    tempBoard.place_move(i, j, symbol);
                    bestScore = std::max(bestScore, minimax(tempBoard, !isMaximizing));
                }
            }
        }
        return bestScore;
    }
    // If it's the minimizing player's (opponent's) turn
    else {
        int bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board.is_valid_move(i, j)) {
                    Board tempBoard = board;
                    tempBoard.place_move(i, j, opponentSymbol);
                    bestScore = std::min(bestScore, minimax(tempBoard, !isMaximizing));
                }
            }
        }
        return bestScore;
    }
}

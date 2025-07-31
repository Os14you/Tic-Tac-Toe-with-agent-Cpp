#include <Board.hpp>

Board::Board() {
    grid.resize(BOARD_SIZE, std::vector<char>(BOARD_SIZE, '-'));
}

void Board::display() const {
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << " " << grid[i][j] << " ";
            if (j < BOARD_SIZE - 1)
                std::cout << "|";
        }
        std::cout << "\n";
        if (i < BOARD_SIZE - 1)
            std::cout << "---|---|---\n";
    }
    std::cout << "\n";
}

void Board::place_move(const int &row, const int &col, const char &playerSymbol) {
    if(is_valid_move(row, col))
        grid[row][col] = playerSymbol;
}

bool Board::is_valid_move(const int &row, const int &col) const {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && grid[row][col] == 0);
}

bool Board::check_win(const char &playerSymbol) const {
    // 1. Check for a win in all rows
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (grid[i][0] == playerSymbol && grid[i][1] == playerSymbol && grid[i][2] == playerSymbol)
            return true;
    }

    // 2. Check for a win in all columns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (grid[0][j] == playerSymbol && grid[1][j] == playerSymbol && grid[2][j] == playerSymbol)
            return true;
    }

    // 3. Check for a win on the main diagonal (top-left to bottom-right)
    if (grid[0][0] == playerSymbol && grid[1][1] == playerSymbol && grid[2][2] == playerSymbol) 
        return true;

    // 4. Check for a win on the anti-diagonal (top-right to bottom-left)
    if (grid[0][2] == playerSymbol && grid[1][1] == playerSymbol && grid[2][0] == playerSymbol)
        return true;

    // If no winning condition was met after all checks, return false.
    return false;
}

bool Board::is_full() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (grid[i][j] == '-')
                return false; // Found an empty cell
        }
    }
    return true; // No empty cells were found
}
#include "Player.hpp"

Player::Player(char playerSymbol) : symbol(playerSymbol) {
    // The member variable 'symbol' is initialized using the member initializer list.
}

char Player::get_symbol() const {
    return symbol;
}

// Note: The pure virtual function 'get_move' does not have an implementation
// in the base class. It is implemented by derived classes 
// e.g. HumanPlayer or AIPlayer.
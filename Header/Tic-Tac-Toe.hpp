#ifndef TIC_TAC_TOE__
#define TIC_TAC_TOE__
#include "agent.hpp"
class Game {
    private:
        int board[3][3],turns;  // 0 = - , 2 = O, 1 = X
        int rowNum[8] {0,1,2,0,0,0,0,0};
        int colNum[8] {0,0,0,0,1,2,0,2};
        int increaseRow[8] {0,0,0,1,1,1,1,1};
        int increaseCol[8] {1,1,1,0,0,0,1,-1};
        char turn;
        void winner(char player);
        void printBoard();
        int playTurn(int x,int y);
        bool checkBoard();
        Agent agent;
    public:
        Game();
        Game(char turn);
        void multiPlayer();
        void singlePlayer();
};
#endif  /* TIC_TAC_TOE__ */
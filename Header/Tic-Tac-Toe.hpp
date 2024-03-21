#ifndef TIC_TAC_TOE__
#define TIC_TAC_TOE__

class Game_TTT {
    private:
        int board[3][3] {0},turns;
        int rowNum[8] {0,1,2,0,0,0,0,0};
        int colNum[8] {0,0,0,1,2,3,0,2};
        int increaseRow[8] {0,0,0,1,1,1,1,1};
        int increaseCol[8] {1,1,1,0,0,0,1,-1};
        char turn;
    public:
        Game_TTT();
        Game_TTT(char turn);
        void winner(char player);
        void printBoard();
        int playTurn(int x,int y);
        bool checkBoard();
        // char singlePlayer();
        void multiPlayer();
};

/*
class agent(){
    private:
    public:
        agent();
};
*/
#endif  /* TIC_TAC_TOE__ */
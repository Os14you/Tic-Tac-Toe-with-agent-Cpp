#ifndef Agent_TTT__
#define Agent_TTT__
class Agent{
    private:
        char symbol;
        int agentSymbol,opponentSymbol;
        int checkBoard(const int board[3][3]);
        int MinMax(int board[3][3], bool isMaximizing, int depth = 20,bool firstTurn = true);
    public:
        Agent();
        Agent(char symbol);
        void getMove(int board[3][3],bool isEmpty = false);
};


#endif  /* Agent_TTT__ */
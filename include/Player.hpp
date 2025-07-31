#ifndef Agent_TTT__
#define Agent_TTT__

#include <fstream>
#include <iostream>

class Agent{
private:
    char symbol;
    int agentSymbol,opponentSymbol;
    std::fstream dataFile;
    void writeBoard(const int board[3][3]);
    int checkBoard(const int board[3][3]);
    int MinMax(int board[3][3], bool isMaximizing, int depth = 20, bool firstTurn = true);
public:
    Agent();
    Agent(char symbol);
    ~Agent(){dataFile <<"Game Ends .. \n\n"; dataFile.close();};
    void getMove(int board[3][3],bool isEmpty = false);
};

#endif  /* Agent_TTT__ */
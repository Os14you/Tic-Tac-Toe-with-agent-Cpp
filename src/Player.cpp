#include <Player.hpp>

Agent::Agent() : Agent('O') { }

Agent::Agent(char symbol) : symbol(symbol){ 
    this->agentSymbol = (symbol == 'X' ? 1 : 2);
    this->opponentSymbol = (symbol == 'X' ? 2 : 1);
    dataFile.open("Data/agentData.txt", std::ios::in | std::ios::out | std::ios::app);
    dataFile << "Start A New Game ...\n";
}

void Agent::writeBoard(const int board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!board[i][j]) dataFile << " - ";
            else if(board[i][j]==1) dataFile << " X ";
            else dataFile <<" O ";
        }
        dataFile << "\n";
    }
}

int Agent::checkBoard(const int board[3][3]){
    //  2: X winner
    // -2: O winner
    //  0: Tie
    //  1: No winner
    
    // For rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=0) {
            return board[i][0] == opponentSymbol ? 2 : -2;
        }
    }

    // For cols
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!=0) {
            return board[0][i] == opponentSymbol ? 2 : -2;
        }
    }
    
    // Diameter 1
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!=0) {
        return board[0][0] == opponentSymbol ? 2 : -2;
    }

    // Diameter 2
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!=0) {
        return board[2][0] == opponentSymbol ? 2 : -2;
    }

    // For Tie Case
    bool tie = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 0) {
                tie = false;
            }
        }   
    }
    if(tie) return 0;

    // Else
    return 1;
}

int Agent::MinMax(int board[3][3],bool isMaximizing, int depth,bool firstTurn){
    if(firstTurn) writeBoard(board);
    int result = checkBoard(board);
    if(depth == 0 || result != 1) {
        return result;
    }

    if(isMaximizing) {
        int finalScore = -10;
        int finalI, finalJ;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = opponentSymbol;
                    int score = MinMax(board,false,depth-1,false);
                    board[i][j] = 0;
                    if(score > finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                    if(firstTurn) dataFile << "score of (" << i << "," << j << ") is " << score << "\n";
                }
            }   
        }
        if(firstTurn) {
            board[finalI][finalJ] = agentSymbol;
        }
        return finalScore;
    } else {
        int finalScore = 10;
        int finalI, finalJ;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = agentSymbol;
                    int score = MinMax(board,true,depth-1,false);
                    board[i][j] = 0;
                    if(score < finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                    if(firstTurn) dataFile << "score of (" << i << "," << j << ") is " << score << "\n";
                }
            }   
        }
        if(firstTurn) {
            board[finalI][finalJ] = agentSymbol;
        }
        return finalScore;
    }
}

void Agent::getMove(int board[3][3],bool isEmpty){
    if(isEmpty) {
        board[1][1] = agentSymbol;
        return;
    }
    bool isMax = (agentSymbol  == 1 ? true : false);
    std::cout << "Agent plays ... \n";
    if(MinMax(board,isMax)) return;
}
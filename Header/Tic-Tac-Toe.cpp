#include "Tic-Tac-Toe.hpp"
#include <iostream>

Game_TTT::Game_TTT() : turn('X') , turns(0){
    std::cout<<"Game Started !!\n\n";
}

Game_TTT::Game_TTT(char turn) : turn(turn) , turns(0){
    std::cout<<"Game Started !!\n\n";
    for(int i=0;i<)
}

void Game_TTT::winner(char player){
    std::cout<<"\n\nWinnnnnnnnnerrrrr !! PLAYER "<<player<<" is the WINNER !!!!\n\n";
}

void Game_TTT::printBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;i<3;j++){
            if(!board[i][j]) std::cout<<" - ";
            else if(board[i][j]==1) std::cout<<" X ";
            else std::cout<<" O ";
        }
        std::cout<<std::endl;
    }
}

int Game_TTT::playTurn(int x,int y){
    if(x<0 || x>2 || y<0 || y>2 || board[x][y]){
        std::cout<<"Invalid input . Try again"<<std::endl;
        return 0;
    }
    else if(this->turn == 'X') board[x][y]=1;
    else board[x][y]=2;
    this->turn = (this->turn == 'X' ? 'O':'X');
    return 1;
}

bool Game_TTT::checkBoard(){
    for(int check=0;check<8;check++){
        int r = rowNum[check] , c = colNum[check] , ic_r = increaseRow[check] , ic_c = increaseCol[check];
        int cnt = 0 , first = board[r][c];
        if(first==0)
            continue;
        for(int steps=0;steps<3; steps++ , r+=ic_r , c+=ic_c)
            cnt += (first == board[r][c]);
        if(cnt == 3){
            winner(turn);
            return true;
        } 
    }
    return false;
}

void Game_TTT::multiPlayer(){
    std::cout<<"Player ( "<<this->turn<<" ) Turn"<<std::endl;
    std::cout<<"Enter your choice [row,column]: ";
    while(true){
        if(turns == 9){
            std::cout<<"\n\nTie Game!\n\n"; break;
        }
        int row,column;
        std::cin>>row>>column;
        row--,column--;
        if(!playTurn(row,column))
            continue;
        printBoard();
        if(checkBoard())
            break;
        turns++;
    }
}
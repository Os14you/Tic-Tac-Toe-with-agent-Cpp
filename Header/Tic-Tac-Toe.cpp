#include "Tic-Tac-Toe.hpp"
#include <iostream>

Game::Game() : Game('X') {}
Game::Game(char turn) : turn(turn) , turns(0){
    std::cout<<"Game Started !!\n\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            board[i][j] = 0;
    }
    /*
    int cnt=0;
    for(int r=0;r<3;r++)
        rowNum[cnt]=r ,colNum[cnt]=0 ,increaseRow[cnt]=0 , increaseCol[cnt++]=1;
    for(int c=0;c<3;c++)
        rowNum[cnt]=0 ,colNum[cnt]=c ,increaseRow[cnt]=1 , increaseCol[cnt++]=0;
    rowNum[cnt]=0 ,colNum[cnt]=0 ,increaseRow[cnt]=1 ,increaseCol[cnt++]=1;
    rowNum[cnt]=0 ,colNum[cnt]=2 ,increaseRow[cnt]=1 ,increaseCol[cnt++]=-1;
    */
}

void Game::winner(char player){
    std::cout<<"\n\nWinnnnnnnnnerrrrr !! PLAYER "<<player<<" is the WINNER !!!!\n\n";
}

void Game::printBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!board[i][j]) std::cout<<" - ";
            else if(board[i][j]==1) std::cout<<" X ";
            else std::cout<<" O ";
        }
        std::cout<<std::endl;
    }
}

int Game::playTurn(int x,int y){ 
    if(x<0 || x>2 || y<0 || y>2 || board[x][y]){
        std::cout<<"\n\nInvalid input . Try again\n\n"<<std::endl;
        return 0;
    }
    else if(this->turn == 'X') board[x][y]=1;
    else board[x][y]=2;
    return 1;
}

bool Game::checkBoard(){
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
    this->turn = (this->turn == 'X' ? 'O':'X');
    return false;
}

void Game::multiPlayer(){
    while(true){
        if(turns == 9){
            std::cout<<"\n\nTie Game!\n\n"; break;
        }
        std::cout<<"Player ( "<<this->turn<<" ) Turn"<<std::endl;
        std::cout<<"Enter your choice [row,column]: ";
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
#include <iostream>
#include <Game.hpp>

int menu(const bool &isFirstTime){
    int choice;
    if(isFirstTime)
        std::cout << "---------- Welcome To Our Game ----------\n\n";
    std::cout << "1. Single player Mode \n2. Multiplayer Mode\n3. Exit\n";
    std::cout << "Enter your choice : ";
    std::cin >> choice;

    while(choice < 1 || choice > 3){
        std::cout<<"Enter a valid input : ";
        std::cin>>choice;
    }
    return choice;
}

void aGame(){
    bool isFirstTime = true;
    while(true){
        Game game;
        int choice = menu(isFirstTime);
        isFirstTime = false;
        
        switch (choice){
            case 1: game.singlePlayer(); break;
            case 2: game.multiPlayer(); break;
            default: return;
        }
    }
}
int main(){
    aGame();
    return 0;
}
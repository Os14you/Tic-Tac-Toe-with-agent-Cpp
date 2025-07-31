#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <limits>

/**
 * @brief Displays a stylish ASCII art title for the game.
 */
void display_title() {
    std::string version = "3.0.0";

    std::cout << "\n\n";
    std::cout << "████████╗██╗ ██████╗    ████████╗ █████╗  ██████╗    ████████╗ ██████╗ ███████╗\n";
    std::cout << "╚══██╔══╝██║██╔════╝    ╚══██╔══╝██╔══██╗██╔════╝    ╚══██╔══╝██╔═══██╗██╔════╝\n";
    std::cout << "   ██║   ██║██║            ██║   ███████║██║            ██║   ██║   ██║█████╗  \n";
    std::cout << "   ██║   ██║██║            ██║   ██╔══██║██║            ██║   ██║   ██║██╔══╝  \n";
    std::cout << "   ██║   ██║╚██████╗       ██║   ██║  ██║╚██████╗       ██║   ╚██████╔╝███████╗\n";
    std::cout << "   ╚═╝   ╚═╝ ╚═════╝       ╚═╝   ╚═╝  ╚═╝ ╚═════╝       ╚═╝    ╚═════╝ ╚══════╝\n";
    std::cout << "\n";
    std::cout << "Version " << version << "                                                     by Osama Yousef\n";
    std::cout << "\n\n";
}

/**
 * @brief Displays the main menu and gets the user's game mode choice.
 * @return An integer representing the user's choice.
 */
int display_menu() {
    int choice;
    std::cout << "---------------------\n";
    std::cout << "      GAME MENU      \n";
    std::cout << "---------------------\n";
    std::cout << "1. Human vs. AI\n";
    std::cout << "2. Human vs. Human\n";
    std::cout << "3. AI vs. AI (Spectate)\n";
    std::cout << "4. Exit\n";
    std::cout << "---------------------\n";
    std::cout << "Enter your choice: ";

    // Loop until a valid integer choice is made
    while (!(std::cin >> choice) || choice < 1 || choice > 4) {
        std::cout << "Invalid input. Please enter a number between 1 and 4: ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    
    return choice;
}

/**
 * @brief The main entry point of the application.
 */
int main() {
    display_title();

    // Main application loop
    while (true) {
        int choice = display_menu();

        // If the choice is to exit, break the loop
        if (choice == 4) {
            std::cout << "\nThanks for playing!\n";
            break;
        }

        // Create a new game based on the user's choice
        switch (choice) {
            case 1: {
                std::cout << "\n--- Starting Human (X) vs. AI (O) ---\n";
                Game game('h', 'a');
                game.run();
                break;
            }
            case 2: {
                std::cout << "\n--- Starting Human (X) vs. Human (O) ---\n";
                Game game('h', 'h');
                game.run();
                break;
            }
            case 3: {
                std::cout << "\n--- Starting AI (X) vs. AI (O) ---\n";
                Game game('a', 'a');
                game.run();
                break;
            }
        }
        std::cout << "\nPress Enter to return to the menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear previous input
        std::cin.get(); // Wait for user to press Enter
    }

    return 0;
}

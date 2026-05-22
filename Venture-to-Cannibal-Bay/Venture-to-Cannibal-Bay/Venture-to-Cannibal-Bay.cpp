// Venture-to-Cannibal-Bay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <thread>
#include "MainMenu.h"
#include "PrintFile.h"
#include "Player.h"
#include "Ship.h"
#include "GameLoop.h"

using namespace std;
int main()
{

    // creates the player and pointer as well as passing the pointer to the came loop
    Player user = Player();
    Player* userPointer = &user;
    GameLoop game = GameLoop(userPointer);
    //starts the game
    game.playGame();
    //loops through the game if the player fails at any point that is not the end
    if (user.getRepeat() == true) {
        while (user.getRepeat() == true) {
            Player user = Player();
            user.setRepeat(false);
            Player* userPointer = &user;
            GameLoop game = GameLoop(userPointer);
            game.playGame();

        }
    }
    
 
}


// Venture-to-Cannibal-Bay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <thread>
#include "MainMenu.h"
#include "PrintFile.h"
#include "Player.h"
using namespace std;
/*
* print title
* menu option, begin quit
* ship animation
* print pirates
* choose between ammo food people
* ship animation
* print sirens
* choose between ammo food people
* ship animations
* print cyclone
* choose between ammo food people
*/
int main()
{

    /*
    AsciiArt title = AsciiArt("./Ascii-art/Title.txt");
    title.printAscii();
    */

    /*
    */
    Player user = Player();
    MainMenu Start = MainMenu();
    Start.displayMenu();

}


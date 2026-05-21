#include "ShipRoom.h"
#include "Ship.h"

ShipRoom::ShipRoom() {
	this->playerX = 1;
	this->playerY = 3;
	this->mapWidth = 22;
	this->mapHeight = 8;
	this->playerChar = '>';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/testMap.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;

}
ShipRoom::ShipRoom(Player* cUser) {
	this->playerX = 2;
	this->playerY = 5;
	this->mapWidth = 21;
	this->mapHeight = 8;
	this->playerChar = '>';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	//called testmap as it was set up to test then it was converted into a level
	this->filename = "./Ascii-art/testMap.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;
	this->user = cUser;
}



void ShipRoom::mapLoop() {
	//this sets up all the features and details for the map and then passes the relevent data to the entities so the can do the calculations to move in the map
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->user->setX(playerX);
	this->user->setY(playerY);
	this->user->setMap(this->mapPointer);


	bool quit = false;
	//sets messagge that will print at bottom of the screen showing controls
	this->map.setMessage("press arrow keys to move, and F to interact");
	//main game loop, loops through getting postions and updating map until quit == true
	while (quit == false) {
		clock_t start = clock();
		//sets the colour of the text to green
		system("Color 0A");
		//######## Process Input ########//

		//checks if the player is alive and allows them to move
		if (this->user->isAlive()) {
			this->user->Move();
		}
		//keeps track of the total clues that the play has access to so when the player collects one it changes the text so the player cant interact with it
		if (this->user->getTotalClues() == 3) {
			this->map.changeChar('|');
			this->map.moveEntity(9,4);
			this->map.moveEntity(9,5);

		}
		//checks the players position if they stop on a certain tile they leace the level
		if (this->user->getY() == 5 and this->user->getX() == 0) {
			quit = true;

		}
		
		//clears the system and the displays the new map and all the changes as well as all player information
		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;
		cout << "Lives: " << this->user->getLives() << endl;
		cout << "Ammo: " << this->user->getAmmo() << endl;
		cout << "Clues " << this->user->getClues() << "/8" << endl;
		cout << "Time Left: " << this->user->getFood() << endl;
		cout << "total clues" << this->user->getTotalClues() << endl;

		//######## Render ########//




		//Calculating how long to wait to achieve desired FPS.

		
		clock_t end = clock();
		int msDuration = end - start;
		//after trial and error this gives the best frame rate
		int msRemaining = 100 - msDuration; 
		this->user->setFood(this->user->getFood() - msRemaining);
		this_thread::sleep_for(chrono::milliseconds(msRemaining));

		



	}
}
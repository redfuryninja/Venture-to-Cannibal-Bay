#include "Beach.h"
#include "PrintFile.h"

Beach::Beach() {
	this->playerX = 3;
	this->playerY = 1;
	this->mapWidth = 66;
	this->mapHeight = 20;
	this->playerChar = '>';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/Beach.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;
}

Beach::Beach(Player* cUser) {
	this->user = cUser;
	this->playerX = 3;
	this->playerY = 10;
	this->user->setX(playerX);
	this->user->setY(playerY);
	this->mapWidth = 66;
	this->mapHeight = 20;
	this->playerChar = '>';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/Beach.txt";
	this->map = Maps(this->filename);



}


void Beach::mapLoop() {
	
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->user->setMap(this->mapPointer);
	int count = 0;
	this->user->setShipKey(true);
	
	
	for (int i = 0; i < 63; i++) {
		if (count == 0) {
			Enemy nEnemy = Enemy();
			nEnemy.setChar('X');
			nEnemy.setY(1);
			nEnemy.setX(i + 1);
			count = 1;
			this->meleeEnemies.push_back(nEnemy);

		}
		else if (count == 1) {
			count = 0;
			Enemy nEnemy = Enemy();
			nEnemy.setChar('x');
			nEnemy.setY(1);
			nEnemy.setX(i + 1);
			count = 0;
			this->meleeEnemies.push_back(nEnemy);
		}
	}

	for (int i = 0; i < this->meleeEnemies.size(); i++) {
		this->meleeEnemies[i].setMap(this->mapPointer);
	}
	
	

	bool quit = false;
	this->map.changeChar('v');
	this->map.moveEntity(this->user->getX(), this->user->getY());
	system("cls");
	cout << this->map.getMap() << endl;
	cout << this->map.getMessage() << endl;
	cout << "Lives: " << this->user->getLives() << endl;
	cout << "Ammo: " << this->user->getAmmo() << endl;
	cout << "Clues " << this->user->getClues() << "/7" << endl;
	cout << "Time Left: " << this->user->getFood() << endl;
	this->map.setMessage("press arrow keys to move and F to interact");

	while (quit == false) {

		clock_t start = clock();
		
		//######## Process Input ########//
		/*
		create map
		pass map to entity
		run entity movement
		give map entity coords

		*/


		for (int i = 0; i < this->meleeEnemies.size(); i++) {
			if (this->meleeEnemies[i].isAlive()) {
				this->meleeEnemies[i].Move();
			}

		}


			this->user->Move();






			
			if (this->user->getY() == 12 and this->user->getX() == 56) {
				quit = true;
				if (this->user->getTotalClues() != 2) {
					this->user->setTotalClues(2);
					this->user->setTreePoint();
					this->user->setShipKey(false);
				}
				
			}

			else if (this->user->getY() == 12) {
				if (this->user->getShipKey() == true) {
					this->map.setMessage("if you face that door and press F you can open it");
				}
			}
			
			if (this->user->getTotalClues() == 2) {
				this->map.changeChar('|');
				this->map.moveEntity(56, 7);

			}



			system("Color 0B");
			system("cls");
			cout << this->map.getMap() << endl;
			cout << this->map.getMessage() << endl;
			cout << "Lives: " << this->user->getLives() << endl;
			cout << "Ammo: " << this->user->getAmmo() << endl;
			cout << "Clues " << this->user->getClues() << "/8" << endl;
			cout << "Time Left: " << this->user->getFood() << endl;






			//######## Render ########//

			clock_t end = clock();
			int msDuration = end - start;
			int msRemaining = 100 - msDuration;
			this->user->setFood(this->user->getFood() - msRemaining);
			this_thread::sleep_for(chrono::milliseconds(msRemaining));


		}

	}
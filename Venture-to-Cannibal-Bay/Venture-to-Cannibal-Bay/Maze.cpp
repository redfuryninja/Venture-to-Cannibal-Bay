#include "Maze.h"
#include "Ship.h"
#include "ShipRoom.h"
#include "PrintFile.h"
Maze::Maze() {
	Player Pointer = Player();
	this->user = &Pointer;
	this->playerX = 73;
	this->playerY = 3;
	this->mapWidth = 79;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/Maze.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;
}
Maze::Maze(Player* cUser) {
	this->user = cUser;
	this->playerX = 73;
	this->playerY = 3;
	this->mapWidth = 79;
	this->mapHeight = 50;
	this->playerChar = '^';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/Maze.txt";
	this->map = Maps(this->filename);



}

void Maze::createEnemies() {
	Enemy maori1 = Enemy();
	Enemy maori2 = Enemy();
	Enemy maori3 = Enemy();
	Enemy maori4 = Enemy();
	Enemy maori5 = Enemy();
	Enemy maori9 = Enemy();
	Enemy maori10 = Enemy();

	maori1.setX(26);
	maori1.setY(1);
	maori1.setOrientation(LEFT);

	maori2.setX(2);
	maori2.setY(31);

	maori3.setX(35);
	maori3.setY(11);

	maori4.setX(66);
	maori4.setY(17);
	maori4.setOrientation(LEFT);


	maori5.setX(19);
	maori5.setY(33);

	maori9.setX(49);
	maori9.setY(41);
	maori9.setOrientation(LEFT);

	maori10.setX(74);
	maori10.setY(49);

	RangeEnemy maori6 = RangeEnemy();
	RangeEnemy maori7 = RangeEnemy();
	RangeEnemy maori8 = RangeEnemy();

	maori6.setX(50);
	maori6.setY(7);

	maori7.setX(74);
	maori7.setY(31);

	maori8.setX(1);
	maori8.setY(2);

	maori6.setMap(this->mapPointer);
	maori8.setMap(this->mapPointer);
	maori7.setMap(this->mapPointer);

	maori6.fillquiver();
	maori7.fillquiver();
	maori8.fillquiver();

	maori6.setOrientation(DOWN);
	maori7.setOrientation(UP);

	this->meleeEnemies = { maori1, maori2, maori3, maori4, maori5, maori9, maori10 };
	this->rangedEnemies = {maori6, maori7, maori8};


}
void Maze::mapLoop() {

	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->createEnemies();
	this->user->setX(playerX);
	this->user->setY(playerY);
	this->user->setStartX(playerX);
	this->user->setStartY(playerY);
	this->user->setMap(this->mapPointer);
	this->user->fillMag();
	this->user->setShipKey(true);
	
	
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
	this->map.setMessage("press arrow keys to move, q to shoot and F to open a door you are facing if you have a key");
	while (quit == false) {
		clock_t start = clock();
		system("Color 0C");
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
			else {
				if (this->meleeEnemies[i].getWeaponDeath() == false) {
					this->user->setLives(this->user->getLives() - 1);
					this->map.clearSpace(this->user->getX(), this->user->getY());
					this->user->setX(this->playerX);
					this->user->setY(this->playerY);
					this->map.changeChar('V');
					this->map.moveEntity(this->user->getX(), this->user->getY());
					PrintFile ascii = PrintFile("./Ascii-art/lostLife.txt");
					ascii.OutputAscii();
					cout << " you lost a life" << endl;
					system("pause");
				}
				if (user->getLives() < 0) {
					this->user->kill();
					this->map.setMessage("you lost a life");

				}
				this->map.clearSpace(this->meleeEnemies[i].getX(), this->meleeEnemies[i].getY());
				this->map.moveEntity(0, 0);
				this->meleeEnemies.erase(meleeEnemies.begin() + i, meleeEnemies.begin() + i + 1);
				this->map.clearSpace(0, 0);


			}


		}

		

		for (int i = 0; i < this->rangedEnemies.size(); i++) {
			if (this->rangedEnemies[i].isAlive()) {
				this->rangedEnemies[i].Move();


			}
			else {
				if (this->rangedEnemies[i].getWeaponDeath() == false) {
					this->user->setLives(this->user->getLives() - 1);
					this->map.clearSpace(this->user->getX(), this->user->getY());
					this->user->setX(this->playerX);
					this->user->setY(this->playerY);
					this->map.changeChar('v');
					this->map.moveEntity(this->user->getX(), this->user->getY());
					PrintFile ascii = PrintFile("./Ascii-art/lostLife.txt");
					ascii.OutputAscii();
					cout << " you lost a life" << endl;
					system("pause");
					if (user->getLives() < 0) {
						this->user->kill();
						this->map.setMessage("you lost a life");

					}
				}
				this->map.clearSpace(this->rangedEnemies[i].getX(), this->rangedEnemies[i].getY());
				this->map.moveEntity(0, 0);
				this->rangedEnemies.erase(rangedEnemies.begin() + i, rangedEnemies.begin() + i + 1);
				this->map.clearSpace(0, 0);


			}


		}
		

		if (user->getLives() == 0) {
			system("cls");
			cout << "you ran out of lives and never discovered the fate of the missing crew" << endl;
			system("pause");
			quit = true;
		}
		else if (this->user->isAlive()) {
			this->user->Move();

		}
		else if (this->user->getLives() > 0) {
			this->user->revive();
			this->user->setLives(this->user->getLives() - 1);
			this->map.clearSpace(this->user->getX(), this->user->getY());
			this->user->setX(this->playerX);
			this->user->setY(this->playerY);
			this->map.changeChar('v');
			this->map.moveEntity(this->user->getX(), this->user->getY());
		}





		
		this->user->moveBullet();

		for (int i = 0; i < this->rangedEnemies.size(); i++) {
			this->rangedEnemies[i].moveArrow();
		}
		

		if (this->user->getY() == 50 and this->user->getX() == 38) {
			quit = true;
		}



		else {
			this->map.setMessage("press arrow keys to move, q to shoot and F to open a door you are facing if you have a key");
		}



		system("cls");
	
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;
		cout << "Lives: " << this->user->getLives() << endl;
		cout << "Ammo: " << this->user->getAmmo() << endl;
		cout << "Clues " << this->user->getClues() << "/8" << endl;
		cout << "x: " << this->user->getX() << endl;
		cout << "y: " << this->user->getY() << endl;
		cout << "Time Left: " << this->user->getFood() << endl;





		//######## Render ########//

		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 70 - msDuration;
		this->user->setFood(this->user->getFood() - msRemaining);
		this_thread::sleep_for(chrono::milliseconds(msRemaining));


	}

}
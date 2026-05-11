#include "Ship.h"
#include "ShipRoom.h"
#include "PrintFile.h"
Ship::Ship(){
	Player Pointer = Player();
	this->user = &Pointer;
	this->playerX = 10;
	this->playerY = 2;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/bigShipMap.txt";
	this->map = Maps(this->filename);
	this->mapPointer = &this->map;
}
Ship::Ship(Player* cUser) {
	this->user = cUser;
	this->playerX = 10;
	this->playerY = 2;
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->playerChar = 'V';
	this->mapChar = ' ';
	this->canMoveX = false;
	this->canMoveY = false;
	this->filename = "./Ascii-art/bigShipMap.txt";
	this->map = Maps(this->filename);


	
}

void Ship::createEnemies() {
	Enemy maori1 = Enemy();
	Enemy maori2 = Enemy();
	Enemy maori3 = Enemy();
	Enemy maori4 = Enemy();
	Enemy maori5 = Enemy();
	Enemy maori6 = Enemy();
	RangeEnemy maori7 = RangeEnemy();
	RangeEnemy maori8 = RangeEnemy();
	maori1.setX(2);
	maori2.setX(4);

	maori4.setX(15);
	maori5.setX(17);

	maori7.setX(3);
	maori8.setX(16);

	maori1.setY(33);
	maori2.setY(33);

	maori4.setY(33);
	maori5.setY(33);

	maori7.setY(34);
	maori8.setY(7);

	maori7.setMap(this->mapPointer);
	maori8.setMap(this->mapPointer);
	maori7.fillquiver();
	maori8.fillquiver();
	maori7.setOrientation(UP);
	this->meleeEnemies = { maori1,maori2, maori4, maori5};
	this->rangedEnemies = { maori7, maori8 };

	
}
void Ship::mapLoop() {
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->createEnemies();
	this->user->setMap(this->mapPointer);
	this->user->fillMag();

	
	for (int i = 0; i < this->meleeEnemies.size(); i++) {
		this->meleeEnemies[i].setMap(this->mapPointer);
	}


	bool quit = false;
	this->map.changeChar('V');
	this->map.moveEntity(this->user->getX(), this->user->getY());
	system("cls");
	cout << this->map.getMap() << endl;
	cout << this->map.getMessage() << endl;
	cout << "Lives: " << this->user->getLives() << endl;
	cout << "Ammo: " << this->user->getAmmo() << endl;
	cout << "Clues " << this->user->getClues() << "/10" << endl;
	cout << "Time Left: " << this->user->getFood() << endl;
	this->map.setMessage("press arrow keys to move, q to shoot and F to open a door you are facing if you have a key");
	while (quit == false) {
		clock_t start = clock();

		//######## Process Input ########//
		/*
		create map
		pass map to entity
		run entity movement
		give map entity coords
		
		*/
		
		/*
		*/


		for (int i = 0; i < this->meleeEnemies.size(); i++) {
			if (this->meleeEnemies[i].isAlive()) {
				this->meleeEnemies[i].Move();
			}
			else {
				if (this->meleeEnemies[i].getWeaponDeath() == false) {
					this->user->setLives(this->user->getLives() - 1);
					this->map.clearSpace(this->user->getX(), this->user->getY());
					this->user->setX(10);
					this->user->setY(2);
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
				this->map.clearSpace(0,0);

				
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
					this->user->setX(10);
					this->user->setY(2);
					this->map.changeChar('V');
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
			quick_exit(0);
		}
		else if (this->user->isAlive()) {
			this->user->Move();

		}
		else if (this->user->getLives() > 0) {
			this->user->revive();
			this->user->setLives(this->user->getLives() - 1);
			this->map.clearSpace(this->user->getX(), this->user->getY());
			this->user->setX(10);
			this->user->setY(2);
			this->map.changeChar('V');
			this->map.moveEntity(this->user->getX(), this->user->getY());
		}
	


		

		this->user->moveBullet();
		for (int i = 0; i < this->rangedEnemies.size(); i++) {
		this->rangedEnemies[i].moveArrow();
		}

		if (this->user->getY() == 1 and this->user->getX() == 8) {
			quit = true;
		}
		else if (this->user->getY() == 20 and this->user->getX() == 5) {
			ShipRoom room = ShipRoom(this->user);
			room.mapLoop();
			this->user->setX(4);
			this->user->setY(20);
			this->user->setMap(this->mapPointer);


		}
		else if (this->user->getY() >= 20 and this->user->getY() < 30 ) {
			if (this->user->getShipKey() == true) {
				this->map.setMessage("if you face that door and press F you can open it");
			}
			else {
				this->map.setMessage("if you had a key you could open that door");

			}
		}
		else {
			this->map.setMessage("press arrow keys to move, q to shoot and F to open a door you are facing if you have a key");
		}
		
		

		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;
		cout << "Lives: " << this->user->getLives()<<endl;
		cout << "Ammo: " << this->user->getAmmo()<<endl;
		cout << "Clues " << this->user->getClues() << "/10" << endl;
		cout << "Time Left: " << this->user->getFood()<<endl;
	

	


		
		//######## Render ########//
		
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 100 - msDuration;
		this->user->setFood(this->user->getFood() - msRemaining);
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		
	
		}

	}
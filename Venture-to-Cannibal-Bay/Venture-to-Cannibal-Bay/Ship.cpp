#include "Ship.h"
#include "ShipRoom.h"
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
	maori1.setX(2);
	maori2.setX(4);
	maori3.setX(6);
	maori4.setX(15);
	maori5.setX(17);
	maori6.setX(19);
	maori1.setY(33);
	maori2.setY(33);
	maori3.setY(33);
	maori4.setY(33);
	maori5.setY(33);
	maori6.setY(33);
	

	this->activeEntities = {maori1,maori2, maori4, maori5};
}
void Ship::mapLoop() {
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	this->createEnemies();
	this->user->setMap(this->mapPointer);
	this->user->fillMag();
	
	for (int i = 0; i < this->activeEntities.size(); i++) {
		this->activeEntities[i].setMap(this->mapPointer);
	}


	bool quit = false;

	system("cls");
	cout << this->map.getMap() << endl;
	cout << this->map.getMessage() << endl;
	cout << "Lives: " << this->user->getLives() << endl;
	cout << "Ammo: " << this->user->getAmmo() << endl;
	cout << "Time Left: " << this->user->getFood() << endl;
	cout << "x: " << this->user->getX() << endl;
	cout << "y: " << this->user->getY() << endl;
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


		for (int i = 0; i < this->activeEntities.size(); i++) {
			if (this->activeEntities[i].isAlive()) {
				this->activeEntities[i].Move();
			}
			else {
				if (this->activeEntities[i].getWeaponDeath() == false) {
					this->user->setLives(this->user->getLives() - 1);
					this->map.clearSpace(this->user->getX(), this->user->getY());
					this->user->setX(10);
					this->user->setY(2);
		
					if (user->getLives() < 0) {
						this->user->kill();
						this->map.setMessage("you lost a life");
						}
				}
				this->map.clearSpace(this->activeEntities[i].getX(), this->activeEntities[i].getY());
				this->map.moveEntity(0, 0);
				this->activeEntities.erase(activeEntities.begin() + i, activeEntities.begin() + i + 1);
				this->map.clearSpace(0,0);

				
			}


		}

		if (this->user->isAlive()) {
			this->user->Move();

		}
		

		this->user->moveBullet();
		
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
		else if (this->user->getY() == 20) {
			if (this->user->getShipKey() == true) {
				this->map.setMessage("if you face this door and press F you can open it");
			}
			else {
				this->map.setMessage("if you had a key you could open this door");

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
		cout << "Time Left: " << this->user->getFood()<<endl;
		cout << "x: " << this->user->getX() << endl;
		cout << "y: " << this->user->getY() << endl;

	


		
		//######## Render ########//
		
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 100 - msDuration;
		this->user->setFood(this->user->getFood() - msRemaining);
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		
	
		}

	}
#include "Ship.h"

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
	/*
	
	this->map = "";
	this->filename = "./Ascii-art/bigShipMap.txt";
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
	this->map[this->playerX + this->playerY * this->mapWidth] = this->playerChar;
	
	*/
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

void Ship::fillMag() {
	for (int i = 0; i < this->user->getAmmo() + 1; i++) {
		Entity nBullet = Entity();
		nBullet.setChar('O');
		nBullet.setMap(this->mapPointer);
		this->magazine.push_back(nBullet);
	}

}

void Ship::mapLoop() {
	this->map.createMap();
	this->map.setDimensions(this->mapWidth, this->mapHeight);
	this->mapPointer = &this->map;
	fillMag();
	this->createEnemies();
	this->user->setMap(this->mapPointer);
	
	for (int i = 0; i < this->activeEntities.size(); i++) {
		this->activeEntities[i].setMap(this->mapPointer);
	}


	bool quit = false;
	bool quit2 = false;
	//this->map.setMessage("press arrow keys to move, q to shoot and F to open a door you are facing if you have a key");
	while (quit == false) {
		clock_t start = clock();
		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;
		

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

		if (this->user->getState() == SHOOTING and this->user->getAmmo() > 0) {
			this->user->setState(NUETRAL);
			this->bullet = magazine[this->user->getAmmo()];
			this->user->setAmmo(this->user->getAmmo() - 1);
				if (this->user->getOrientation() == UP) {
					if (this->user->checkSpace(this->user->getX(), this->user->getY() - 1) == true) {
					this->bullet.setState(MOVING);
					this->bullet.setX(this->user->getX());
					this->bullet.setY(this->user->getY()-1);
					this->bullet.setOrientation(UP);
					this->projectiles.push_back(this->bullet);

					}
					

				} 
				else if (this->user->getOrientation() == DOWN ) {
					if (this->user->checkSpace(this->user->getX(), this->user->getY() + 1) == true) {
						this->bullet.setState(MOVING);
						this->bullet.setX(this->user->getX());
						this->bullet.setY(this->user->getY() + 1);
						this->bullet.setOrientation(DOWN);
						this->projectiles.push_back(this->bullet);

					}


				}
				else if (this->user->getOrientation() == LEFT) {
					if (this->user->checkSpace(this->user->getX()-1, this->user->getY()) == true) {
						this->bullet.setState(MOVING);
						this->bullet.setX(this->user->getX()-1);
						this->bullet.setY(this->user->getY());
						this->bullet.setOrientation(LEFT);
						this->projectiles.push_back(this->bullet);

					}


				}
				else if (this->user->getOrientation() == RIGHT) {
					if (this->user->checkSpace(this->user->getX() + 1, this->user->getY()) == true) {
						this->bullet.setState(MOVING);
						this->bullet.setX(this->user->getX() + 1);
						this->bullet.setY(this->user->getY());
						this->bullet.setOrientation(RIGHT);
						this->projectiles.push_back(this->bullet);

					}


				}
		}

		for (int i = 0; i < this->projectiles.size(); i++) {
			if (this->projectiles[i].isAlive()) {
			this->projectiles[i].Move();
			}
			else {
				this->map.changeChar(' ');
				this->map.moveEntity(this->projectiles[i].getX(), this->projectiles[i].getY());
				this->map.moveEntity(0,0);
				this->projectiles.erase(projectiles.begin() + i, projectiles.begin() + i + 1);
			}
			

		}
		
		if (this->user->getY() == 18 and this->user->getX() == 7) {
			this->map.setMessage("access to next room");
		}
		else if (this->user->getY() == 19 and this->user->getX() != 6) {
			if (this->user->getShipKey() == true) {
				this->map.setMessage("if you face this door and press F you can open it");
			}
			else {
				this->map.setMessage("if you had a key you could open this door");

			}
		}

		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;

	


		
		//######## Render ########//
		
		//outputMap();


		//Calculating how long to wait to achieve desired FPS.
		
		/*
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 50 - msDuration; //This game runs at 5 FPS (change from 200 to 33 to try 30 FPS).
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		
		*/
		
		
	
		}
	/*
	while (true) {

		if (this->getKeyValue() == KEY_E) {
			break;
		}
	*/
	}
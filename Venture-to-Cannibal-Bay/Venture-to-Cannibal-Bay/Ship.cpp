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
	this->user->setMap(this->mapPointer);
	bool quit = false;

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

		this->user->Move();

		for (int i = 0; i < this->activeEntities.size(); i++) {
			this->activeEntities[i]->Move();
		}
		if (this->user->getState() == SHOOTING) {
			this->user->setState(NUETRAL);
			this->bullet = magazine[this->user->getAmmo()];

				if (this->user->getOrientation() == UP and this->bullet.getState() != MOVING) {
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
				else if (this->user->getOrientation() == LEFT and this->bullet.getState() != MOVING) {
					if (this->user->checkSpace(this->user->getX()-1, this->user->getY()) == true) {
						this->bullet.setState(MOVING);
						this->bullet.setX(this->user->getX()-1);
						this->bullet.setY(this->user->getY());
						this->bullet.setOrientation(DOWN);
						this->projectiles.push_back(this->bullet);

					}


				}
				else if (this->user->getOrientation() == RIGHT and this->bullet.getState() != MOVING) {
					if (this->user->checkSpace(this->user->getX() + 1, this->user->getY()) == true) {
						this->bullet.setState(MOVING);
						this->bullet.setX(this->user->getX() + 1);
						this->bullet.setY(this->user->getY());
						this->bullet.setOrientation(DOWN);
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
		
		system("cls");
		cout << this->map.getMap() << endl;
		cout << this->map.getMessage() << endl;



		
		//######## Render ########//
		
		//outputMap();


		//Calculating how long to wait to achieve desired FPS.
		
		
	
		
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 50 - msDuration; //This game runs at 5 FPS (change from 200 to 33 to try 30 FPS).
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		
	
		}
	/*
	while (true) {

		if (this->getKeyValue() == KEY_E) {
			break;
		}
	*/
	}
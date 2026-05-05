#include "Maps.h"

Maps::Maps(){
	this-> mapWidth = 45;
	this->mapHeight = 6;
	this->map = "";
	this->entityChar = 'E';
	this->mapChar = ' ';
	this->filename = "./Ascii-art/testMap.txt";
	this->artFile= ifstream(this->filename);
	this->linePrint = "";
}

Maps::Maps(string file){
	this->mapWidth = 21;
	this->mapHeight = 42;
	this->map = "";
	this->entityChar = 'E';
	this->mapChar = ' ';
	this->filename = file;
	this->artFile = ifstream(this->filename);
	this->linePrint = "";
}

void Maps::createMap(){
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
}

string Maps::getMap(){
	return this->map;
}

int Maps::getWidth(){
	return this->mapWidth;
}
int Maps::getHeight() {
	return this->mapHeight;
}
void Maps::setDimensions(int width, int height){
	this->mapWidth = width;
	this->mapHeight = height;
}

void Maps::changeChar(int currChar){
	this->entityChar = currChar;
}

void Maps::moveEntity(int x, int y){
	this->map[x + y * this->mapWidth] = this->entityChar;
}

void Maps::clearSpace(int x, int y) {
	this->map[x + y * this->mapWidth] = this->mapChar;
}

char Maps::getMapChar(int x, int y) {
	this->mapChar = map[x + y * this->mapWidth];
	return this->mapChar;
}

string Maps::getMessage() {
	return this->message;
}

void Maps::setMessage(string nMessage) {
	this->message = nMessage;
}
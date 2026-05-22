#include "Maps.h"
//constructors
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
//gets the map from the file and adds it to astring
void Maps::createMap(){
	this->artFile = ifstream(this->filename);
	while (getline(this->artFile, this->linePrint)) {
		this->map += this->linePrint;
		this->map += "\n";
	}
}
//gets character at given coordinates
char Maps::getChar(int x, int y) {
	return this->map[x + y * this->mapWidth];
}
//returns the msp
string Maps::getMap(){
	return this->map;
}
//gets the height and width
int Maps::getWidth(){
	return this->mapWidth;
}
int Maps::getHeight() {
	return this->mapHeight;
}
//set the height and width of the map
void Maps::setDimensions(int width, int height){
	this->mapWidth = width;
	this->mapHeight = height;
}
//changes the character used to change an entityies space
void Maps::changeChar(char currChar){
	this->entityChar = currChar;
}
//moves the entity to the fiven character
void Maps::moveEntity(int x, int y){
	this->map[x + y * this->mapWidth] = this->entityChar;
}
//clears the space at the given coordinates
void Maps::clearSpace(int x, int y) {
	this->map[x + y * this->mapWidth] = ' ';
}
//gets the coorinates and the given coordinates
char Maps::getMapChar(int x, int y) {
	this->mapChar = map[x + y * this->mapWidth];
	return this->mapChar;
}
//returns the message strin
string Maps::getMessage() {
	return this->message;
}
// sets the message string
void Maps::setMessage(string nMessage) {
	this->message = nMessage;
}
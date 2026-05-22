#pragma once
#include <iostream>
#include <thread>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream> 
#include <conio.h>
#include "Maps.h"
using namespace std;
class Maps
{	
private:
	//variables for map manipulation
	int mapWidth;
	int mapHeight;
	string map;
	char entityChar;
	char mapChar;
	string filename;
	ifstream artFile;
	string linePrint;
	string message;
public:
	//constructors
	Maps();
	Maps(string file);
	//creates the map 
	void createMap();
	//returns the map
	string getMap();
	//gets the height and width
	int getWidth();
	int getHeight();
	//sets the dimensions of the map for calculations
	void setDimensions(int width, int height);
	//changes the current character 
	void changeChar(char currChar);
	//moves an entity
	void moveEntity(int x, int y);
	//clears a space
	void clearSpace(int x, int y);
	//get the map char at the corridanates input
	char getMapChar(int x, int y);
	//gets and sets the message
	string getMessage();
	void setMessage(string nMessage);
	//get the map char at the corridanates input accidentally made same function twice
	char getChar(int x, int y);
};

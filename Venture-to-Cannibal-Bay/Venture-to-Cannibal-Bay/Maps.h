#pragma once
#include <iostream>
#include <thread>
#include <windows.h>
#include <string>
#include <fstream>
#include <sstream> 
#include <conio.h>
using namespace std;
class Maps
{	
private:
	int mapWidth;
	int mapHeight;
	string map;
	char entityChar;
	char mapChar;
	string filename;
	ifstream artFile;
	string linePrint;
public:
	Maps();
	Maps(string file);
	void createMap();
	string getMap();
	int getDimensions();
	void setDimensions(int width, int height);
	void changeChar(int currChar);
	void moveEntity(int x, int y);
	void removeEntity(int x, int y);
};

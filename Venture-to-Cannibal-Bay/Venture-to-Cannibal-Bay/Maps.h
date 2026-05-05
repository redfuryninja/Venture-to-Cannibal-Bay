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
	Maps();
	Maps(string file);
	void createMap();
	string getMap();
	int getWidth();
	int getHeight();
	void setDimensions(int width, int height);
	void changeChar(int currChar);
	void moveEntity(int x, int y);
	void clearSpace(int x, int y);
	char getMapChar(int x, int y);
	string getMessage();
	void setMessage(string nMessage);
};

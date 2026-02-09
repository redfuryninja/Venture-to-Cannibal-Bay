#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 
using namespace std;

class AsciiArt
{
private:
	string filename;
	ifstream artFile;
	string linePrint;
public:
	AsciiArt(string nFileName);
	void printAscii();


};


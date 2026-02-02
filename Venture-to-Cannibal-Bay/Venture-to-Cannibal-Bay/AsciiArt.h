#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 
using namespace std;

class AsciiArt
{
private:
	string filename;
	ifstream ArtPrint;
public:
	AsciiArt(string nFileName);
	void printAscii();


};


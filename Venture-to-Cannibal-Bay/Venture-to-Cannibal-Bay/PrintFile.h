#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 

using namespace std;

class PrintFile
{
private:
	string filename;
	ifstream artFile;
	string linePrint;
public:
	//constructor one basic the other takes file name
	PrintFile();
	PrintFile(string nFileName);
	//outputs the file
	void OutputAscii();

};
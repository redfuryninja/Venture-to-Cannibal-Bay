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
	PrintFile(string nFileName);
	void OutputAscii();


};


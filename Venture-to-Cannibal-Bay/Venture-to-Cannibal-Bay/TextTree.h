#pragma once
#include "TextColour.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <conio.h>

using namespace std;
class TextTree
{
private:
	//point for reference where to read from in the vector
	int treePoint;
	//vector containing all text dialouge
	vector <vector <string>> clues;
public:
	//constructor
	TextTree();
	//getters and setters for treepoint variable
	int getTreePoint();
	void setTreePoint(int nPoint);
	//output for text in vector
	void outputText();
	//gets vector size
	int getClueSize();
};


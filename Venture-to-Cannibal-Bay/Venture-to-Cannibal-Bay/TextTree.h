#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <conio.h>

using namespace std;
class TextTree
{
private:
	int treePoint;
	vector <vector <string>> books;
	map <string, int> investigation; 
public:
	TextTree();
	int getTreePoint();
	void setTreePoint(int nPoint);
	void outputText();
	int getBookSize();
};


#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class TextTree
{
private:
	int treePoint;
	vector <vector <string>> text;
public:
	TextTree();
	int getTreePoint();
	void setTreePoint(int nPoint);

};


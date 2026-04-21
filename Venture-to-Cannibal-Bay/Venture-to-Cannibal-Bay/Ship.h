#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;
class Ship
{
private:
	vector<vector<string>> map;
public:
	Ship();
	void outputMap();
};


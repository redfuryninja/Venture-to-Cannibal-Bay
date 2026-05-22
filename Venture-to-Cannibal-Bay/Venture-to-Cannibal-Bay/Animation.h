#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include <fstream>
#include <sstream> 
#include <ctime>
#include <thread>
#include "PrintFile.h"
class Animation
{
private:

public:
	Animation();
	//plays the ascii animations for different scenes
	void swordAnimation();
	void gunAnimation();
	void arrowAnimation();
};


#include "TextColour.h"
void TextColour::changeColour(int colour) {

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colour);
}
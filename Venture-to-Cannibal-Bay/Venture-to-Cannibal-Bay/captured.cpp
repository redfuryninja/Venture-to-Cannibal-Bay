#include "captured.h"
captured::captured() {
	this->fileName;
	
	this->colour = TextColour();
}
captured::captured(Player* c_User) {
	this->colour = TextColour();
	this->fileName = "./Ascii-art/surrounded.txt";
	this->user = c_User;
}

void captured::cutscene() {
	system("cls");
	PrintFile ascii = PrintFile(this->fileName);
	ascii.OutputAscii();
	this->colour.changeColour(4);
	this->user->outputClue();
	this->colour.changeColour(15);
}
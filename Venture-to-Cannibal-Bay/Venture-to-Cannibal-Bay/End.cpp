#include "End.h"
#include "Animation.h"
End::End() {
	this->fileName;
	this->colour = TextColour();
	
}
End::End(Player* c_User) {
	this->colour = TextColour();
	this->fileName = "./Ascii-art/messageBird.txt";
	this->user = c_User;
	this->endMessage = { 
		{"You got the good ending, you were able to gather enough information", "the English don't view the Maori as monsters and will only use as much force as is needed to rescue the survivors of the boyd massacre"},
		{"You got the bad ending, you were not able to gather enough information", "the Maori tribe will now be viewed as horrible monsters and be wiped out by the English"}};
}

void End::Ending() {
	Animation ani = Animation();
	system("cls");
	PrintFile ascii = PrintFile(this->fileName);
	ascii.OutputAscii();
	this->colour.changeColour(4);
	cout << "You managed to escape the Maori prison and get back to your ship where a Carrier Pidgeon Awaits your message, you quickly scribble down all that you know" << endl;
	system("pause");
	ani.arrowAnimation();
	this->colour.changeColour(15);
	
	
	if (this->user->getClues() >= 6 ) {
		PrintFile ascii = PrintFile("./Ascii-art/youWin.txt");
		ascii.OutputAscii();
		for (int i = 0; i < this->endMessage[0].size(); i++) {
			TextColour colour;
			colour.changeColour(10);
			cout << this->endMessage[0][i] << endl;
			colour.changeColour(15);
			system("pause");
		}
	}
	else {
		PrintFile ascii = PrintFile("./Ascii-art/youLose.txt");
		ascii.OutputAscii();
		system("pause");
		for (int i = 0; i < this->endMessage[0].size(); i++) {
			TextColour colour;
			colour.changeColour(64);
			cout << this->endMessage[1][i] << endl;
			colour.changeColour(15);
			system("pause");
		}
	}
	
	
}
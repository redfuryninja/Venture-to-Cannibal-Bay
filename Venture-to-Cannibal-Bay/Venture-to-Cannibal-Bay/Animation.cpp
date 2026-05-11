#include "Animation.h"

Animation::Animation() {

}

void Animation::swordAnimation() {
	bool quit = false;
	int pos = 0;
	for (int i = 0; i < 20; i++) {
		clock_t start = clock();
		system("cls");
		if (pos == 0) {
			PrintFile ascii = PrintFile("./Ascii-art/sword.txt");
			ascii.OutputAscii();
			pos = 1;

		}
		else if (pos == 1) {
			PrintFile ascii2 = PrintFile("./Ascii-art/fight.txt");
			ascii2.OutputAscii();
			pos = 0;

		}
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 150 - msDuration;
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		
	}
}

void Animation::gunAnimation() {
	bool quit = false;
	int pos = 0;
	for (int i = 0; i < 20; i++) {
		clock_t start = clock();
		system("cls");
		if (pos == 0) {
			PrintFile ascii = PrintFile("./Ascii-art/gunsFrame1.txt");
			ascii.OutputAscii();
			pos = 1;

		}
		else if (pos == 1) {
			PrintFile ascii2 = PrintFile("./Ascii-art/gunsFrame2.txt");
			ascii2.OutputAscii();
			pos = 2;

		}
		else if (pos == 2) {
			PrintFile ascii2 = PrintFile("./Ascii-art/gunsFrame3.txt");
			ascii2.OutputAscii();
			pos = 3;

		}
		else if (pos == 3) {
			PrintFile ascii2 = PrintFile("./Ascii-art/gunsFrame4.txt");
			ascii2.OutputAscii();
			pos = 4;

		}
		else if (pos == 4) {
			PrintFile ascii2 = PrintFile("./Ascii-art/gunsFrame5.txt");
			ascii2.OutputAscii();
			pos = 0;

		}

		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 150 - msDuration;
		this_thread::sleep_for(chrono::milliseconds(msRemaining));
		
	}
}
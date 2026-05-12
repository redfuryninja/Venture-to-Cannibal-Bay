#include "Animation.h"

Animation::Animation() {

}
void Animation::arrowAnimation(){
	bool quit = false;
	int pos = 0;
	for (int i = 0; i < 27; i++) {
		clock_t start = clock();
		system("cls");
		if (pos == 0) {
			PrintFile ascii1 = PrintFile("./Ascii-art/arrowFrame1.txt");
			ascii1.OutputAscii();
			pos = 1;

		}
		else if (pos == 1) {
			PrintFile ascii2 = PrintFile("./Ascii-art/arrowFrame2.txt");
			ascii2.OutputAscii();
			pos = 2;

		}
		else if (pos == 2) {
			PrintFile ascii3 = PrintFile("./Ascii-art/arrowFrame3.txt");
			ascii3.OutputAscii();
			pos = 3;

		}
		else if (pos == 3) {
			PrintFile ascii4 = PrintFile("./Ascii-art/arrowFrame4.txt");
			ascii4.OutputAscii();
			pos = 4;

		}
		else if (pos == 4) {
			PrintFile ascii5 = PrintFile("./Ascii-art/arrowFrame5.txt");
			ascii5.OutputAscii();
			pos = 5;

		}
		else if (pos == 5) {
			PrintFile ascii6 = PrintFile("./Ascii-art/arrowFrame6.txt");
			ascii6.OutputAscii();
			pos = 6;

		}
		else if (pos == 6) {
			PrintFile ascii7 = PrintFile("./Ascii-art/arrowFrame7.txt");
			ascii7.OutputAscii();
			pos = 7;

		}
		else if (pos == 7) {
			PrintFile ascii8 = PrintFile("./Ascii-art/arrowFrame8.txt");
			ascii8.OutputAscii();
			pos = 8;

		}
		else if (pos == 8) {
			PrintFile ascii9 = PrintFile("./Ascii-art/arrowFrame9.txt");
			ascii9.OutputAscii();
			pos = 0;

		}
		clock_t end = clock();
		int msDuration = end - start;
		int msRemaining = 200 - msDuration;
		this_thread::sleep_for(chrono::milliseconds(msRemaining));

	}
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
#include "AsciiArt.h"

AsciiArt::AsciiArt(string nFileName) {
	this->filename = nFileName;
	this->artFile = ifstream(this->filename);

}
void AsciiArt::printAscii() {
	while (getline(this->artFile, this->linePrint)) {
		cout << linePrint << endl;
	}
}
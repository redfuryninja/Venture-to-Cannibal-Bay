#include "AsciiArt.h"

AsciiArt::AsciiArt(string nFileName) {
	this->filename = nFileName;
	this->ArtPrint = ifstream(filename);

}
void printAscii() {

}
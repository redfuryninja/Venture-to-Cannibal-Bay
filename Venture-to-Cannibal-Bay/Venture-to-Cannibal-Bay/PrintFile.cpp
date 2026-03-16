#include "PrintFile.h"

PrintFile::PrintFile() {
	this->filename = "./Ascii-art/Title.txt";
	this->artFile = ifstream(this->filename);
}
PrintFile::PrintFile(string nFileName) {
	this->filename = nFileName;
	this->artFile = ifstream(this->filename);

}
void PrintFile::OutputAscii() {
	while (getline(this->artFile, this->linePrint)) {
		cout << linePrint << endl;
	}
}


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
	string buffer = "";
	while (getline(this->artFile, this->linePrint)) {
		buffer += this->linePrint;
		buffer += "\n";
	}
	cout << buffer << endl;
}


#include "PrintFile.h"

PrintFile::PrintFile() {
	this->filename = "./Ascii-art/Title.txt";
	this->artFile = ifstream(this->filename);
}
//gets the file
PrintFile::PrintFile(string nFileName) {
	this->filename = nFileName;
	this->artFile = ifstream(this->filename);

}
void PrintFile::OutputAscii() {
	string buffer = "";
	//adds the line from the file to a string so it can all be output at the same time decreacing resources used
	while (getline(this->artFile, this->linePrint)) {
		buffer += this->linePrint;
		buffer += "\n";
	}
	cout << buffer << endl;
}


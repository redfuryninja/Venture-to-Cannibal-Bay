#include "TextTree.h"

TextTree::TextTree() {
	this->treePoint = 0;
	this->books = { 
		{"you have found a burnt book next to a pile of bloodsoaked clothes", "Captains log X1 October 1809", "j--r--y f--m Aus---lia to n-- z---and", "George stole. wh-pp-d him -it- 9 tails"}
	};
	this->investigation = { {"descision1", 0}, {"descision2", 0}, {"descision3", 0}, {"descision4", 0}};
}
int TextTree::getTreePoint() {
	return this->treePoint;
}
void TextTree::setTreePoint(int nPoint) {
	this->treePoint = nPoint;
}

int TextTree::getBookSize() {
	return this->books.size();
}
void TextTree::outputText() {

	for (int i = 0; i < this->books[this->treePoint].size(); i++) {
		cout << this->books[this->treePoint][i] << endl;
		system("pause");
	}
}

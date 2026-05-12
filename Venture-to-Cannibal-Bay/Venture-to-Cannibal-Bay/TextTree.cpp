#include "TextTree.h"

TextTree::TextTree() {
	this->treePoint = 0;
	this->clues = { 
		{"You and your crew have been sent off on an expedition to Whangaroa Harbour in New Zealand", "Its crew containing 70 passangers containing the crew, prisoners and the son of a Maori chief have gone missing", "It is up to you to investigate their dissapearence and figure out what happened to them"},
		{"You find shards of a burnt and broken barrel with coated with gunpowder residue", "it's clear that the ships stores of gunpoder was used to blow up and set fire to the ship"},
		{"You have found a burnt book next to a pile of bloodsoaked clothes", "Captains log X1 October 1809", "j--r--y f--m Aus---lia to n-- z---and", "George stole. wh-pp-d him -it- 9 tails"}
	};
	this->investigation = { {"descision1", 0}, {"descision2", 0}, {"descision3", 0}, {"descision4", 0}};
}
int TextTree::getTreePoint() {
	return this->treePoint;
}
void TextTree::setTreePoint(int nPoint) {
	this->treePoint = nPoint;
}

int TextTree::getClueSize() {
	return this->clues.size();
}
void TextTree::outputText() {

	for (int i = 0; i < this->clues[this->treePoint].size(); i++) {
		system("Color 03");
		cout << this->clues[this->treePoint][i] << endl;
	
		system("pause");
	}
}

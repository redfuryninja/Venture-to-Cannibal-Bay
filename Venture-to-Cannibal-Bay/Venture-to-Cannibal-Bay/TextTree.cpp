#include "TextTree.h"

TextTree::TextTree() {
	this->treePoint = 0;
	this->clues = { 
		{"You and your crew have been sent off on an expedition to Whangaroa Harbour in New Zealand", "Its crew containing 70 passangers containing the crew, prisoners and the son of a Maori chief have gone missing", "It is up to you to investigate their dissapearence and figure out what happened to them"},
		{"you find piles of human bones along the shoreline being pushed back and forth by the sea", "You also locate shards of a burnt and broken barrel with coated with gunpowder residue", "it's clear that the ships stores of gunpoder was used to blow up and set fire to the ship", "did the crew accidentally blow up the boat and wild animals eat their flesh"},
		{"You have found a burnt book next to a pile of bloodsoaked clothes", "Captains log X1 October 1809", "j--r--y f--m Aus---lia to n-- z---and", "George stole. wh-pp-d him -it- 9 tails"},
		{"As you exit the Ship you find yourself surrounded by Maori Folk, they belong to same tribe that attacked you in the ship Ngati Pou", "At the front of the crowd you see the chief of the tribe and his son", " the chief started speaking to you",  "'go home Pakeha your kind has caused enough damage look what you did to my son'", "he gestured to his son who was covered in whip lashings", " 'we can't leave not until we find out what happened to the crew of they Boyd that you son was apart of' you spoke", "this angered the maori chief as his men surrounded and captured you"},
		{"You see 2 year old  Elizabeth Broughton child in a cage", "'Monsters'", "'Monsters ate Papa'"},
		{"You find the Apprentice Thomas Davis in a cage curled up in a corner muttering to himself", "'it's my fault, it's all my fault'", "'i accidentally tossed the pewter spoons I...I pinned it on george'"},
		{"you find a Mother, Ann Morley and her baby, somehow she seems to be the most level headed of all the survivors as she comforted her baby", "'they accused the chief's son Te Ara of stealing all this was them getting revenge'", "'how much death and destruction will follow this i wonder'"}
	};
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
	HANDLE  hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < this->clues[this->treePoint].size(); i++) {
		TextColour colour;
		colour.changeColour(64);
		cout << this->clues[this->treePoint][i] << endl;
		colour.changeColour(15);
		system("pause");
	}
}

#ifndef WORD_H
#define WORD_H

#include "BinarySearchTree.h"
#include "Indexer.h"
#include "stdlib.h"
#include <iostream>
#include <queue>
#include <string>

class Word{

public:
	Word();
	Word(string inWord, int lineNumber);
	string GetWord();
	void CountWord(int lineNumber);
	bool operator<(const Word &RHS) const;
	bool operator==(const Word &RHS) const;
	Word operator=(const Word &RHS);
	friend ostream operator<<(ostream out, Word &inWord);

private:
	int count;
	queue<int> lineNumbers;
	string wordText;

};

#endif
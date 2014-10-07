#include "Word.h"

//default constructor
Word::Word()
{
	wordText = "";
	count = 0;
}

//constructs a word with given string and linenumber arguments
Word::Word(string inWord, int lineNumber)
{
	wordText = inWord;
	count = 0;
	lineNumbers.push(lineNumber);

}

//returns the wordText from requested Word
string Word::GetWord()
{
	return wordText;
}

//adds first occurnce of line number to queue, increments count
void Word::CountWord(int lineNumber)
{
	//if line number is not already in queue
	if(lineNumbers.back() != lineNumber)
	{
		lineNumbers.push(lineNumber);
	}

	count++;
}

//returns true if RHS wordText is greater
bool Word::operator<(const Word &RHS) const
{
	return wordText < RHS.wordText;
}

//returns true if both wordTexts are equal
bool Word::operator==(const Word &RHS) const
{
	return wordText == RHS.wordText;
}

//assigns the wordText to the wordText of RHS
Word Word::operator=(const Word &RHS) 
{
	//makes sure not already equal
	if(this == &RHS)
		return *this;
	wordText = RHS.wordText;
	return *this;
}

//outputs information about word including
ostream operator<<(ostream out, Word &inWord)
{
	//gets length of text to know how many '.'s to offset
	int wordLen = inWord.wordText.length();
	int count = 0;
	//print word
	out << inWord.wordText;
	//print periods until correct amount for spacing
	for(int i = wordLen; i < 24; i++){out << ".";}
	out << inWord.count <<":";
	//print and pop line numbers from queue
	while(!inWord.lineNumbers.empty()){
		out << inWord.lineNumbers.front() << " ";
		inWord.lineNumbers.pop();
	}

}

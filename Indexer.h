#ifndef INDEXER_H
#define INDEXER_H

#include "Word.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Indexer{

public:

	Indexer();
	Indexer(string filter, string data);
	void DoIndex();
	BinarySearchTree<Word> FileFilterReader(string filterfile);
	BinarySearchTree<Word> FileWordReader(string datafile);
	bool FileExists(string filename);
	void OutputResults();

private:

	BinarySearchTree<Word> filteredBST;
	BinarySearchTree<Word> indexedBST;
	
	string datafile;
	string filterfile;





};


#endif
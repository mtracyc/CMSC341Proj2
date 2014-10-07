#include "Indexer.h"

Indexer::Indexer()
{

}

Indexer::Indexer(string filter, string data) 
{
	filteredBST;
	indexedBST;
	filterfile = filter;
	datafile = data;
	
}

void Indexer::DoIndex()
{
	FileExists(filterfile);
	FileExists(datafile);
	FileFilterReader(filterfile);
	FileWordReader(datafile);
}

bool Indexer::FileExists(string filename)
{
	ifstream infile;
	//open the filename specified
	infile.open(filename.c_str(), ios_base::in);

	//if file fails to open
	if(infile.fail()){
		cout << "The file "<<filename<<" was not successfully opened."<< endl;
		exit(1); // ends ENTIRE program!!!
	}

	infile.close();
	return true;
}

BinarySearchTree<Word> Indexer::FileFilterReader(string filename)
{
	ifstream infile;
	string word;
	int linenumber = 0;
	//open the filename specified
	infile.open(filename.c_str(), ios_base::in);
	while(infile.peek() != EOF)
	{
		infile >> word;
		Word temp = Word(word, linenumber);
		if(!filteredBST.contains(temp))
		{
			filteredBST.insert(temp);
		}
		else 
		{
			temp.CountWord(linenumber);
		}
		linenumber++;
	}


	infile.close();
	return filteredBST;
}

BinarySearchTree<Word> Indexer::FileWordReader(string filename)
{
	ifstream infile;
	//open the filename specified
	infile.open(filename.c_str(), ios_base::in);



	infile.close();
	return indexedBST;
}

void Indexer::OutputResults()
{

}
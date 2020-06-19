#include <iostream>
using namespace std;
#include  <locale>
#include  <cstdlib>
#include "bst.h"
#include <fstream>

BST<std::string> makeTree(char* filename)
{
        ifstream file;
	file.open(filename);
	BST<string> TREE;
	string word;
	string line;
	while (file)
	{
		file >> word;
		int i = 0;
		while (i < word.size())
		{
			int k = 0;
			while ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') && (i < word.size()))
			{
				if (word[i] >= 'A' && word[i] <= 'Z')
					word[i] += 32;
				line += word[i];
				i++;
				k++;
			}
			if (k != 0)
			{
				TREE.add(line);
				line = "";
			}
			else
				i++;
		}
	}
	return TREE;
}

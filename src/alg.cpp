#include <iostream>
using namespace std;
#include  <locale>
#include  <cstdlib>
#include "bst.h"

BST<std::string> makeTree(char* filename)
{
        ifstream file;
	file.open(filename);
	BST<string> TREE;
	string word;
	while (file)
	{
		file >> word;
		int k = 0;
		for (int i = 0; i < word.size(); i++)
		{
			if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
			{
				if (word[i] >= 'A' && word[i] <= 'Z')
					word[i] += 32;
				
				k++;
			}
		}
		if (k == word.size())
			TREE.add(word);
	}
	return TREE;
}

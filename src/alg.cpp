#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>

BST<std::string> makeTree(char* filename)
{
  std::string w;
	std::ifstream file(filename);
	BST<std::string>* tree = new BST<std::string>;
	char str = ' ';
	while (!file.eof()) {
		while (str < 'A' && (!file.eof()))
		{
			file.get(str);
		}

		while (str >= 'A' && (!file.eof()))
		{
			if (str >= 'A' && str <= 'Z')
			{
				w += str;
			}
			if (str >= 'a' && str <= 'z')
			{
				w += str;
			}

			file.get(str);
		}
		for (int i = 0; i < w.length(); i++)
		{
			if (w[i] >= 'A' && w[i] <= 'Z')
				w[i] += 32;
		}

		(*tree).add(w);
		w = "";
	}

	return *tree;
}

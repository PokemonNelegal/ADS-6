#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>

BST<std::string> makeTree(char* filename)
{

}
BST<std::string> tree;
	ifstream file(filename);
	string str,node;
	while (!file.eof()) {
		node="";
		file >> str;
		bool flag = 0;
		for (int i = 0; i < str.length(); i++) {
			if (isalpha(str[i]))
			{
				flag = 1;
				str[i]=tolower(str[i]);
				node += str[i];
			}
			else if (flag == 1)
			{
				tree.add(node);
				node = "";
				flag = 0;
			}
		}
		if (!node.empty()) {
			tree.add(node);
		}
	}
	return tree;
}

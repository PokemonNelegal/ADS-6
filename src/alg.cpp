#include "bst.h"
#include <iostream>
using namespace std;
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <cctype> 

BST<std::string> makeTree(char* filename)
{
	BST<std::string>BS;
	ifstream f;
	f.open(filename);
	string s="",tmp="";
	int i = 0, flag = 0;
	while (f >> s)
	{
			for (int j = 0; j < s.size(); j++)
			{
				flag = 0;
				if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
					tmp += (char)tolower(s[j]);
				else 
				{
						if (tmp != "")
						{
							BS.add(tmp);
							tmp = "";
							flag = 1;
							continue;
						}
				}
			}
			if (flag == 0 && tmp!="")
			{
				BS.add(tmp);
				tmp = "";
			}
	}
	return BS;
}

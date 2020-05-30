#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include<string.h>
#include<ctype.h>
using namespace std;

BST<string> makeTree(char* filename)
{
    BST<string> tree1;
    ifstream file(filename);
    string str, tmp;
    while (!file.eof())
    {
        tmp.clear();
        file >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (('A' <= str[j] && str[j] <= 'Z') || ('a' <= str[j] && str[j] <= 'z'))
            {
                str[j] = (char)tolower(str[j]);
                tmp += str[j];
            }
            else if (!tmp.empty())
            {
                tree1.add(tmp);
                tmp.clear();
                continue;
            }
        }
    }
    return tree1;
}

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
    while (file >> str)
    {
        tmp.clear(); 
        for (int j = 0; j < str.size(); j++)
        {
            if ((str[j]>= '65' && str[j] <= '90') || (str[j]>='97' && str[j] <= '122'))
            {
                str[j] = (char)tolower(str[j]);
                tmp += str[j];
            }
            else if (tmp!="")
            {
                tree1.add(tmp);
                tmp="";
                continue;
            }
        }
    }
    return tree1;
}

#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <cctype>

BST<std::string> makeTree(char* filename)
{
    char sim, * text, * value;
    int count, num, begin = 0, end = 0;
    std::string str;
    
    BST<std::string> tree;
    
    std::ifstream fin(filename);
    
    if (!fin.is_open()) {
		std::cout << "File not found. Try again." << std::endl;
		return tree;
	}
	
	while (fin.get(sim)) {
			count++;
	}
	fin.close();
	
    if (count == 0) {
		std::cout << "You did not enter anything." << std::endl;
		return tree;
	}
	
	count++;
	text = new char[count];
	
	fin.open(filename);
	for (int i = 0; i < count-1; i++) {
		fin.get(sim);
		text[i] = sim;
	}
	fin.close();
	
	text[count-1] = '\0';
	
	while (begin < count) {
		if (isalpha((unsigned char)text[begin])) {
			end = begin;
			if (end + 1 < count) {
				while (isalpha((unsigned char)text[end+1])) {
					end++;
					if (end + 1 > count) break;
				}
			}
			
			if (end + 1 < count) {
				if (!isspace((unsigned char)text[end+1]) && !ispunct((unsigned char)text[end+1]) 
				&& (unsigned char)text[end+1] != '\0') {
					begin = end + 1;
					while (!isspace((unsigned char)text[begin]) && !ispunct((unsigned char)text[begin]) 
					&& (unsigned char)text[begin] !='\0') {
						begin++;
						if (begin > count) break;
					}
					continue;
				}
			}
			
			num = end - begin + 2;
			value = new char[num];
			for (int i = 0; i < num - 1; i++) {
			    if (isupper((unsigned char)text[begin])) {
			        text[begin] = tolower(text[begin]);
			    }
			    value[i] = text[begin];
			    begin++;
			}
			value[num - 1] = '\0';
			std::string str = value;
			
			tree.add(str);
			delete[] value;
		}
		else begin++;
	}

    delete[] text;
    
    return tree;
}

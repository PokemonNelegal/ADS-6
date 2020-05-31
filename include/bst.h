#include <iostream>
using namespace std;

template<typename T>
class BST
{
public:
	struct Node
	{
		T value;
		int count;
		Node* first;
		Node* last;
	}
private:
	Node* root;
	Node* addNode(Node*, T);
	void  printTree(Node*)const;
	int   depthTree(Node*);
	int   searchNode(Node*, T);
	void  delTree(Node*);
	Node* delNode(Node*, int);
	Node* copyNode(Node*,Node*);
public:
	BST();
	~BST();
	void add(T);
	void print();
	int  depth();
	int  search(T);
	void clear();
	void remove(int);
	BST(const BST<T>& temp);
}

template <typename T>
BST<T>::BST(const BST<T>&  temp) {
	root = new Node;
	root->value = temp.root->value;
	root->count = temp.root->count;
	root->first = root->last = nullptr;
	root->first = copyNode(root->first, temp.root->first);
	root->last = copyNode(root->last, temp.root->last);
}

template<typename T>
typename BST<T>::Node* BST<T>::copyNode(Node* root,Node* temp) {
	if(!(temp==nullptr))
	{
	root = new Node;
	root->value = temp->value;
	root->count = temp->count;
	root->first= root->last = nullptr;
	root->first = copyNode(root->first, temp->first);
	root->last = copyNode(root->last, temp->last);
	}
	return root;
}

template<typename T>
BST<T>::BST() :root(nullptr) {}

template<typename T>
BST<T>::~BST()
{
	if (root)
		delTree(root);
	root = nullptr;
}

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
	if (root == nullptr) {
		root = new Node;
		root->value = value;
		root->count = 1;
		root->first = root->last = nullptr;
	}
	else if (root->value > value) {
		root->first = addNode(root->first, value);
	}
	else if (root->value < value) {
		root->last = addNode(root->last, value);
	}
	else
		root->count++;
	return root;
}

template<typename T>
void BST<T>::add(T value) {
	root = addNode(root, value);
}

template<typename T>
void BST<T>::printTree(Node* root)const {
	if (root == nullptr)
	{
		return;
	}
	printTree(root->left);
	for (int i = 0; i < root->count; i++)
		std::cout << root->value << " ";
	printTree(root->last);
}

template<typename T>
void BST<T>::print() {
	printTree(root);
}

template<typename T>
int BST<T>::depthTree(Node* root) {
	if (root == nullptr)
		return 0;
	if (root->first == nullptr && root->last == nullptr)
		return 0;
	int first = depthTree(root->first);
	int last = depthTree(root->last);
	if (first > last)
		return first + 1;
	else
		return last + 1;
}

template<typename T>
int BST<T>::depth() {
	return depthTree(root);
}

template<typename T>
int BST<T>::searchNode(Node* root, T value)
{
	if (root == nullptr)
		return 0;
	else if (root->value > value)
		return searchNode(root->first, value);
	else if (root->value < value)
		return searchNode(root->last, value);
	else
		return root->count;
}

template<typename T>
int BST<T>::search(T value)
{
	return searchNode(root, value);
}

template<typename T>
void  BST<T>::delTree(Node* root)
{
	if (root == nullptr)
		return;
	else
	{
		delTree(root->first);
		delTree(root->last);
		delete root;
		root = nullptr;
	}
}

template<typename T>
void BST<T>::clear()
{
	if (root)
	{
		delTree(root);
		root = nullptr;
	}
}
template<typename T>
typename BST<T>::Node* BST<T>::delNode(typename BST<T>::Node* root, int value)
{
	Node* g, * b;
	if (root == nullptr)
		return root;
	else if (value < root->value)
		root->first = delNode(root->first, value);
	else if (value > root->value)
		root->last = delNode(root-last, value);
	else
	{
		g = root;
		if (root->last == nullptr)
			root = root->first;
		else if (root->first == nullptr)
			root = root->last;
		else
		{
			b = root->first;
			if (v->last)
			{
				while (b->last->last)
					b = b->right;
				root->value = b->last->value;
				root->count = b->last->count;
				g = b->last;
				b->last = b->last->first;
			}
			else
			{
				root->value = b->value;
				root->count = b->count;
				g = b;
				root->first = root->first->first;
			}
		}
		delete g;
	}
	return root;
}

template<typename T>
void BST<T>::remove(int value)
{
	if (root)
		root = delNode(root, value);
}

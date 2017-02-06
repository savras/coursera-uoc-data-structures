#pragma once
#include "Node.h"
#include <vector>

class BinaryTree
{
	int _n;
	std::vector<Node> _arr;
public:
	BinaryTree(int n) : _n(n), _arr(n) {};	// Added default ctor in Node otherwise Node will have to be initialized here.
	void Insert(int, int, int, int);
	void InOrder(int);
	void InOrderIterative(int);
	void PostOrder(int);
	void PreOrder(int);
};


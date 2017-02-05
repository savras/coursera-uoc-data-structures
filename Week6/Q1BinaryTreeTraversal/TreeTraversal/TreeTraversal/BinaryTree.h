#pragma once
#include "Node.h"
#include <vector>

class BinaryTree
{
	int _n;
	std::vector<Node> _arr;
public:
	BinaryTree(int n) : _n(n), _arr(n) {};
	void Insert(int, int, int, int);
	void InOrder();
	void PostOrder();
	void PreOrder();
};


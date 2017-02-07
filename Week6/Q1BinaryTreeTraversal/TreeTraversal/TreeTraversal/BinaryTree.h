#pragma once
#include "Node.h"
#include <vector>

class BinaryTree
{
	int _n;
	int GoLeft(const int&, std::vector<int>&);
	int GoRight(const int&, std::vector<int>&);
	int PrintAndGetCurrentIndex(std::vector<int>&);
	std::vector<Node> _arr;
public:
	BinaryTree(int n) : _n(n), _arr(n) {};	// Added default ctor in Node otherwise Node will have to be initialized here.
	void Insert(int, int, int, int);
	void InOrder(int);	
	void PostOrder(int);
	void PreOrder(int);
	void InOrderIterative(int);
	void PreOrderIterative(int);
	void PostOrderIterative(int);
};


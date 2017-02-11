#pragma once
#include "Node.h"
#include "SplayMod.h"
#include <vector>

class SplayTree
{
	std::vector<Node> _arr;
	long long _sum;
	void Splay(const int&);
	int GetSize();
	int GoLeft(const int&) const;
	int GoRight(const int&) const;	
	int Hash(const long long&) const;
	SplayMod GetSplayModification(const int&) const;
public:	
	SplayTree() : _sum(0) {};
	void Add(const long long&) const;
	void Find(const long long&) const;
	void Del(const long long&) const;
	void Sum(const long long&, const long long&) const;
};


#pragma once
#include <vector>;

class DisjointSet {
	std::vector<int> _parent;
	std::vector<int> _rank;
	std::vector<int> _rows;	// or Tables with rows
	int Find(const int);
public:
	DisjointSet(const std::vector<int>&);
	void Merge(const int, const int);
};
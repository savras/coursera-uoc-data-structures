#pragma once
#include <vector>;

class DisjointSet {
	std::vector<int> _parent;
	std::vector<int> _rank;
	std::vector<int> _rows;	// or Tables with rows
	std::vector<int> _result;
	int _max;
	int Find(const int);
public:
	DisjointSet(const std::vector<int>&, const int);
	void Merge(const int, const int);
	void PrintResult();
};
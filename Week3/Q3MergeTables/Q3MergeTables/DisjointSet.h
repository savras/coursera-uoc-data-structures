#pragma once
#include <vector>;

class DisjointSet {
	int _max;
	std::vector<int> _parent;
	std::vector<int> _rank;
	std::vector<int> _rows;	// or Tables with rows
	std::vector<int> _result;
	int Find(const int) const;
	int GetParent(const int);
	void PathCompression(const std::vector<int>&, const int);

public:
	DisjointSet(const std::vector<int>&, const int);
	void Merge(const int, const int);
	void PrintResult() const;
};
#include "DisjointSet.h"
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::pair;
using std::max;
using std::cout;

DisjointSet::DisjointSet(const vector<int>& rows, int max) {
	int size = rows.size();
	for (size_t i = 0; i < size; i++) {
		_parent.push_back(i);
	}

	for (size_t i = 0; i < size; i++) {
		_rank.push_back(0);
	}

	_rows = rows;
	_max = max;
}

int DisjointSet::Find(const int i) {
	if (_parent[i] == i)
	{
		return i;
	}

	return Find(_parent[i]);
}

void DisjointSet::Merge(const int destination, const int source) {
	int sourceRoot = Find(source);
	int destinationRoot = Find(destination);

	if (sourceRoot != destinationRoot) {
		if (_rank[sourceRoot] < _rank[destinationRoot]) {
			_parent[sourceRoot] = destinationRoot;
			_rows[destinationRoot] += _rows[sourceRoot];
			_rows[sourceRoot] = 0;
		}
		else {
			_parent[destinationRoot] = sourceRoot;
			_rows[sourceRoot] += _rows[destinationRoot];
			_rows[destinationRoot] = 0;
			_rank[destinationRoot]++;
		}
	}

	_result.push_back(max(_rows[sourceRoot], max(_max, _rows[destinationRoot])));
}

void DisjointSet::PrintResult() {
	for (const auto& result : _result) {
		std::cout << result << std::endl;
	}
}
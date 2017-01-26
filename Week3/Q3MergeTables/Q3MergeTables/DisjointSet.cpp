#include "DisjointSet.h"
#include <vector>

using std::vector;
using std::pair;

DisjointSet::DisjointSet(const vector<int>& rows) {
	int size = rows.size();
	for (size_t i = 0; i < size; i++) {
		_parent.push_back(i);
	}

	for (size_t i = 0; i < size; i++) {
		_rank.push_back(0);
	}

	_rows = rows;
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

	if (_rank[source] < _rank[destinationRoot]) {
		_parent[source] = destinationRoot;
		_rows[destinationRoot] += _rows[source];
		_rows[source] = 0;
	}
	else {
		_parent[destinationRoot] = source;
		_rows[source] = _rows[destinationRoot];
		_rows[destinationRoot] = 0;
		_rank[destinationRoot]++;

	}
}
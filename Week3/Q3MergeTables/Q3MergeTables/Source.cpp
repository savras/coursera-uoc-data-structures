#include "DisjointSet.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cin;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> rows(n);
	for (size_t i = 0; i < n; i++) {
		cin >> rows[i];
	}

	DisjointSet ds(rows);
	int source, destination;
	int offset = 1;
	for (size_t i = 0; i < m; i++) {
		cin >> destination >> source;
		ds.Merge(destination + offset, source + offset);
	}
	return 0;
}
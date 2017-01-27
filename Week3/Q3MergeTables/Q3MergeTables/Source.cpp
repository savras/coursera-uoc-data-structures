#include "DisjointSet.h"
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int main() {

	int n, m;
	cin >> n >> m;

	int maximum = 0;
	vector<int> rows(n);
	for (size_t i = 0; i < n; i++) {
		cin >> rows[i];
		maximum = max(maximum, rows[i]);
	}

	DisjointSet ds(rows, maximum);
	int source, destination;
	int offset = 1;
	for (size_t i = 0; i < m; i++) {
		cin >> destination >> source;
		ds.Merge(destination - offset, source - offset);
	}

	ds.PrintResult();

	system("pause");
	return 0;
}
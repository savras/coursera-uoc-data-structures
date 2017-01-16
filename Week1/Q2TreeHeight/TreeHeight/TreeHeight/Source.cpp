#include <iostream>
#include <vector>
#include "Tree.h"

using std::cin;
using std::cout;
using std::vector;

int main() {
	int n, val;
	cin >> n;

	Tree tree;
	vector<int> arr;
	for (size_t i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}

	tree.Build(arr);
	cout << tree.HeightRecursive();

	return 0;
}
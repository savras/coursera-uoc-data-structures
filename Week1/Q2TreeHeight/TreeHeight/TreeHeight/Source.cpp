#include <iostream>
#include <vector>
#include "Tree.h"

using std::cin;
using std::cout;
using std::vector;

int main() {
	int n, val;
	cin >> n;

	Tree tree(n);
	vector<int> arr(n);
	for (size_t i = 0; i < n; i++) {
		cin >> arr[i];
	}

	tree.Build(arr);
	//cout << tree.HeightRecursive();
	//cout << tree.HeightDynamicIterative(arr);
	cout << tree.HeightDynamicRecursive(arr);

	return 0;
}
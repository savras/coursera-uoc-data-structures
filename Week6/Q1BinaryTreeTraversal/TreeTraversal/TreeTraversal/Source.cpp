#include "BinaryTree.h"
#include <iostream>

using std::cin;
using std::cout;

int main() {
	int n;
	cin >> n;

	BinaryTree t(n);
	int key, left, right;
	for (size_t i = 0; i < n; i++) {
		cin >> key >> left >> right;
		t.Insert(key, i, left, right);
	}

	t.PreOrder();
	t.InOrder();
	t.PostOrder();

	system("pause");

	return 0;
}
#include "BinaryTree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int n;
	cin >> n;

	BinaryTree t(n);
	int key, left, right;
	for (size_t i = 0; i < n; i++) {
		cin >> key >> left >> right;
		t.Insert(key, i, left, right);
	}

	t.InOrderIterative(0);
	cout << endl;
	t.InOrder(0);
	cout << endl;

	t.PreOrderIterative(0);
	cout << endl;
	t.PreOrder(0);
	cout << endl;

	//t.PostOrderIterative(0);
	cout << endl;	
	t.PostOrder(0);
	cout << endl;

	system("pause");

	return 0;
}
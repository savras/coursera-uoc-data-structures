#include <iostream>
#include <vector>
#include "Heap.h"

using std::cin;
using std::vector;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (size_t i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Heap<int> heap(arr);
	heap.BuildHeap();

	system("pause");

	return 0;
}
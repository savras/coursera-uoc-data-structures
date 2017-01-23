#include "Heap.h";
#include <iostream>;
#include <vector>;

using std::vector;
using std::cin;
using std::cout;
using std::pair;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> arr(n);
	for (size_t i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	Heap heap(arr);
	heap.BuildHeap();

	system("pause");

	return 0;
}
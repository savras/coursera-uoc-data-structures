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

	vector<pair<int, long long>> threads(n);	// <thread,time>
	for (size_t i = 0; i < n; i++) {
		threads[i].first = i;
	}

	vector<long long> input(m);
	for (size_t i = 0; i < m; i++) {
		cin >> input[i];
	}

	Heap heap(threads, input);
	heap.BuildHeap();
	heap.Process();

	system("pause");

	return 0;
}
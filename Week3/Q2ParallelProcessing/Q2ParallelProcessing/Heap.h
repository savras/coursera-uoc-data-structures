#pragma once
#include <vector>

// Min Heap.
class Heap {
	std::vector<std::pair<int, long long>> _arr;
	std::vector<long long> _input;
	int _size;
	int _maxHeapSize;
	void Swap(const int, const int);
	int ParentIndex(int) const;
	int LeftChildIndex(const int) const;
	int RightChildIndex(const int) const;
	void SiftDown(const int);
public:
	Heap(const std::vector<std::pair<int, long long>>&, const std::vector<long long>&);
	void Process();
	void BuildHeap();
};
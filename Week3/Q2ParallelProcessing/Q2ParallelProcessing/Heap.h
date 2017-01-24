#pragma once
#include <vector>

// Min Heap.
class Heap {
	std::vector<std::pair<int,int>> _arr;
	std::vector<int> _input;
	int _size;
	int _maxHeapSize;
	void Swap(const int, const int);
	int ParentIndex(int) const;
	int LeftChildIndex(const int) const;
	int RightChildIndex(const int) const;
	void SiftDown(const int);
public:
	Heap(const std::vector<std::pair<int,int>>&, const std::vector<int>&);
	void Process();
	void BuildHeap();
};
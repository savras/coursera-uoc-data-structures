#pragma once
#include <vector>

class Heap {
	std::vector<std::pair<int,int>> _arr;
	int _size;
	int _maxHeapSize;
	void Swap(const int, const int);
	int ParentIndex(int) const;
	int LeftChildIndex(const int) const;
	int RightChildIndex(const int) const;
	void SieveUp(const int);
public:
	Heap(std::vector<std::pair<int,int>> arr);
	int Extract();
	void BuildHeap();
};
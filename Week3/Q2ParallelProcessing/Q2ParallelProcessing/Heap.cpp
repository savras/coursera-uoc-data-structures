#include <iostream>;
#include <vector>;
#include "Heap.h";

using std::vector;
using std::cout;
using std::endl;
using std::pair;

Heap::Heap(vector<pair<int,int>> arr) {
	_arr = arr;
	_maxHeapSize = _arr.size();
	_size = _maxHeapSize;
}

int Heap::LeftChildIndex(const int i) const {
	int index = ((2 * i) + 1);

	if (index >= _size) {
		return -1;
	}

	return index;
}

int Heap::RightChildIndex(const int i) const {
	int index = ((2 * i) + 2);

	if (index >= _size) {
		return -1;
	}

	return index;
}

int Heap::ParentIndex(const int childIndex) const {
	if (childIndex <= 0) { return -1; }

	int parent;
	if (childIndex % 2 == 0) {
		parent = (childIndex - 2) / 2;
	}
	else {
		parent = (childIndex - 1) / 2;
	}

	return parent;
}

void Heap::Swap(int ia, int ib) {
	pair<int,int> temp = _arr[ia];
	_arr[ia] = _arr[ib];
	_arr[ib] = temp;
}

void Heap::SieveUp(int index) {
	int parentIndex = ParentIndex(index);
	if (parentIndex == -1) {
		return;
	}

	int swapIndex = parentIndex;
	int leftIndex = LeftChildIndex(parentIndex);
	int rightIndex = RightChildIndex(parentIndex);
	if (leftIndex != -1 && _arr[swapIndex].first > _arr[leftIndex].first) {
		swapIndex = leftIndex;
	}
	if (rightIndex != -1 && _arr[swapIndex].first > _arr[rightIndex].first) {
		swapIndex = rightIndex;
	}
	if (parentIndex != swapIndex) {
		Swap(parentIndex, swapIndex);
		SieveUp(parentIndex);
	}
}

int Heap::Extract() {
	pair<int,int> result = _arr[0];

	Swap(0, _size - 1);
	SieveUp(_size - 1);

	return result.first;
}

void Heap::BuildHeap() {
	for (size_t i = 1; i < _size; i+= 2) {
		SieveUp(i);
	}
}
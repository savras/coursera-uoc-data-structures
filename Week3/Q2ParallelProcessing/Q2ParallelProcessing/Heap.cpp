#include <iostream>;
#include <vector>;
#include "Heap.h";

using std::vector;
using std::cout;
using std::endl;
using std::pair;

Heap::Heap(const vector<pair<int,int>>& arr, const vector<int>& input) {
	_arr = arr;
	_input = input;
	_maxHeapSize = arr.size();
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

void Heap::SiftDown(const int index) {
	if (index < 0 || index >= _size) {
		return;
	}

	int swapIndex = index;

	int leftIndex = LeftChildIndex(index);
	if (leftIndex != -1 &&  _arr[swapIndex].second >= _arr[leftIndex].second) {
		if (_arr[swapIndex].second == _arr[leftIndex].second)
		{
			swapIndex = _arr[swapIndex].first > _arr[leftIndex].first ? leftIndex : swapIndex;
		}
		else {
			swapIndex = leftIndex;
		}
	}

	int rightIndex = RightChildIndex(index);
	if (rightIndex != -1 && _arr[swapIndex].second >= _arr[rightIndex].second) {
		if (_arr[swapIndex].second == _arr[rightIndex].second)
		{
			swapIndex = _arr[swapIndex].first > _arr[rightIndex].first ? rightIndex : swapIndex;
		}
		else {
			swapIndex = rightIndex;
		}
	}

	if (index != swapIndex) {
		Swap(index, swapIndex);
		SiftDown(swapIndex);
	}
}

void Heap::Process() {
	for (size_t i = 0; i < _input.size(); i++) {
		cout << _arr[0].first << " " << _arr[0].second << endl;
		_arr[0].second += _input[i];

		SiftDown(0);
	}
}

void Heap::BuildHeap() {
	for (int i = _size/2; i >= 0; i--) {	// Each node in the levels before the last/leaf
		SiftDown(i);
	}
}
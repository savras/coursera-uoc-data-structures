#pragma once
#include <vector>

template <typename T>
class Heap {
	std::vector<T> _arr;
	int _size;
	int _maxHeapSize;
	bool _swapOccured;
	void Swap(const int, const int);
	int GetParentIndex(int) const;
	int GetLeftChildIndex(const int) const;
	int GetRightChildIndex(const int) const;
public:
	Heap(std::vector<T> arr);
	void SieveDown(const int);
	void BuildHeap();
};

template <typename T>
Heap<T>::Heap(std::vector<T> arr) {
	_arr = arr;
	_maxHeapSize = _arr.size();
	_size = _maxHeapSize;
	_swapOccured = false;
}

template <typename T>
int Heap<T>::GetLeftChildIndex(const int i) const {
	int index = ((2 * i) + 1);
	
	if (index >= _size) {
		return -1;
	}

	return index;
}

template <typename T>
int Heap<T>::GetRightChildIndex(const int i) const {
	int index = ((2 * i) + 2);
	
	if (index >= _size) {
		return -1;
	}

	return index;
}

template <typename T>
int Heap<T>::GetParentIndex(const int childIndex) const {
	if (childIndex == 0) { return -1; }

	int parent;
	if (childIndex % 2 == 0) {
		parent = (childIndex - 2) / 2;
	}
	else {
		parent = (childIndex - 1) / 2;
	}

	return parent;
}

template <typename T>
void Heap<T>::Swap(int parentIndex, int childIndex) {
	if (!_swapOccured) {
		_swapOccured = true;
	}

	std::cout << parentIndex << " " << childIndex << std::endl;
	int temp = _arr[parentIndex];
	_arr[parentIndex] = _arr[childIndex];
	_arr[childIndex] = temp;
}

template <typename T>
void Heap<T>::SieveDown(const int parentIndex) {
	if (parentIndex < 0 || parentIndex >= _maxHeapSize) {
		std::cout << "SieveDown:: Invalid parent index: " + parentIndex << std::endl;
	}

	int leftIndex = GetLeftChildIndex(parentIndex);
	int rightIndex = GetRightChildIndex(parentIndex);

	if (leftIndex == -1 && rightIndex == -1) {
		return;
	}

	int sieveDirectionIndex = 0;
	if (rightIndex == -1 && _arr[parentIndex] > _arr[leftIndex]) {
		sieveDirectionIndex = leftIndex;
	}
	else if (leftIndex == -1 && _arr[parentIndex] > _arr[rightIndex]) {
		sieveDirectionIndex = rightIndex;
	}
	else {
		T leftVal = _arr[leftIndex];
		T rightVal = _arr[rightIndex];
		T parentVal = _arr[parentIndex];
		if (parentVal < leftVal && parentVal < rightVal) {
			return;	// Heap preserved
		}

		if (parentVal > leftVal || parentVal > rightVal) {
			sieveDirectionIndex = leftVal > rightVal ? rightIndex : leftIndex;
		}
	}

	Swap(parentIndex, sieveDirectionIndex);
	SieveDown(sieveDirectionIndex);
}

template <typename T>
void Heap<T>::BuildHeap() {
	int indexCounter = _size - 1;
	for (size_t i = indexCounter; i > 0; i -= 2) {
		int parentIndex = GetParentIndex(i);
		SieveDown(parentIndex);
	}

	if (!_swapOccured) {
		std::cout << 0 << std::endl;
	}
}
#pragma once
#include <vector>

template <typename T>
class Heap {
	std::vector<T> _arr;
public:
	Heap(std::vector<T> arr);
	T GetLeftChild(const int i) const;
	T GetRightChild(const int i) const;
	void BuildHeap();
	void Swap(int i, int childI);
};

template <typename T>
Heap<T>::Heap(std::vector<T> arr) {
	_arr = arr;
}

template <typename T>
T Heap<T>::GetLeftChild(const int i) const {

}

template <typename T>
T Heap<T>::GetRightChild(const int i) const {

}

template <typename T>
void Heap<T>::Swap(int i, int childI) {

}


template <typename T>
void Heap<T>::BuildHeap() {

}
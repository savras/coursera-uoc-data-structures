#include "Stack.h"
#include <stdexcept>

template <typename T>
void Stack<T>::push(const T& elem) {
	_elements.push_back(elem);
}

template <typename T>
T Stack<T>::pop() const {
	if (_elements.empty()) {
		throw out_of_range("Stack::pop(): stack is empty");
	}

	return _elements.pop_back();
};

template <typename T>
T Stack<T>::top() const {
	if (_elements.empty()) {
		throw out_of_range("Stack::top(): stack is empty");
	}

	return _elements.back();
};
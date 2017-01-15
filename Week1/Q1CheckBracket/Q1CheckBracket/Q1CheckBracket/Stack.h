#pragma once
#include <vector>
#include <stdexcept>

using std::out_of_range;

template <typename T>	// same as <class T>
class Stack
{
	std::vector<T> _elements;
public:
	void push(const T&);	// http://stackoverflow.com/questions/2640446/why-do-some-people-prefer-t-const-over-const-t
	T pop();
	T top() const;	// Cannot modify _elements unless marked mutable.
	int size() const;
};

// Can't split this: http://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
template <typename T>
void Stack<T>::push(const T& elem) {
	_elements.push_back(elem);
}

template <typename T>
T Stack<T>::pop() {
	if (_elements.empty()) {
		throw out_of_range("Stack::pop(): stack is empty");
	}

	_elements.pop_back();
};

template <typename T>
T Stack<T>::top() const {
	if (_elements.empty()) {
		throw out_of_range("Stack::top(): stack is empty");
	}

	return _elements.back();
};

template <typename T>
int Stack<T>::size() const {
	return _elements.size();
}
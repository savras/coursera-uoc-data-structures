#pragma once
#include <vector>

using std::vector;

template <typename T>	// same as <class T>
class Stack
{
public:
	void push(const T&);	// http://stackoverflow.com/questions/2640446/why-do-some-people-prefer-t-const-over-const-t
	T pop() const;
	T top() const;	// Cannot modify _elements unless marked mutable.
private:
	vector<T> _elements;
};


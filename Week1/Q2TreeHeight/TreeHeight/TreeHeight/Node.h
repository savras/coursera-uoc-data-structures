#pragma once
#include <vector>

template <typename T>
class Node
{
public:
	T value;
	std::vector<Node<T>*> children;
};


#pragma once
#include <vector>
#include <memory>

using std::unique_ptr;

template <typename T>
class Node
{
public:
	T value;
	std::vector<Node<T>*> children;
};


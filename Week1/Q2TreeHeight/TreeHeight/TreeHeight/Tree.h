// Pointer notes: http://stackoverflow.com/questions/9765052/how-to-pass-a-constant-pointer-to-a-method-in-a-class
/*
Node *ptr;  // Non-constant pointer to non-constant data
Node *const ptr;  // Constant pointer to non-constant data
const Node *ptr;  // Non-constant pointer to constant data
Node const *ptr;  // Same as above
const Node *const ptr;  // Constant pointer to constant data
Node const *const ptr;  // Same as above
*/
#pragma once
#include "Node.h"
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <map>

using std::unordered_set;
using std::vector;
using std::max;
using std::map;
using std::for_each;

class Tree
{
	int size;
	Node<int> *root;
	Node<int> *nodes;	// http://stackoverflow.com/questions/2275076/is-stdvector-copying-the-objects-with-a-push-back
	int GetHeightRecursive(const Node<int> *node, int height) const;
	int GetMaxHeight(const vector<int>&) const;
	void BuildHeightRecursive(const vector<int>&, const int, vector<int>&) const;
public:
	Tree(const int n);
	~Tree();
	void Build(const vector<int>&);
	int HeightIterative() const;
	int HeightRecursive() const;
	int HeightDynamicIterative(const vector<int>&) const;
	int HeightDynamicRecursive(const vector<int>&) const;
};

Tree::Tree(const int n) {
	size = n;
	nodes = new Node<int>[n]();
}

Tree::~Tree() {
	delete[] nodes;
	nodes = nullptr;

	/*for (int i = 0; i < size; i++) {
		vector<Node<int>*> children = nodes[i].children;

		for (vector<Node<int>*>::const_iterator it = children.begin(); it != children.end(); it++)
		{
			delete *it;
		}
		children.clear();
	}*/
}

void Tree::Build(const vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		Node<int> node;
		node.value = i;
		nodes[i] = node;
	}
	
	for (size_t i = 0; i < arr.size(); i++) {
		int parentIndex = arr[i];

		if (parentIndex == -1)
		{
			root = &nodes[i];
		}
		else {
			nodes[parentIndex].children.push_back(&nodes[i]);
		}
	}
}

int Tree::HeightRecursive() const {
	return GetHeightRecursive(root, 1);
}

int Tree::GetHeightRecursive(const Node<int> *node, int height) const {
	if (node->children.empty()) {
		return height;
	}

	int maxHeight = INT_MIN;
	for (size_t i = 0; i < node->children.size(); i++) {
		Node<int> *ptr = node->children[i];
		maxHeight = max(maxHeight, GetHeightRecursive(ptr, height) + 1);
	}
	return maxHeight;
}

int Tree::HeightIterative() const {
	return 0;
}

int Tree::HeightDynamicRecursive(const vector<int> &arr) const {
	vector<int> heights(arr.size());

	for (int i = 0; i < arr.size(); i++) {
		BuildHeightRecursive(arr, i, heights);
	}

	return GetMaxHeight(heights);
}

void Tree::BuildHeightRecursive(const vector<int> &arr, const int i, vector<int>& heights) const {
	if (heights[i] != 0) {
		return;
	}
	
	if (arr[i] == -1) {
		heights[i] = 1;
		return;
	}

	if (heights[i] == 0) {
		BuildHeightRecursive(arr, arr[i], heights);
	}

	heights[i] = heights[arr[i]] + 1;
}

int Tree::GetMaxHeight(const vector<int> &heights) const {
	int maxHeight = INT_MIN;
	for (int i = 0; i < heights.size(); i++)
	{
		maxHeight = max(maxHeight, heights[i]);
	}
	return maxHeight;
}

int Tree::HeightDynamicIterative(const vector<int> &arr) const {
	vector<int> steps;
	vector<int> heights(arr.size());

	steps.push_back(0);
	int parentIndex = arr[0];
	while (parentIndex != -1) {
		steps.push_back(parentIndex);
		parentIndex = arr[steps.back()];
	}

	int height = 0;
	while (!steps.empty()) {
		heights[steps.back()] = ++height;
		steps.pop_back();
	}

	for (int i = 1; i < arr.size(); i++) {
		parentIndex = arr[i];
		steps.push_back(i);

		while (heights[steps.back()] == 0) {
			steps.push_back(parentIndex);
			parentIndex = arr[parentIndex];
		}

		int lastKnownHeight = heights[steps.back()];
		steps.pop_back();
		while (!steps.empty()) {
			heights[steps.back()] = ++lastKnownHeight;
			steps.pop_back();
		}
	}

	return GetMaxHeight(heights);
}
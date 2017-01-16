#pragma once
#include "Node.h"
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>

using std::unordered_set;
using std::vector;
using std::max;

class Tree
{
	Node<int> root;
	vector<Node<int>> nodes;	// http://stackoverflow.com/questions/2275076/is-stdvector-copying-the-objects-with-a-push-back
	int GetHeightRecursive(const Node<int> &node, int height) const;
public:
	void Build(const vector<int>&);
	int HeightIterative() const;
	int HeightRecursive() const;
};

void Tree::Build(const vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		Node<int> node;
		node.value = i;
		nodes.push_back(node);
	}
	
	for (size_t i = 0; i < arr.size(); i++) {
		int parentIndex = arr[i];

		if (parentIndex == -1)
		{
			root = nodes[i];
		}
		else {
			nodes[parentIndex].children.push_back(nodes[i]);
		}
	}
}

int Tree::HeightRecursive() const {
	return GetHeightRecursive(root, 1);
}

int Tree::GetHeightRecursive(const Node<int> &node, int height) const {
	if (node.children.empty()) {
		return height;
	}

	int maxHeight = INT_MIN;
	for (size_t i = 0; i < node.children.size(); i++) {
		maxHeight = max(maxHeight, GetHeightRecursive(node.children[i], height) + 1);
	}
	return maxHeight;
}

int Tree::HeightIterative() const {
	return 0;
}
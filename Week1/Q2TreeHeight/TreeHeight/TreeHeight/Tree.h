#pragma once
#include "Node.h"
#include <vector>

using std::vector;

template <typename T>
class Tree
{
	Node<T> root;
public:
	void BuildIterative(const vector<int>&);
	void BuildRecursive(const vector<int>&);
	int HeightIterative() const;
	int HeightRecursive() const;
};

template <typename T>	// How to constrain this to basic types?
void Tree<T>::BuildIterative(const vector<int>& arr) {

	Node parent;
	for (int i = 0; i < arr.size(); i++) {
		// if(i has been processed e.g. in map()) { continue; }	
		
		if (arr[i] == -1) {
			root = node;
		}
		else {
			Node<T> child;
			child.value = i;
			int current = arr[i];
			// Add i to map;

			while (current != -1) {

				// if(current exists in map) { 
				//   get node 4.
				//   node 4.children.push_back(child);
				//	 break;
				// } 
				// else {
				Node node;
				node.value = current;
				node.childdren.push_back(child);

				child = node;
				current = arr[current];
				// Add i to map;
			}

			root.children.push_back(child);
		}		
	}	
}

template <typename T>
void Tree<T>::BuildRecursive(const vector<int> &arr) {

}

template <typename T>
int Tree<T>::HeightRecursive() const {
	
}

template <typename T>
int Tree<T>::HeightIterative() const {
	
}
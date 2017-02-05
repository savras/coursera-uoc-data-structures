#include <iostream>
#include "BinaryTree.h"

using std::cout;

void BinaryTree::Insert(int val,int index, int left, int right) {
	Node node = Node(val, left, right);
	_arr[index] = node;
}

void BinaryTree::InOrder(int index) {
	if (index == -1) {
		return;
	}

	InOrder(_arr[index].GetLeftChild());
	cout << _arr[index].GetKey() << " ";
	InOrder(_arr[index].GetRightChild());	
}

void BinaryTree::PostOrder(int index) {
	if (index == -1) {
		return;
	}

	PostOrder(_arr[index].GetLeftChild());
	PostOrder(_arr[index].GetRightChild());
	cout << _arr[index].GetKey() << " ";
}

void BinaryTree::PreOrder(int index) {
	if (index == -1) {
		return;
	}

	cout << _arr[index].GetKey() << " ";
	PreOrder(_arr[index].GetLeftChild());
	PreOrder(_arr[index].GetRightChild());
}
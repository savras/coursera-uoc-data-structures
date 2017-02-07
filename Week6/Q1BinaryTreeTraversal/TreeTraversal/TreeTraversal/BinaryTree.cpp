#include <iostream>
#include <vector>
#include "BinaryTree.h"

using std::cout;
using std::vector;

void BinaryTree::Insert(int val,int index, int left, int right) {
	Node node = Node(val, left, right);
	_arr[index] = node;
}

void BinaryTree::InOrderIterative(int index) {
	vector<int> stack;
	
	int counter = 0;
	do {
		while (index != -1) {
			stack.push_back(index);
			index =_arr[index].GetLeftChild();
		}

		index = stack.back();
		cout << _arr[index].GetKey() << " ";
		counter++;
		stack.pop_back();

		index = _arr[index].GetRightChild();		
	} while (counter < _n);
}

void BinaryTree::PreOrderIterative(int index) {
	vector<int> stack;

	stack.push_back(index);
	while (!stack.empty()) {
		int i = stack.back();
		stack.pop_back();
		cout << _arr[i].GetKey() << " ";

		if (_arr[i].GetRightChild() != -1) {
			stack.push_back(_arr[i].GetRightChild());
		}

		if (_arr[i].GetLeftChild() != -1) {
			stack.push_back(_arr[i].GetLeftChild());
		}
	}
}
//void BinaryTree::PreOrderIterative(int index) {
//	vector<int> stack;	
//
//	int counter = 0;
//	do {
//		while (index != -1) {
//			cout << _arr[index].GetKey() << " ";
//			counter++;
//			stack.push_back(index);
//			index =_arr[index].GetLeftChild();
//		}
//
//		index = stack.back();
//		stack.pop_back();
//
//		index = _arr[index].GetRightChild();
//	} while (counter < _n);
//}

// Using 2 stacks
void BinaryTree::PostOrderIterative(int index) {
	vector<int> stack1;
	vector<int> stack2;

	stack1.push_back(index);
	while (!stack1.empty()) {
		int i = stack1.back();
		stack1.pop_back();
		stack2.push_back(i);		

		if (_arr[i].GetLeftChild() != -1)
		{
			stack1.push_back(_arr[i].GetLeftChild());
		}

		if (_arr[i].GetRightChild() != -1)
		{
			stack1.push_back(_arr[i].GetRightChild());
		}
	}

	for (int i = stack2.size() - 1; i >= 0; i--) {
		cout << _arr[stack2[i]].GetKey() << " ";
	}
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
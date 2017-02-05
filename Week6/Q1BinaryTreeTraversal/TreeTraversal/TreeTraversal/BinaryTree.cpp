#include "BinaryTree.h"

void BinaryTree::Insert(int val,int index, int left, int right) {
	Node node = Node(val, left, right);
	_arr[index] = node;
}

void BinaryTree::InOrder() {

}

void BinaryTree::PostOrder() {

}

void BinaryTree::PreOrder() {

}
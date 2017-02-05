#pragma once

class Node {
	int _key;
	int _left;
	int _right;
public:
	Node();
	Node(int key, int left, int right) : _key(key), _left(left), _right(right) {};
	int GetLeftChild();
	int GetRightChild();
	int GetKey();
};
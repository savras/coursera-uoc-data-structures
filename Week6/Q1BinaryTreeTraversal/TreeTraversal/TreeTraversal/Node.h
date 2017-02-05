#pragma once

class Node {
	int _key;
	int _left;
	int _right;
public:
	Node::Node();
	Node(int key, int left, int right) : _key(key), _left(left), _right(right) {};
};
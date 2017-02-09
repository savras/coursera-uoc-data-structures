#include "SplayTree.h"
#include "SplayMod.h"
#include "Position.h"

int SplayTree::GetSize() {
	return _arr.size();
}

int SplayTree::Hash(const long long& i) const {
	const long long x = 1000000001;
}

void SplayTree::Add(const long long&) const {
}

void SplayTree::Find(const long long&) const {
}

void SplayTree::Del(const long long&) const {
}

void SplayTree::Sum(const long long&, const long long&) const {
}

void SplayTree::Splay(const int& current) {
	int index = 0; // Find(current);
	SplayMod mod = GetSplayModification(index);
	switch (mod) {
	case SplayMod.ZigZag: {
			break;
		}
	case SplayMod.ZigZig:{
			break;
		}
	case SplayMod.Zig:{
			break;
		}
	}
}

SplayMod SplayTree::GetSplayModification(const int& index) const {
	// int parentIndex = GetParent(index);

	// if(parentIndex <= 0)
	//	  return SplayMod.Zig;

	// enum parentPosition = GetParentPosition(index);
	// enum grandParentPosition = GrandParentPosition(index);
	
	// if((parentPosition.Left && grandParentPosition.Right) || 
	//	  (parentPosition.Right && grandParentPosition.Left))
	//	  return SplayMod.ZigZag;
	// return SplayMod.ZigZig;
}

int SplayTree::GoLeft(const int& current) const {
	return _arr[current]._leftChild;
}

int SplayTree::GoRight(const int& current) const {
	return _arr[current]._rightChild;
}


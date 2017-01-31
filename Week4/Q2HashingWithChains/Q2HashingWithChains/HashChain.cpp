#include "HashChain.h"
#include <cmath>
#include <iostream>
#include <list>

using std::string;
using std::list;
using std::cout;
using std::endl;

void HashChain::Add(const string& str) {
	int index = Hash(str);

	list<string> l = _arr[index];
	l.push_back(str);	
}

void HashChain::Del(const string& str) {
	int index = Hash(str);
	list<string> l = _arr[index];
	l.remove(str);
}

void HashChain::Find(const string& str) {
	int index = Hash(str);
	list<string> l = _arr[index];

	bool found = false;
	for (const auto& word : l) {
		if (word.compare(str) == 0) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << "yes" << endl;		
	}
	else {
		cout << "no" << endl;
	}
}

void HashChain::Check(const int& i) const {
	if (i > 0) {
		list<string> l = _arr[i];
		if (l.size() > 0)
		{
			for (const auto& word : l) {
				cout << word << " ";
			}
			cout << endl;
			return;
		}
	}

	cout << " " << endl;
}

int HashChain::Hash(const string& str) {
	long long sum = 0;
	const int x = 263;
	const int p = 1000000007;
	for (size_t i = 0; i < str.length(); i++) {
		int ascii = (int)str[i];
		int powerX = std::pow(x, i);

		sum += (ascii * powerX);
	}

	return sum % p % _m;
}
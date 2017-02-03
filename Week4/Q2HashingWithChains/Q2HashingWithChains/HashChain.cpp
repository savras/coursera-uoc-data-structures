#include "HashChain.h"
#include <cmath>
#include <iostream>
#include <list>
#include <sstream>

using std::string;
using std::list;
using std::cout;
using std::endl;
using std::stringstream;

void HashChain::Add(const string& str) {
	int index = Hash(str);

	// Enforce idempotence
	for (auto it = _arr[index].begin(); it != _arr[index].end(); ++it) {
		if (*it == str) {
			return;
		}
	}

	_arr[index].push_back(str);
}

void HashChain::Del(const string& str) {
	int index = Hash(str);
	_arr[index].remove(str);
}

string HashChain::Find(const string& str) {
	int index = Hash(str);
	list<string> l = _arr[index];

	bool found = false;
	for (const auto& word : l) {
		if (word.compare(str) == 0) {
			found = true;
			break;
		}
	}

	return found ? "yes" : "no";
}

string HashChain::Check(const int& i) const {
	if (i > 0) {

		stringstream ss;
		int length = _arr[i].size();
		if (length > 0)
		{
			list<string> l = _arr[i];
			for (std::list<string>::reverse_iterator i = l.rbegin(); i != l.rend(); ++i)
			{
				ss << *i + " ";
			}
			return ss.str();
		}
	}

	return " ";
}

int HashChain::Hash(const string& str) {
	long long hash = 0;
	const int x = 263;
	const int p = 1000000007;
	for (int i = str.length() - 1; i >= 0 ; i--) {
		int ascii = (int)str[i];

		hash = (hash * x + ascii) % p;
	}

	return hash % _m;
}
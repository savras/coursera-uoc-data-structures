#include <iostream>
#include <sstream>
#include "HashChain.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main() {
	int m, n;
	cin >> m >> n;

	HashChain hc(m);
	
	string op, word;
	int index;

	stringstream ss;
	for (size_t i = 0; i < n; i++) {
		cin >> op;

		if (op.compare("add") == 0) {
			cin >> word;
			hc.Add(word);
		}
		else if (op.compare("del") == 0) {
			cin >> word;
			hc.Del(word);
		}
		else if (op.compare("find") == 0) {
			cin >> word;
			ss << hc.Find(word) << endl;
		}
		else if (op.compare("check") == 0) {
			cin >> index;
			ss << hc.Check(index) << endl;
		}
	}

	cout << ss.str();
	system("pause");

	return 0;
}
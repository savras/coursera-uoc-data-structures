#include <iostream>
#include "HashChain.h"

using std::cin;
using std::cout;
using std::string;

int main() {
	int m, n;
	cin >> m >> n;

	HashChain hc(m);
	
	string op, word;
	int index;

	for (size_t i; i < n; i++) {
		cin >> op;

		if (op.compare("add") == 0) {
			cin >> word;
			hc.Add(word);
		}
		else if (op.compare("del")) {
			cin >> word;
			hc.Del(word);
		}
		else if (op.compare("find")) {
			cin >> word;
			hc.Find(word);
		}
		else if (op.compare("check")) {
			cin >> index;
			hc.Check(index);
		}
	}

	system("pause");

	return 0;
}
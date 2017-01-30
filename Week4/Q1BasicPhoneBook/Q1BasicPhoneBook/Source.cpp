#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	int naiveLength = 9999999;
	vector<string> arr(naiveLength);

	int n;
	cin >> n;

	int number;
	string op, name;
	for (size_t i = 0; i < n; i++) {
		cin >> op;
		cin >> number;

		if (op.compare("add") == 0) {
			cin >> name;

			arr[number] = name;
		} else if (op.compare("find") == 0) {
			arr[number].empty() ?
				cout << "not found" << endl :
				cout << arr[number] << endl;
		} else if (op.compare("del") == 0) {
			if (!arr[number].empty()) {
				arr[number].clear();
			}
		}
	}

	system("pause");

	return 0;
}

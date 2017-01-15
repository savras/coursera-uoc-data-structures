#include <iostream>
#include <string>
#include <utility>
#include "Stack.h"

using std::cin;
using std::cout;
using std::string;
using std::pair;
using std::make_pair;

void validateBrackets(const string &text, Stack<pair<int, char>> stack) {
	const int offset = 1;
	char val;
	for (int i = 0; i < text.length(); i++) {
		val = text[i];
		if (val == '[' || val == '{' || val == '(') {
			stack.push(make_pair(i, text[i]));
		}
		else if (val == ']' || val == '}' || val == ')') {
			if (stack.size() == 0) {
				cout << i + offset;
				return;
			}

			if ((val == ']' && stack.top().second != '[') ||
				(val == '}' && stack.top().second != '{') ||
				(val == ')' && stack.top().second != '(')) {
				cout << i + offset;
				return;
			}

			stack.pop();
		}
	}

	if (stack.size() != 0) {
		cout << stack.top().first + offset;
		return;
	}

	cout << "Success";
}

int main() {
	Stack<pair<int, char>> stack;
	string text;
	cin >> text;

	validateBrackets(text, stack);
	return 0;
}
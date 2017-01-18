#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::endl;

bool hasSlot(const int sumP, const int i, const int S, const vector<pair<int, int>> &input) {
	if (i < S) {
		return true;
	}

	int currentA = input[i].first;

	int processingTimeOfPreviousBuffers = 0;
	bool equalTimes = false;

	for (int p = i - 1; p >= 0 && p >= i - S; p--) {
		processingTimeOfPreviousBuffers += input[p].second;
		equalTimes = equalTimes || input[p].first == currentA;
	}

	return processingTimeOfPreviousBuffers > currentA && !equalTimes;
}

int main() {
	int S, n;
	cin >> S >> n;

	int A, P;
	vector<pair<int, int>> input;
	input.push_back(pair<int, int> (0, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> A >> P;
		input.push_back(pair<int, int>(A, P));
	}

	int sumP = 0;
	for (int i = 1; i <= n; i++) {
		if (input[i].first < sumP) {
			if (!hasSlot(sumP, i, S, input)) {
				cout << -1;
			}
			else {
				cout << sumP;
			}
		}
		else {
			if (i != 0)
			{
				cout << input[i].first << endl;
			}
		}

		sumP += P;
	}

	return 0;
}
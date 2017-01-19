#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::endl;
using std::queue;
using std::max;

int main() {
	int S, n;
	cin >> S >> n;

	queue<int> queue;
	vector<pair<int, int>> inputs;
	int A, P;
	for (int i = 0; i < n; i++) {
		cin >> A >> P;
		inputs.push_back(pair<int, int>(A, P));
	}

	int runningSum = 0;
	for (int i = 0; i < n; i++) {
		A = inputs[i].first;
		P = inputs[i].second;

		if (!queue.empty()) {
			runningSum = queue.back();
		}
		while (!queue.empty() && queue.front() <= A) {
			queue.pop();
		}

		if (queue.empty()) {
			cout << A << endl;
			queue.push(A + P);
		}
		else if (queue.size() < S) {
			cout << max(A, queue.back()) << endl;
			queue.push(runningSum + P);
		}
		else {
			cout << -1 << endl;
		}
	}

	system("pause");
	return 0;
}
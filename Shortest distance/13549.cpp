#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

void dijikstra(int start, int dest, vector<int>& result) {

	priority_queue<pair<int, int>> heap;
	int two, one, neg;
	// -가중치, 인덱스

	result[start] = 0;
	heap.push({ 0, start });

	while (!heap.empty()) {

		int cur_cost = -heap.top().first;
		int cur_idx = heap.top().second;

		heap.pop();

		if (cur_cost > result[cur_idx]) {
			continue;
		}
		
		two = cur_idx * 2;
		if (cur_idx <= dest && result[two] > cur_cost) {
			result[two] = cur_cost;
			heap.push({ -cur_cost, two });
		}

		one = cur_idx + 1;
		if (cur_idx <= dest && result[one] > cur_cost + 1) {
			result[one] = cur_cost + 1;
			heap.push({ -(cur_cost + 1), one });
		}

		neg = cur_idx - 1;
		if (cur_idx > 0 && result[neg] > cur_cost + 1) {
			result[neg] = cur_cost + 1;
			heap.push({ -(cur_cost + 1), neg });
		}
	}
}

int main(int argc, char** argv) {

	vector<int> result;
	int n, k, max;
	cin >> n >> k;

	max = n > k ? n : k;
	result.resize(max * 3, numeric_limits<int>::max());

	dijikstra(n, k, result);

	cout << result[k] << '\n';

	return 0;
}
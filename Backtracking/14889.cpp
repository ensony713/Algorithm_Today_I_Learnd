#include <iostream>
#include <vector>
using namespace std;

int status[21][21] = { 0 }, n;
vector<int> start;
int result = INT32_MAX;
bool visited[21] = { 0 }, link[21] = { 0 };

void sum_status() {
	int s = 0, l = 0, sum;

	for (int i : start) {
		for (int j : start) {
			s += status[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!link[i] && !link[j]) {
				l += status[i][j];
			}
		}
	}

	sum = s - l < 0 ? (s - l) * (-1) : s - l;

	result = result > sum ? sum : result;
}

void dfs(int deep) {
	if (deep >= n / 2) {
		sum_status();
		return;
	}

	int f = start.size() != 0 ? start[start.size() - 1] : 0;

	for (int i = f; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			start.push_back(i);
			link[i] = true;

			dfs(deep + 1);

			visited[i] = false;
			start.pop_back();
			link[i] = false;
		}
	}
}

int main(int argc, char* argv[]) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> status[i][j];
		}
	}

	dfs(0);

	cout << result << '\n';
	return 0;
}
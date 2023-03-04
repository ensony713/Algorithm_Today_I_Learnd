#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

vector<int> coin;
int cache[MAX] = { 0 };

int dp(int n) {
	if (n < 0) {
		return -1;
	}

	if (n == 0) {
		return 0;
	}

	if (cache[n]) {
		return cache[n];
	}

	int result = 0, mini = MAX * MAX;
	for (auto& c : coin) {
		if (n - c >= 0) {
			result = dp(n - c) + 1;
		}

		if (result > 0) {
			mini = mini < result ? mini : result;
		}
	}

	cache[n] = mini != MAX * MAX ? mini : -1;
	return cache[n];
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, input;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> input;
		coin.push_back(input);
	}

	cout << dp(k);

	return 0;
}
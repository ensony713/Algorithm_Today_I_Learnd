#include <iostream>
#include <memory.h>
#include <algorithm>
#define MAX 505
using namespace std;

int cache[MAX][MAX] = { 0 };
int chapter[MAX] = { 0 };
int sum[MAX] = { 0 };

int dp(int start, int end) {

	if (start == end) { return 0; }
	if (end - start == 1) {
		return chapter[start] + chapter[end];
	}

	if (cache[start][end] != 0) {
		return cache[start][end];
	}

	int result = MAX * MAX * MAX;
	for (int i = start; i < end; i++) {
		result = min(result, dp(start, i) + dp(i + 1, end) + sum[end] - sum[start - 1]);
	}

	cache[start][end] = result;
	return cache[start][end];
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int t, k;

	cin >> t;

	while (t > 0) {

		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> chapter[i];
			sum[i] = sum[i - 1] + chapter[i];
		}

		cout << dp(1, k) << '\n';

		memset(cache, 0, sizeof(cache));

		t--;
	}
}
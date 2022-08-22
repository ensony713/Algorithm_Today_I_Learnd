#include <iostream>
using namespace std;

int dp[1000000] = { 0 };

int calculate(int n) {
	if (n < 1) {
		return 2000000;
	}

	if (n == 1) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	int tree = INT32_MAX, two = INT32_MAX, one;
	if (n % 3 == 0) {
		tree = calculate(n / 3) + 1;
	}

	if (n % 2 == 0) {
		two = calculate(n / 2) + 1;
	}

	one = calculate(n - 1) + 1;

	dp[n] = one < two ? one : two;
	dp[n] = dp[n] < tree ? dp[n] : tree;

	return dp[n];
}

int main(int argc, char** argv) {
	int n;
	cin >> n;

	//cout << calculate(n);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0) {
			dp[i] = dp[i] < dp[i / 3] + 1 ? dp[i] : dp[i / 3] + 1;
		}

		if (i % 2 == 0) {
			dp[i] = dp[i] < dp[i / 2] + 1 ? dp[i] : dp[i / 2] + 1;
		}
	}

	cout << dp[n];
	return 0;
}
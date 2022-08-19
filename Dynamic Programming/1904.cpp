#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int n, * dp = new int[1000002];
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n];

	delete[] dp;
	return 0;
}
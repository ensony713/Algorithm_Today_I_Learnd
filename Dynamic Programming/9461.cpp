#include <iostream>
using namespace std;

typedef unsigned long number;

number dp[101] = { 0 };

number fibo(int n) {
	if (n < 0) { n = 0;}

	if (dp[n] != 0) {
		return dp[n];
	}

	dp[n] = fibo(n - 1) + fibo(n - 5);
	return dp[n];
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;

	cin >> t;
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fibo(n) << '\n';
	}
	return 0;
}
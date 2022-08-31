#include <iostream>
using namespace std;

int n, k;
int weight[105] = { 0 }, value[105] = { 0 }, dp[105][100005] = { 0 };

int main(int argc, char** argv) {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];

		for (int j = weight[i]; j <= k; j++) {
			if (j - weight[i] >= 0) {
				dp[i][j] = dp[i - 1][j - weight[i]] + value[i];
			}
			dp[i][j] = dp[i][j] < dp[i - 1][j] ? dp[i - 1][j] : dp[i][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << dp[n][k];
	return 0;
}
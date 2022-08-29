#include <iostream>
#define MAX 505
using namespace std;

int main(int argc, char** argv) {
	int line[MAX] = { 0 }, n, result = 0, a, b, last = 0, dp[MAX] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		line[a] = b;
		dp[i] = 1;

		last = last < a ? a : last;
		last = last < b ? b : last;
	}

	for (int i = 1; i <= last; i++) {
		
		if (line[i] == 0) { 
			dp[i] = 0;
			continue; 
		}

		for (int j = 1; j < i; j++) {
			if (line[j] < line[i]) {
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}

		result = result > dp[i] ? result : dp[i];
	}

	cout << n - result;
	return 0;
}
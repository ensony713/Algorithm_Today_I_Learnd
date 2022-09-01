#include <iostream>
using namespace std;

int sum[100005] = { 0 };

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, max = -20000000;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	for (int i = 0; i <= n - k; i++) {
		max = max > sum[i + k] - sum[i] ? max : sum[i + k] - sum[i];
	}

	cout << max;
	return 0;
}
#include <iostream>
#define MOD 1000000000
#define MAX 203
using namespace std;

typedef long long number;
number cache[MAX][MAX] = {0};

number dp(int r, int l, int n, int k) {

	if (l == k && r == n) {
		return 1;
	}
	else if (l == k) {
		return 0;
	}

	if (cache[n - r][k - l] != 0) {
		return cache[n - r][k - l];
	}

	for (int i = 0; i <= n - r; i++) {
		cache[n - r][k - l] = (cache[n - r][k - l] + dp(r + i, l + 1, n, k)) % MOD;
	}
	
	return cache[n - r][k - l];
}

int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;

	cout << dp(0, 0, n, k);
	return 0;
}